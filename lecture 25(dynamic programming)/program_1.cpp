// fibonacci
#include<bits/stdc++.h>
using namespace std;

// basic recursion
int fibRecursion(int num){
    if(num == 0 || num == 1){
        return num;

    }
    
    return fibRecursion(num-1) + fibRecursion(num-2);
}

// tabulation
int fibDP_bottomUp(int num){
    vector<int>dp(num+2);

    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2 ; i<=num ; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[num];
}

// recursion + memoization
int fibDP_TopDown(int num , vector<int>&dp){
    if(num == 0 || num == 1){
        return num;

    }

    if(dp[num] != -1){
        return dp[num];
    }
    
    dp[num] =  fibDP_TopDown(num-1 , dp) + fibDP_TopDown(num-2 , dp);
    return dp[num];
}

// space optimized
int fibOptimized(int num){
    if(num <= 1){
        return num;
    }

    int t1 = 0;
    int t2 = 1;
    int sum = 0;

    for(int i = 2 ; i<=num ; i++){
        sum = t1+t2;
        t1 = t2;
        t2 = sum;
    }

    return sum;
}

int main(){
    int num = 8;
    cout<<"Recursion :  "<<fibRecursion(num)<<endl;

    
    cout<<"DP Bottom UP: "<<fibDP_bottomUp(num)<<endl;

    vector<int>dp(num+1 , -1);
    cout<<"DP Top Down : "<<fibDP_TopDown(num , dp)<<endl;

    cout<<"fib optimized : "<<fibOptimized(num)<<endl;
    
    return 0;
}