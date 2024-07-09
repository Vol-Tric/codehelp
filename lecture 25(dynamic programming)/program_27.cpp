// unique BST (structurally)
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solveRecursive(int n){
        if(n == 0 || n == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }
        
        int ans = 0;
        for(int i=1 ; i<=n ; i++){
            int temp = (solveRecursive(i-1) * solveRecursive(n-i));
            ans += temp;
        }
        return ans;
    }

    int solveMemo(int n , vector<int>&dp){
        if(n == 0 || n == 1){
            return 1;
        }

        if(n == 2){
            return 2;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        int ans = 0;
        for(int i=1 ; i<=n ; i++){
            ans += (solveMemo(i-1 , dp) * solveMemo(n-i , dp));
        }
        dp[n] = ans;
        return dp[n];
    }

    int solveTabulation(int n){
        vector<int>dp(n+1 , 0);
        dp[0] = dp[1] = 1;

        for(int i = 2 ; i<=n ; i++){
            int ans = 0;
            for(int j = 1 ; j<=i ; j++){
                ans += dp[j - 1] * dp[i - j];
            }
            dp[i] = ans;
        }
        return dp[n];
    }

    // long long int factorial(int n){
    //     if(n == 0 || n == 1){
    //         return 1;
    //     }
    //     return n * factorial(n-1);
    // }
    
    // // catalan original way
    // int solveOptimized(int n){
    //     // using the concept of catalan numbers
    //     // formula for catalan numbers is 
    //     // f(n) = (2n)! / ((n+1)! * n!)

    //     long long int num = factorial(2*n);
    //     long long int denum = factorial(n+1) * factorial(n);

    //     int ans = num / denum;
    //     return ans;
    // }
    

    // catalan using DP
    int solveOptimized(int n){
        // using the concept of catalan numbers
        // formula for catalan numbers is 
        // f(n) = (2n)! / ((n+1)! * n!)
        // but as the formula uses factorial  , there is a better way to do it
        // catalan(n) = catalan(i) * catalan(n-i-1); where i => [0 , n).

        vector<int>dp(n+1 , 0);
        dp[0] = dp[1] = 1;

        for(int i=2 ; i<=n ; i++){
            int ans = 0;
            for(int j = 0 ; j < i ; j++){
                ans += dp[j] * dp[i - j -1];
            }
            dp[i] = ans;
        }
        return dp[n];
    }
public:
    // // using recursion
    // int numTrees(int n) {
    //     return solveRecursive(n);
    // }

    // // using memoization
    // int numTrees(int n){
    //     vector<int>dp(n+1 , -1);
    //     return solveMemo(n , dp);
    // }

    // // using Tabulation
    // int numTrees(int n){
    //     return solveTabulation(n);
    // }

    // using optimized approach , using catalan numbers
    int numTrees(int n){
        return solveOptimized(n);
    }
};

int main(){
    int n = 4;
    Solution obj;
    int ans = obj.numTrees(n);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}