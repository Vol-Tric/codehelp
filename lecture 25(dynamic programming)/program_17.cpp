// longest Increasing subsequence
#include<bits/stdc++.h>
using namespace std;

class Solution{
    int solveRecursive(int n , vector<int>arr , int curr , int prev){
        // base case
        if(curr == n){
            return 0;
        }

        // include
        int include = 0;
        if(arr[curr] > arr [prev] || prev == -1){
            include = 1 + solveRecursive(n , arr , curr + 1 , curr);
        }

        int exclude = 0 + solveRecursive(n , arr , curr + 1 , prev);

        return max(include , exclude);
    }

    int solveMemo(int n , vector<int>arr , int curr , int prev , vector<vector<int>>&dp){
        // base case
        if(curr == n){
            return 0;
        }

        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }

        // include
        int include = 0;
        if(arr[curr] > arr [prev] || prev == -1){
            include = 1 + solveMemo(n , arr , curr + 1 , curr , dp);
        }

        int exclude = 0 + solveMemo(n , arr , curr + 1 , prev , dp);

        dp[curr][prev+1] = max(include , exclude);
        return dp[curr][prev+1];
    }

    int solveTabulation(int n , vector<int>&arr){
        vector<vector<int>>dp(n+1 , vector<int>(n+1 , 0));

        for(int curr = n-1 ; curr >= 0 ; curr--){
            for(int prev = curr-1 ; prev >= -1 ; prev--){
                int include = 0;
                if(prev == -1 || arr[curr] > arr [prev]){
                    include = 1 + dp[curr+1][curr + 1]; // prev+1 bcz prev can be -1 , same for curr + 1
                }

                int exclude = 0 + dp[curr+1][prev+1]; // prev+1 bcz prev can be -1

                dp[curr][prev+1] = max(include , exclude);
            }
        }
        return dp[0][0];
    }

    int solveSpaceOptimized(int n , vector<int>&arr){
        vector<int>currRow(n+1 , 0);
        vector<int>nextRow(n+1 , 0);

        for(int curr = n-1 ; curr >= 0 ; curr--){
            for(int prev = curr-1 ; prev >= -1 ; prev--){
                int include = 0;
                if(prev == -1 || arr[curr] > arr [prev]){
                    include = 1 + nextRow[curr + 1]; // prev+1 bcz prev can be -1 , same for curr + 1
                }

                int exclude = 0 + nextRow[prev+1]; // prev+1 bcz prev can be -1

                currRow[prev + 1] = max(include , exclude);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    
    }

    // using DP with binary search
    int solveOptimal(int n , vector<int>&arr){
        if(n == 0){
            return 0;
        }

        vector<int>ans;
        ans.push_back(arr[0]);

        for(int i=1 ; i<n ; i++){
            if(arr[i] > ans.back()){
                ans.push_back(arr[i]);
            }
            else{
                // find index of just larger element in ans
                int index = lower_bound(ans.begin() , ans.end() , arr[i]) - ans.begin();
                ans[index] = arr[i];
            }
        }

        return ans.size();
    }

    
    public:
    // // using recursion
    // int longestSubsequence(int n, vector<int>&arr){
    //     return solveRecursive(n , arr , 0 , -1);
    // }

    // // using Memoization
    // int longestSubsequence(int n, vector<int>&arr){
    //     vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1));
    //     return solveMemo(n , arr , 0 , -1 , dp);
    // }

    // // using tabulation
    // int longestSubsequence(int n, vector<int>&arr){
    //     return solveTabulation(n , arr);
    // }

    // // using space optimized approach
    // int longestSubsequence(int n, vector<int>&arr){
    //     return solveSpaceOptimized(n , arr);
    // }

    // using optimal approach using DP with binary search
    int longestSubsequence(int n, vector<int>&arr){
        return solveOptimal(n , arr);
    }

    
};

int main(){
    vector<int>arr = {5,8,3,7,9,1};
    int n = arr.size();
    // ans should be 3
    Solution obj;
    int ans = obj.longestSubsequence(n , arr);
    cout<<"answer is : "<<ans<<endl;
    return 0;


}