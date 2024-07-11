// minimum cost tree from leaf values
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solveRecursive(vector<int>&arr , map<pair<int , int> , int>&maxi , int left , int right){

        // base case
        if(left == right){
            return 0;
        }

        // as we want a minimum answer
        int ans = INT_MAX;

        for(int i = left ; i < right ; i++){
            ans = min(ans , (maxi[{left , i}] * maxi[{i+1 , right}] + solveRecursive(arr , maxi , left , i) + solveRecursive(arr , maxi , i+1 , right)));
        }

        return ans;
    }

    int solveMemo(vector<int>&arr , map<pair<int , int> , int>&maxi , int left , int right , vector<vector<int>>&dp){

        // base case
        if(left == right){
            return 0;
        }

        if(dp[left][right] != -1){
            return dp[left][right];
        }

        int ans = INT_MAX;

        for(int i = left ; i < right ; i++){
            ans = min(ans , (maxi[{left , i}] * maxi[{i+1 , right}] + solveMemo(arr , maxi , left , i , dp) + solveMemo(arr , maxi , i+1 , right , dp)));
        }

        dp[left][right] = ans;
        return dp[left][right];
    }

    int solveTabulation(vector<int>&arr , map<pair<int , int> , int>&maxi , int left , int right){
        int n = arr.size();
        vector<vector<int>>dp(n+2 , vector<int>(n+2 , 0));

        for(int left = n-1 ; left >= 0 ; left--){
            for(int right = 0 ; right < n ; right++){
                if(left == right){
                    continue;
                }
                int ans = INT_MAX;

                for(int i = left ; i < right ; i++){
                    ans = min(ans , (maxi[{left , i}] * maxi[{i+1 , right}] + dp[left][i] + dp[i+1][right]));
                }

                dp[left][right] = ans;
            }
        }
        return dp[0][n-1];
    }
public:
    // // using recursion
    // int mctFromLeafValues(vector<int>& arr) {
    //     map<pair<int , int> , int> maxi;

    //     // to store max of each subtree
    //     for(int i=0 ; i<arr.size() ; i++){
    //         maxi[{i , i}] = arr[i];
    //         for(int j = i+1 ; j<arr.size() ; j++){
    //             maxi[{i , j}] = max(arr[j] , maxi[{i , j-1}]);
    //         }
    //     }

    //     return solveRecursive(arr , maxi , 0 , arr.size()-1);
    // }

    // // using memoization
    // int mctFromLeafValues(vector<int>& arr) {
    //     int n = arr.size();
    //     map<pair<int , int> , int> maxi;

    //     // to store max of each subtree
    //     for(int i=0 ; i<n ; i++){
    //         maxi[{i , i}] = arr[i];
    //         for(int j = i+1 ; j<n ; j++){
    //             maxi[{i , j}] = max(arr[j] , maxi[{i , j-1}]);
    //         }
    //     }

    //     vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1));
    //     return solveMemo(arr , maxi , 0 , n-1 , dp);
    // }

    // using Tabulation
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        map<pair<int , int> , int> maxi;

        // to store max of each subtree
        for(int i=0 ; i<n ; i++){
            maxi[{i , i}] = arr[i];
            for(int j = i+1 ; j<n ; j++){
                maxi[{i , j}] = max(arr[j] , maxi[{i , j-1}]);
            }
        }

        return solveTabulation(arr , maxi , 0 , n-1);
    }
};

int main(){
    vector<int>arr = {6,2,4};
    Solution obj;
    int ans = obj.mctFromLeafValues(arr);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}