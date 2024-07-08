// longest arithmetic Progression
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solveRecursive(int index , int diff , vector<int>&nums){
        if(index < 0){
            return 0;
        }

        int ans = 0;
        for(int j = index-1 ; j >= 0 ; j--){
            if((nums[index] - nums[j]) == diff){
                ans = max(ans , 1 + solveRecursive(j , diff , nums));
            }
        }
        return ans;
    }

    int solveMemoization(int index , int diff , vector<int>&nums , unordered_map<int , int>dp[]){
        if(index < 0){
            return 0;
        }

        if(dp[index].count(diff)){
            return dp[index][diff];
        }
        int ans = 0;
        for(int j = index-1 ; j >= 0 ; j--){
            if((nums[index] - nums[j]) == diff){
                ans = max(ans , 1 + solveMemoization(j , diff , nums , dp));
            }
        }
        dp[index][diff] = ans;
        return dp[index][diff];
    }
public:
    // // using recursive approach
    // int longestArithSeqLength(vector<int>& nums) {
    //     int n = nums.size();
    //     sort(nums.begin() , nums.end());

    //     if(n <= 2){
    //         return n;
    //     }

    //     int ans = 0;

    //     for(int i=0 ; i<n ; i++){
    //         for(int j = i+1 ; j<n ; j++){
    //             ans = max(ans , 2 + solveRecursive(i , nums[j] - nums[i] , nums));
    //         }
    //     }
    //     return ans;
    // }

    // // using memoization
    // int longestArithSeqLength(vector<int>& nums) {
    //     int n = nums.size();
    //     sort(nums.begin() , nums.end());

    //     if(n <= 2){
    //         return n;
    //     }

    //     int ans = 0;
    //     unordered_map<int , int>dp[n+1];

    //     for(int i=0 ; i<n ; i++){
    //         for(int j = i+1 ; j<n ; j++){
    //             ans = max(ans , 2 + solveMemoization(i , nums[j] - nums[i] , nums , dp));
    //         }
    //     }
    //     return ans;
    // }

    // using tabulation
    int longestArithSeqLength(vector<int>& nums){
        int n = nums.size();
        sort(nums.begin() , nums.end());

        if(n <= 2){
            return n;
        }

        int ans = 0;
        unordered_map<int , int>dp[n+1];

        for(int i=1 ; i<n ; i++){
            for(int j=0 ; j<i ; j++){
                int diff = nums[i] - nums[j];
                int cnt = 1;

                // check if ans already present
                if(dp[j].count(diff)){
                    cnt = dp[j][diff];
                }
                dp[i][diff] = 1 + cnt;
                ans = max(ans , dp[i][diff]);
            }
        }
        return ans;
    }
};

int main(){
    vector<int>nums = {0,8,45,88,48,68,28,55,17,24};
    Solution obj;
    int ans = obj.longestArithSeqLength(nums);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}