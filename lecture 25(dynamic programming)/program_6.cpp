// cut rod into segments X, Y, Z
#include<bits/stdc++.h>
using namespace std;

class Solution{
    int solveRecursive(int n , int x , int y , int z){
        // base case
        if(n==0){
            return 0;
        }

        if(n < 0){
            return INT_MIN;
        }

        int a = solveRecursive(n-x , x , y , z) + 1;
        int b = solveRecursive(n-y , x , y , z) + 1;
        int c = solveRecursive(n-z , x , y , z) + 1;

        int ans = max(a , max(b , c));
        return ans;
    }

    int solveMemo(int n , int x , int y , int z , vector<int>&dp){
        // base case
        if(n==0){
            return 0;
        }

        if(n < 0){
            return INT_MIN;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        int a = solveMemo(n-x , x , y , z , dp) + 1;
        int b = solveMemo(n-y , x , y , z , dp) + 1;
        int c = solveMemo(n-z , x , y , z , dp) + 1;

        dp[n] = max(a , max(b , c));
        return dp[n];
    }

    int solveTabulation(int n , int x , int y , int z){
        vector<int>dp(n+1 , INT_MIN);
        if(n==0){
            return 0;
        }

        if(n < 0){
            return INT_MIN;
        }

        dp[0] = 0;

        for(int i=1 ; i<=n ; i++){
            if(i-x >= 0){
                dp[i] = max(dp[i] , dp[i-x] + 1);
            }
            if(i-y >= 0){
                dp[i] = max(dp[i] , dp[i-y] + 1);
            }
            if(i-z >= 0){
                dp[i] = max(dp[i] , dp[i-z] + 1);
            }
        }
        return dp[n];
    }
    public:
    // // using recursion
    // int cutSegments(int n , int x , int y , int z){
    //     int ans = solveRecursive(n , x , y , z);
    //     return (ans < 0) ?  0 :  ans;
    // }

    // // using memoization
    // int cutSegments(int n , int x , int y , int z){
    //     vector<int>dp(n+1 , -1);
    //     dp[0] = 0;
    //     int ans = solveMemo(n , x , y , z , dp);
    //     return (ans < 0) ?  0 :  ans;
    // }

    // using tabulation
    int cutSegments(int n , int x , int y , int z){
        int ans = solveTabulation(n , x , y , z);
        return (ans < 0) ?  0 :  ans;
    }

};

int main(){
    int n = 7;
    int x = 5;
    int y = 2;
    int z = 2;

    Solution obj;
    int ans = obj.cutSegments(n , x , y , z);
    cout<<ans<<endl;

    return 0;
}