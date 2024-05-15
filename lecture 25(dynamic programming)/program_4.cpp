//  Maximum sum of non-adjacent elements
#include<bits/stdc++.h>
using namespace std;

class Solution{
    int solveRecursive(vector<int>&nums , int index){
        // base case
        if(index < 0){
            return 0;
        }
        if(index == 0){
            return nums[0];
        }
        int include = nums[index] + solveRecursive(nums , index-2);
        int exclude = solveRecursive(nums , index-1);

        return max(include , exclude);
    }

    int solveMemo(vector<int>&nums , int index , vector<int>&dp){
        // base case
        if(index < 0){
            return 0;
        }
        if(index == 0){
            return nums[0];
        }

        // memoization
        if(dp[index] != -1){
            return dp[index];
        }
        int include = nums[index] + solveMemo(nums , index-2 , dp);
        int exclude = solveMemo(nums , index-1 , dp);

        dp[index] = max(include , exclude);
        return max(include , exclude);
    }

    int solveTabulation(vector<int>&nums){
        int n = nums.size();

        if(n == 0){
            return 0;
        }

        vector<int>dp(n , 0);

        dp[0] = nums[0];
        dp[1] = max(nums[0] , nums[1]);

        for(int i = 2 ; i<n ; i++){
            int include = dp[i-2] + nums[i];
            int exclude = dp[i-1];
            dp[i] = max(include , exclude);
        }
        return dp[n-1];
    }

    int solveOptimized(vector<int>&nums){
        int n = nums.size();
        if(n == 0){
            return 0;
        }

        int first = nums[0];
        int second = max(nums[0] , nums[1]);
        int temp = 0;
        for(int i=2 ; i<n ; i++){
            temp = max(nums[i] + first , second);
            first = second;
            second = temp;
        }
        return temp;
    }


    public:
    // // using basic recursion
    // int maximumNonAdjacentSum(vector<int> &nums){
    //     int n = nums.size();
    //     int ans = solveRecursive(nums , n-1);
    //     return ans;
    // }

    // // using memoization
    // int maximumNonAdjacentSum(vector<int> &nums){
    //     int n = nums.size();
    //     vector<int>dp(n+1 , -1);
    //     int ans = solveMemo(nums , n-1 , dp);
    //     return ans;
    // }

    // // using Tabulation
    // int maximumNonAdjacentSum(vector<int> &nums){
        
    //     int ans = solveTabulation(nums);
    //     return ans;
    // }

    // using space optimized way
    int maximumNonAdjacentSum(vector<int> &nums){
        
        int ans = solveOptimized(nums);
        return ans;
    }

};

int main(){
    vector<int>nums = {2, 1, 4, 9};
    Solution obj;
    int ans = obj.maximumNonAdjacentSum(nums);
    cout<<ans<<endl;
    return 0;
}