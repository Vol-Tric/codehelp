// buy and sell stock ( part 5)
// leetcode 714
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solveRecursive(vector<int>&prices , bool buy , int index , int fee){
        if(index == prices.size()){
            return 0;
        }
        int profit = 0;
        int bought , skip , sold = 0;
        if(buy){
            bought = -prices[index] + solveRecursive(prices , !buy , index+1 , fee);
            skip = 0 + solveRecursive(prices , buy , index+1 , fee); 

            profit = max(bought , skip);
            return profit;
        }
        else{
            sold = +prices[index] - fee + solveRecursive(prices , !buy , index+1 , fee);
            skip = 0 + solveRecursive(prices , buy , index+1 , fee); 

            profit = max(sold , skip);
            return profit;
        } 
    }

    int solveMemo(vector<int>&prices , bool buy , int index , int fee ,vector<vector<int>>&dp){
        if(index == prices.size()){
            return 0;
        }

        if(dp[index][buy] != -1){
            return dp[index][buy];
        }

        int profit = 0;
        int bought , sold , skip = 0;

        if(buy == 1){
            bought = -prices[index] + solveMemo(prices , !buy , index+1 , fee , dp);
            skip = 0 + solveMemo(prices , buy , index+1 , fee , dp);

            dp[index][buy] = max(bought , skip);
            return dp[index][buy];
        }
        else{
            sold = +prices[index] - fee + solveMemo(prices , !buy , index+1 , fee , dp);
            skip = 0 + solveMemo(prices , buy , index+1 , fee , dp);

            dp[index][buy] = max(sold , skip);
            return dp[index][buy];
        }

    }

    int solveTabulation(vector<int>&prices , int fee){
        int n = prices.size();
        vector<vector<int>>dp(n+1 , vector<int>(2 , 0));

        for(int index = n-1 ; index >= 0 ; index--){
            for(int buy = 0 ; buy < 2 ; buy++){
                int profit = 0;
                int bought , sold , skip = 0;

                if(buy == 1){
                    bought = -prices[index] + dp[index+1][0];
                    skip = 0 + dp[index+1][1];

                    dp[index][buy] = max(bought , skip);    
                }
                else{
                    sold = +prices[index] - fee + dp[index+1][1];
                    skip = 0 + dp[index+1][0];

                    dp[index][buy] = max(sold , skip);
                }
            }
        }
        return dp[0][1];
    }

    int solveSpaceOptimized(vector<int>&prices , int fee){
        int n = prices.size();
        vector<int>prev(2 , 0);//index
        vector<int>curr(2 , 0);//index+1

        for(int index = n-1 ; index >= 0 ; index--){
            for(int buy = 0 ; buy < 2 ; buy++){
                int profit = 0;
                int bought , sold , skip = 0;

                if(buy == 1){
                    bought = -prices[index] + curr[0];
                    skip = 0 + curr[1];

                    prev[buy] = max(bought , skip);    
                }
                else{
                    sold = +prices[index] - fee + curr[1];
                    skip = 0 + curr[0];

                    prev[buy] = max(sold , skip);
                }
            }
            curr = prev;
        }
        return prev[1];
    }
public:

    // // using recursion
    // int maxProfit(vector<int>& prices , int fee){
    //     return solveRecursive(prices , 1 , 0 , fee);
    // }

    // // using Memoization
    // int maxProfit(vector<int>& prices , int fee){
    //     int n = prices.size();
    //     vector<vector<int>>dp(n+1 , vector<int>(2 , -1));
    //     return solveMemo(prices , 1 , 0 , fee , dp);
    // }

    // // using tabulation
    // int maxProfit(vector<int>& prices , int fee){
        
    //     return solveTabulation(prices , fee);
    // }

    // using space optimized approach
    int maxProfit(vector<int>& prices , int fee){
        
        return solveSpaceOptimized(prices , fee);
    }
};




int main(){
    vector<int>prices = {1,3,2,8,4,9};
    int fee = 2;
    Solution obj;
    int ans = obj.maxProfit(prices , fee);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}