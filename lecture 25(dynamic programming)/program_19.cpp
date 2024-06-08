// pizza with 3n slices
// leetcode 1388

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solveRecursive(int index , int endIndex , vector<int>&slices , int n){
        // base case
        if(n == 0 || index > endIndex){
            return 0;
        }

        int take = slices[index] + solveRecursive(index+2 , endIndex , slices , n-1);
        int notTake = 0 + solveRecursive(index+1 , endIndex , slices , n);

        return max(take , notTake);
    }

    int solveMemoization(int index ,int endIndex , vector<int>&slices , int n , vector<vector<int>>&dp){
        // base case
        if(n == 0 || index > endIndex){
            return 0;
        }

        if(dp[n][index] != -1){
            return dp[n][index];
        }

        int take = slices[index] + solveMemoization(index+2 , endIndex , slices , n-1 , dp);
        int notTake = 0 + solveMemoization(index+1 , endIndex , slices , n , dp);

        dp[n][index] = max(take , notTake);
        return dp[n][index];
    }

    int solveTabulation(vector<int>&slices){
        int k = slices.size();
        vector<vector<int>>dp1(k+2 , vector<int>(k+2 , 0));
        vector<vector<int>>dp2(k+2 , vector<int>(k+2 , 0));

        for(int index = k-2 ; index >= 0 ; index--){
            for(int n = 1 ; n <= k/3 ; n++){
                int take = slices[index] + dp1[index+2][n-1];
                int notTake = 0 + dp1[index+1][n];

                dp1[index][n] = max(take , notTake);
            }
        }

        for(int index = k-1 ; index >= 1 ; index--){
            for(int n = 1 ; n <= k/3 ; n++){
                int take = slices[index] + dp2[index+2][n-1];
                int notTake = 0 + dp2[index+1][n];

                dp2[index][n] = max(take , notTake);
            }
        }

        return max(dp1[0][k/3] , dp2[1][k/3]);
    }

    int solveOptimized(vector<int>&slices){
        int k = slices.size();

        vector<int>prev1(k+2 , 0); //dp[index]
        vector<int>curr1(k+2 , 0); //dp[index +1]
        vector<int>next1(k+2 , 0); //dp[index +2]

        vector<int>prev2(k+2 , 0);
        vector<int>curr2(k+2 , 0);
        vector<int>next2(k+2 , 0);


        for(int index = k-2 ; index >= 0 ; index--){
            for(int n = 1 ; n <= k/3 ; n++){
                int take = slices[index] + next1[n-1];
                int notTake = 0 + curr1[n];

                prev1[n] = max(take , notTake);
            }
            // vector<int> temp = curr1;
            next1 = curr1;
            curr1 = prev1;
        }

        for(int index = k-1 ; index >= 1 ; index--){
            for(int n = 1 ; n <= k/3 ; n++){
                int take = slices[index] + next2[n-1];
                int notTake = 0 + curr2[n];

                prev2[n] = max(take , notTake);
            }
            // vector<int> temp = curr2;
            next2 = curr2;
            curr2 = prev2;
        }

        return max(prev1[k/3] , prev2[k/3]);
    }


    public:


    // // using recursion
    // int maxSizeSlices(vector<int>& slices) {
    //     int k = slices.size();
    //     int case1 = solveRecursive(0 , k-2 , slices , k/3);
    //     int case2 = solveRecursive(1 ,k-1 , slices , k/3);
    //     return max(case1 , case2);
    // }

    // // using memoization
    // int maxSizeSlices(vector<int>& slices) {
    //     int k = slices.size();
    //     vector<vector<int>>dp1(k + 1 , vector<int>(k+1 , -1));
    //     int case1 = solveMemoization(0 , k-2 , slices , k/3 , dp1);

    //     vector<vector<int>>dp2(k + 1 , vector<int>(k+1 , -1));
    //     int case2 = solveMemoization(1 ,k-1 , slices , k/3 , dp2);
    //     return max(case1 , case2);
    // }

    // // using tabulation
    // int maxSizeSlices(vector<int>& slices){
    //     return solveTabulation(slices);
    // } 

    // using space optimized approach
    int maxSizeSlices(vector<int>& slices){
        return solveOptimized(slices);
    } 
};

int main(){
    vector<int>slices = {8,9,8,6,1,1};
    // ans should be 16
    Solution obj;
    int ans = obj.maxSizeSlices(slices);
    cout<<"answer is : "<<ans<<endl;
    return 0;


}