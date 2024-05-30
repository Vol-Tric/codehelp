// min score triangulation of polygon
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solveRecursive(vector<int>& v , int i , int j){
        // base case
        if(i+1 == j){
            return 0;
        }
        int ans = INT_MAX;
        for(int k = i+1 ; k<j ; k++){
            ans = min(ans , v[i]*v[j]*v[k] + solveRecursive(v , i , k) + solveRecursive(v , k , j));
        }
        return ans;
    }

    int solveMemoization(vector<int>&v , int i , int j , vector<vector<int>>dp){
        // base case
        if(i+1 == j){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = INT_MAX;
        for(int k = i+1 ; k<j ; k++){
            ans = min(ans , v[i]*v[j]*v[k] + solveMemoization(v , i , k , dp) + solveMemoization(v , k , j , dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }


    int solveTabulation(vector<int>& v , int i , int j){
        int n = v.size();
        vector<vector<int>>dp(n , vector<int>(n , 0));

        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = i+2 ; j<n ; j++){ // j starts from i+2 so that there are atleast 3 nodes in between
                int ans = INT_MAX;
                for(int k = i+1 ; k<j ; k++){
                    ans = min(ans , v[i]*v[j]*v[k] + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][n-1];
    }

    public:

    // // using recursion
    // int minScoreTriangulation(vector<int>& values) {
    //     int n = values.size();
    //     return solveRecursive(values , 0 , n-1);
    // }

    // // using Memoization
    // int minScoreTriangulation(vector<int>& values) {
    //     int n = values.size();
    //     vector<vector<int>>dp(n , vector<int>(n , -1));
    //     return solveMemoization(values , 0 , n-1 , dp);
    // }

    // using Tabulation
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        return solveTabulation(values , 0 , n-1);
    }
};

int main(){
    vector<int>nums = {3,7,4,5};
    // ans should be 144
    Solution obj;
    int ans = obj.minScoreTriangulation(nums);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}