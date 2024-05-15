// minimum number of coins
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solveRec(vector<int>num , int amt){
        // base case
        if(amt == 0){
            return 0;
        }
        if(amt < 0){
            return INT_MAX;
        }

        int mini = INT_MAX;
        for(int i=0 ; i<num.size();i++){
            int ans = solveRec(num , amt-num[i]);
            if(ans != INT_MAX){
                mini = min(mini , 1+ans);
            }
        }
        return mini;
    }

    int solveMemo(vector<int>num , int amt , vector<int>&dp){
        // base case
        if(amt == 0){
            return 0;
        }
        if(amt < 0){
            return INT_MAX;
        }

        if(dp[amt] != -1){
            return dp[amt];
        }

        int mini = INT_MAX;
        for(int i=0 ; i<num.size();i++){
            int ans = solveMemo(num , amt-num[i] , dp);
            if(ans != INT_MAX){
                mini = min(mini , 1+ans);
            }
        }
        dp[amt] = mini;
        return mini;
    }


    int solveTabulation(vector<int>num , int amt){
        vector<int>dp(amt+1 , INT_MAX);
        dp[0] = 0;

        for(int i= 0 ;i<=amt;i++){
            for(int j = 0 ; j<num.size() ; j++){
                if(i - num[j] >= 0 && dp[i-num[j]] != INT_MAX){
                    dp[i] = min(dp[i] , 1 + dp[i-num[j]]);
                }
            }
        }
        return dp[amt];

    }

    
public:
    // // recursive
    // int coinChange(vector<int>& coins, int amount) {
    //     int ans = solveRec(coins , amount);
    //     if(ans == INT_MAX){
    //         return -1;
    //     }
    //     return ans;
    // }

    // // memoization
    // int coinChange(vector<int>& coins, int amount) {
    //     vector<int>dp(amount+1 , -1);
    //     int ans = solveMemo(coins , amount , dp);
    //     if(ans == INT_MAX){
    //         return -1;
    //     }
    //     return ans;
    // }

    // tabulation
    int coinChange(vector<int>& coins, int amount) {
        
        int ans = solveTabulation(coins , amount);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};

int main(){
    vector<int>coins = {1,2,5};
    int amount = 11;

    Solution obj;
    int ans = obj.coinChange(coins , amount);
    cout<<ans<<endl;

    return 0;
}