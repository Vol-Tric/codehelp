// number of dice rolls with target sum
#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

class Solution {
    int solveRecursive(int dice , int faces , int target){
        // base cases
        if(target < 0){
            return 0;
        }
        if(target == 0 && dice != 0){
            return 0;
        }
        if(dice == 0 && target != 0){
            return 0;
        }
        if(dice == 0 && target == 0){
            return 1;
        }

        int ans = 0;
        for(int i=1 ; i<=faces ; i++){
            ans += solveRecursive(dice-1 , faces , target-i) % MOD;
        }
        return ans % MOD;
    }

    int solveMemo(int dice , int faces , int target , vector<vector<int>>&dp){
        // base cases
        if(target < 0){
            return 0;
        }
        if(target == 0 && dice != 0){
            return 0;
        }
        if(dice == 0 && target != 0){
            return 0;
        }
        if(dice == 0 && target == 0){
            return 1;
        }

        if(dp[dice][target] != -1){
            return dp[dice][target];
        }

        int ans = 0;
        for(int i=1 ; i<=faces ; i++){
            ans += solveMemo(dice-1 , faces , target-i , dp) % MOD;
        }
        dp[dice][target] = ans % MOD;
        return dp[dice][target] % MOD;
    }

    int solveTabulation(int dice , int faces , int target){
        vector<vector<int>>dp(dice+1 , vector<int>(target+1 , 0));

        dp[0][0] = 1;


        for(int i = 1 ; i <= dice ; i++){
            for(int j = 1 ; j <= target ; j++){
                int ans = 0;
                for(int k = 1 ; k<=faces ; k++){
                    if(j-k >= 0)
                        ans += dp[i-1][j-k];
                }
                dp[i][j] = ans;
            }
        }
        return dp[dice][target];
    }

    int solveOptimized(int dice , int faces , int target){
        vector<int>prev(target+1 , 0); // dp[0]
        vector<int>curr(target+1 , 0);

        prev[0] = 1;

        for(int i = 1 ; i <= dice ; i++){
            for(int j = 1 ; j <= target ; j++){
                int ans = 0;
                for(int k = 1 ; k<=faces ; k++){
                    if(j-k >= 0)
                        ans += prev[j-k];
                }
                curr[j] = ans;
            }
            prev = curr;
        }

        return prev[target];
    }
public:
    // // using recursion
    // int numRollsToTarget(int n, int k, int target) {
    //     return solveRecursive(n , k , target);
    // }

    // // using memoization
    // int numRollsToTarget(int n, int k, int target){
    //     vector<vector<int>>dp(n+1 , vector<int>(target+1 , -1));
    //     return solveMemo(n , k , target , dp);
    // }

    // // using tabulation
    // int numRollsToTarget(int n, int k, int target) {
    //     return solveTabulation(n , k , target);
    // }
    
    // using space optimized approach
    int numRollsToTarget(int n, int k, int target) {
        return solveOptimized(n , k , target);
    }
    
};

int main(){
    int n = 2;
    int k = 6;
    int target = 7;

    Solution obj;
    int ans = obj.numRollsToTarget(n , k , target);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}