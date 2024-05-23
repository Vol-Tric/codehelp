// painting fence
// recurrance relation is : 
// f(n) = (k-1) * (f(n-2) + f(n-1))

#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

class Solution{
    int add(int a , int b){
        return (a%MOD + b%MOD)%MOD;
    }

    int mul(int a , int b){
        return ((a%MOD) * (b%MOD))%MOD;
    }

    int solveRecursive(int n , int k){
        // base case
        if(n == 1){
            return k;
        }
        if(n == 2){
            return (add(k , mul(k , k-1)));
        }

        int ans = mul(k-1 , add(solveRecursive(n-2 , k) , solveRecursive(n-1 , k)));
        return ans;
    }

    int solveMemo(int n , int k , vector<int>&dp){
        // base case
        if(n == 1){
            return k;
        }
        if(n == 2){
            return (add(k , mul(k , k-1)));
        }

        if(dp[n] != -1){
            return dp[n];
        }

        dp[n] = mul(k-1 , add(solveMemo(n-2 , k , dp) , solveMemo(n-1 , k , dp)));
        return dp[n];

    }

    int solveTabulation(int n , int k){
        vector<int>dp(n+1 , -1);

        // base case
        dp[1] = k;
        dp[2] = add(k , mul(k , k-1));

        for(int i=3 ; i<=n ; i++){
            dp[i] = mul(k-1 , add(dp[i-1] , dp[i-2]));
        }

        return dp[n];
    }

    int solveOptimized(int n , int k){
        // base case
        if(n == 1){
            return k;
        }
        if(n == 2){
            return (add(k , mul(k , k-1)));
        }

        int first = k;
        int second = add(k , mul(k , k-1));
        int sum = 0;

        for(int i=2 ; i<n ; i++){
            sum = mul(k-1 , add(first , second));
            first = second;
            second = sum;
        }
        return sum;
    }
    public:

    // // using recursion
    // int numberOfWays(int n , int k){
    //     return solveRecursive(n , k);
    // }

    // // using Memoization
    // int numberOfWays(int n , int k){
    //     vector<int>dp(n+1 , -1);
    //     return solveMemo(n , k , dp);
    // }

    // // using Tabulation
    // int numberOfWays(int n , int k){
    //     return solveTabulation(n , k);
    // }

    // using space optimized approach
    int numberOfWays(int n , int k){
        return solveOptimized(n , k);
    }
};

int main(){
    int n = 2;
    int k = 4;

    Solution obj;

    int ans = obj.numberOfWays(n , k);
    cout<<"answer is : "<<ans<<endl;

    return 0;
}