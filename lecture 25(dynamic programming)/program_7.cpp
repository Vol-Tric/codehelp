// count dearangements
// recurrance relation is : 
// f(n) = (n-1) * (f(n-2) + f(n-1))
#include<bits/stdc++.h>

#define MOD 1000000007;
using namespace std;

class Solution{
    long long int solveRecursive(int num){
        if(num == 1){
            return 0;
        }
        if(num == 2){
            return 1;
        }

        long long int ans = (((num - 1) ) * ((solveRecursive(num-1) ) + (solveRecursive(num-2) ))) ;
        return ans;
    }

    long long int solveMemo(int num , vector<long long int>&dp){
        dp[1] = 0;
        dp[2] = 1;

        if(dp[num] != -1){
            return dp[num];
        }

        dp[num] = (((num - 1) )*((solveMemo(num-1 , dp) ) + (solveMemo(num-2 , dp) ))) ;

        return dp[num];
    }

    long long int solveTabulation(int num){
        vector<long long int>dp(num+1 , 0);
        dp[1] = 0;
        dp[2] = 1;

        for(long long int i=3 ; i<=num ; i++){
            dp[i] = (((i-1) )*((dp[i-1]) + (dp[i-2]) )) ;
        }
        return dp[num];
    }

    long long int solveOptimized(int num){
        if(num == 1){
            return 0;
        }
        if(num == 2){
            return 1;
        }

        long long int first = 0;
        long long int second = 1;
        long long int sum = 0;
        for(int i=3 ; i<=num ; i++){
            sum = ((i-1)*((first ) + second )) ;
            first = second;
            second = sum;
        }
        return second;
    }
    public:
    // // using recursion
    // long long int countDerangements(int num){
    //     return solveRecursive(num);
    // }

    // // using Memoization
    // long long int countDerangements(int num){
    //     vector<long long int>dp(num+1 , -1);
    //     return solveMemo(num , dp);
    // }

    // // using Tabulation
    // long long int countDerangements(int num){
    //     return solveTabulation(num);
    // }

    // using optimized approach
    long long int countDerangements(int num){
        return solveOptimized(num);
    }
};

int main(){
    int num = 20;
    Solution obj;
    long long int ans = obj.countDerangements(num);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}