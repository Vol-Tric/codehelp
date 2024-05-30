// maximum product sub array
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int maxOfArray(vector<int>nums){
        int maxi = INT_MIN;
        for(auto i : nums){
            maxi = max(maxi , i);
        }
        return maxi;
    }


    int solveTabulation(vector<int>&nums){
        if(nums.size() == 1){
            return nums[0];
        }
        vector<pair<int , int>>dp(nums.size() + 1); // pair<max , min>
        dp[0].first = nums[0];
        dp[0].second = nums[0];
        int ans = INT_MIN;
        for(int i = 1 ; i<nums.size() ; i++){
            
            // int temp = dp[i-1].first*nums[i];
            dp[i].first = max(dp[i-1].first*nums[i] , max(nums[i] , dp[i-1].second*nums[i]));
            dp[i].second = min(dp[i-1].first*nums[i] , min(nums[i] , dp[i-1].second*nums[i]));
            
            cout<<dp[i].first<<"  "<<dp[i].second<<endl;
            ans = max(ans , max(dp[i].first , dp[i].second));
            cout<<ans<<endl;
        }
        return ans;
    }


    int solveSpaceOptimized(vector<int>&nums){
        if(nums.size() == 1){
            return nums[0];
        }

        int ans = maxOfArray(nums);
        int currMax = INT_MIN;
        int currMin = INT_MAX;

        for(auto i : nums){
            int temp = currMax*i;
            currMax = max(currMax*i , max(currMin*i , i));
            currMin = min(temp , min(currMin*i , i));
            ans = max(ans , currMax);
        }
        return ans;
    }
public:
    // // using tabulation
    // int maxProduct(vector<int>& nums) {
    //     return solveTabulation(nums);
    // }

    // using space optimized approach
    int maxProduct(vector<int>& nums) {
        return solveSpaceOptimized(nums);
    }
};

int main(){
    vector<int>nums = {2,-1,1,1};
    // ans should be 6
    Solution obj;
    int ans = obj.maxProduct(nums);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}