// guess the number higher or lower
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solveRecursive(int start , int end){
        // base case
        if(start >= end){
            return 0;
        }

        int ans = INT_MAX;
        for(int i = start ; i <= end ; i++){ 
            ans = min(ans , i + max(solveRecursive(start , i-1) , solveRecursive(i+1 , end)));
        }
        return ans;    
    }

    int solveMemo(int start , int end , vector<vector<int>>&dp){
        if(start >= end){
            return 0;
        }

        if(dp[start][end] != -1){
            return dp[start][end];
        }

        int ans = INT_MAX;
        for(int i=start ; i<=end ; i++){
            ans = min(ans , i + max(solveMemo(start , i-1 , dp) , solveMemo(i+1 , end , dp)));
        }

        dp[start][end] = ans;
        return dp[start][end];
    }

    int solveTabulation(int n){
        vector<vector<int>>dp(n+2 , vector<int>(n+2 , 0));

        for(int start = n ; start >= 1 ; start--){
            for(int end = start ; end <= n ; end++){
                if(start == end){
                    continue;
                }
                else{
                    int ans = INT_MAX;
                    for(int i = start ; i <= end ; i++){
                        ans = min(ans , i + max(dp[start][i-1] , dp[i+1][end]));
                    }
                    dp[start][end] = ans;
                }                
            }
        }

        return dp[1][n];
    }

public:
    // // using recursion
    // int getMoneyAmount(int n) {
    //     return solveRecursive(1 , n);
    // }

    // // using memoization
    // int getMoneyAmount(int n) {
    //     vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1));
    //     return solveMemo(1 , n , dp);
    // }

    // using Tabulation
    int getMoneyAmount(int n) {
        return solveTabulation(n);
    }
};

int main(){
    int n = 10;
    Solution obj;
    int ans = obj.getMoneyAmount(n);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}