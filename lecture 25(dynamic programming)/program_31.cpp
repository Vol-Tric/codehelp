// buy and sell stock ( part 2)
// leetcode 122
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solveRecursive(vector<int>&prices , bool buy , int index){
        if(index == prices.size()){
            return 0;
        }
        int profit = 0;
        int bought , skip , sold = 0;
        if(buy){
            bought = -prices[index] + solveRecursive(prices , !buy , index+1);
            skip = 0 + solveRecursive(prices , buy , index+1); 

            profit = max(bought , skip);
            return profit;
        }
        else{
            sold = +prices[index] + solveRecursive(prices , !buy , index+1);
            skip = 0 + solveRecursive(prices , buy , index+1); 

            profit = max(sold , skip);
            return profit;
        } 
    }

    int solveMemo(vector<int>&prices , bool buy , int index , vector<vector<int>>&dp){
        if(index == prices.size()){
            return 0;
        }

        if(dp[index][buy] != -1){
            return dp[index][buy];
        }

        int profit = 0;
        int bought , sold , skip = 0;

        if(buy == 1){
            bought = -prices[index] + solveMemo(prices , !buy , index+1 , dp);
            skip = 0 + solveMemo(prices , buy , index+1 , dp);

            dp[index][buy] = max(bought , skip);
            return dp[index][buy];
        }
        else{
            sold = +prices[index] + solveMemo(prices , !buy , index+1 , dp);
            skip = 0 + solveMemo(prices , buy , index+1 , dp);

            dp[index][buy] = max(sold , skip);
            return dp[index][buy];
        }

    }

    int solveTabulation(vector<int>&prices){
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
                    sold = +prices[index] + dp[index+1][1];
                    skip = 0 + dp[index+1][0];

                    dp[index][buy] = max(sold , skip);
                }
            }
        }
        return dp[0][1];
    }

    int solveSpaceOptimized(vector<int>&prices){
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
                    sold = +prices[index] + curr[1];
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
    // int maxProfit(vector<int>& prices){
    //     return solveRecursive(prices , 1 , 0);
    // }

    // // using Memoization
    // int maxProfit(vector<int>& prices){
    //     int n = prices.size();
    //     vector<vector<int>>dp(n+1 , vector<int>(2 , -1));
    //     return solveMemo(prices , 1 , 0 , dp);
    // }

    // // using tabulation
    // int maxProfit(vector<int>& prices){
        
    //     return solveTabulation(prices);
    // }

    // using space optimized approach
    int maxProfit(vector<int>& prices){
        
        return solveSpaceOptimized(prices);
    }
};




int main(){
    vector<int>prices = {7,1,5,3,6,4};
    Solution obj;
    int ans = obj.maxProfit(prices);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}