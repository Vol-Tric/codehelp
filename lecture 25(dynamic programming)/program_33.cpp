// buy and sell stock ( part 4)
// leetcode 188
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solveRecursive(vector<int>&prices , bool buy , int index , int count , int k){
        if(index == prices.size() || count >= k){
            return 0;
        }
        int profit = 0;
        int bought , skip , sold = 0;
        if(buy){
            bought = -prices[index] + solveRecursive(prices , !buy , index+1 , count , k);
            skip = 0 + solveRecursive(prices , buy , index+1 , count , k); 

            profit = max(bought , skip);
            return profit;
        }
        else{
            sold = +prices[index] + solveRecursive(prices , !buy , index+1 , count+1 , k);
            skip = 0 + solveRecursive(prices , buy , index+1 , count , k); 

            profit = max(sold , skip);
            return profit;
        } 
    }

    int solveMemo(vector<int>&prices , bool buy , int index , int count , int k , vector<vector<vector<int>>>&dp){
        if(index == prices.size() || count >= k){
            return 0;
        }

        if(dp[index][buy][count] != -1){
            return dp[index][buy][count];
        }

        int profit = 0;
        int bought , sold , skip = 0;

        if(buy == 1){
            bought = -prices[index] + solveMemo(prices , !buy , index+1 , count , k , dp);
            skip = 0 + solveMemo(prices , buy , index+1 , count , k , dp);

            dp[index][buy][count] = max(bought , skip);
            return dp[index][buy][count];
        }
        else{
            sold = +prices[index] + solveMemo(prices , !buy , index+1 , count+1 , k , dp);
            skip = 0 + solveMemo(prices , buy , index+1 , count , k, dp);

            dp[index][buy][count] = max(sold , skip);
            return dp[index][buy][count];
        }
    }

    int solveTabulation(vector<int>&prices , int k){
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1 , vector<vector<int>>(2 , vector<int>(k+1 , 0)));

        for(int index = n-1 ; index >=0 ; index--){
            for(int buy = 0 ; buy < 2 ; buy++){
                for(int count = k-1 ; count >= 0 ; count--){
                    int profit = 0;
                    int bought , sold , skip = 0;

                    if(buy == 1){
                        bought = -prices[index] + dp[index+1][0][count];
                        skip = 0 + dp[index+1][1][count];

                        dp[index][buy][count] = max(bought , skip);
                        
                    }
                    else{
                        sold = +prices[index] + dp[index+1][1][count+1];
                        skip = 0 + dp[index+1][0][count];

                        dp[index][buy][count] = max(sold , skip);
                        
                    }
                }
            }
        }
        return dp[0][1][0];
    }

    int solveSpaceOptimized(vector<int>&prices , int k){
        int n = prices.size();

        vector<vector<int>>prev(2 , vector<int>(k+1 , 0));//index
        vector<vector<int>>curr(2 , vector<int>(k+1 , 0));//index+1
        for(int index = n-1 ; index >=0 ; index--){
            for(int buy = 0 ; buy < 2 ; buy++){
                for(int count = k-1 ; count >= 0 ; count--){
                    int profit = 0;
                    int bought , sold , skip = 0;

                    if(buy == 1){
                        bought = -prices[index] + curr[0][count];
                        skip = 0 + curr[1][count];

                        prev[buy][count] = max(bought , skip);
                        
                    }
                    else{
                        sold = +prices[index] + curr[1][count+1];
                        skip = 0 + curr[0][count];

                        prev[buy][count] = max(sold , skip);
                        
                    }
                }
            }
            curr = prev;
        }
        return prev[1][0];
    }
public:
    // // using recursion
    // int maxProfit(vector<int>& prices , int k) {
    //     return solveRecursive(prices , 1 , 0 , 0 ,k);
    // }

    // // using memoization
    // int maxProfit(vector<int>& prices , int k) {
    //     int n = prices.size();
    //     vector<vector<vector<int>>>dp(n+1 , vector<vector<int>>(2 , vector<int>(k+1 , -1)));
    //     return solveMemo(prices , 1 , 0 , 0 , k , dp);
    // }

    // // using Tabulation
    // int maxProfit(vector<int>& prices , int k) {
    //     return solveTabulation(prices , k);
    // }

    // using Space optimized approach
    int maxProfit(vector<int>& prices , int k) {
        return solveSpaceOptimized(prices , k);
    }
};


int main(){
    vector<int>prices = {3,2,6,5,0,3};
    int k = 2;
    Solution obj;
    int ans = obj.maxProfit(prices , k);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}