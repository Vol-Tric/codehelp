// partition equal subset sum

#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool solveRecursive(vector<int>&nums , int target , int index){
        if(index == nums.size() || target < 0){
            return false;
        }
        if(target == 0){
            return true;
        }

        bool include = solveRecursive(nums , target - nums[index] , index+1);
        bool exclude = solveRecursive(nums , target , index+1);

        if(include || exclude){
            return true;
        }
        return false;
    }

    bool solveMemo(vector<int>&nums , int target , int index , vector<vector<int>>&dp){
        if(index == nums.size() || target < 0){
            return false;
        }
        if(target == 0){
            return true;
        }

        if(dp[index][target] != -1){
            return dp[index][target];
        }

        bool include = solveMemo(nums , target - nums[index] , index+1 , dp);
        bool exclude = solveMemo(nums , target , index+1 , dp);

        if(include || exclude){
            dp[index][target] = 1;
        }
        else{
            dp[index][target] = 0;
        }
        return dp[index][target];
    }

    bool solveTabulation(vector<int>&nums , int total){
        int N = nums.size();
        vector<vector<int>>dp(N+1 , vector<int>(total+1 , 0));

        for(int i=0 ; i<=N ; i++){
            dp[i][0] = 1;
        }

        for(int index = N-1 ; index >= 0 ; index--){
            for(int target = 0 ; target <= total/2 ; target++){
                bool include = false;
                if(target - nums[index] >= 0){
                    include = dp[index+1][target - nums[index]];
                }
                bool exclude = dp[index+1][target];

                if(include || exclude){
                    dp[index][target] = 1;
                }
                else{
                    dp[index][target] = 0;  
                }
            }
        }

        return dp[0][total/2];
    }

    int solveSpaceOptimized(vector<int>&nums , int total){
        int N = nums.size();

        vector<int>curr(total+1 , 0);
        vector<int>prev(total+1 , 0);

        curr[0] = 1;
        prev[0] = 1;

        for(int index = N-1 ; index >= 0 ; index--){
            for(int target = 0 ; target <= total/2 ; target++){
                bool include = false;
                if(target - nums[index] >= 0){
                    include = curr[target - nums[index]];
                }
                bool exclude = curr[target];

                if(include || exclude){
                    prev[target] = 1;
                }
                else{
                    prev[target] = 0;
                }
            }
            curr = prev;
        }

        return prev[total/2];
    }
public:
    // // using recursion
    // bool canPartition(vector<int>& nums) {
    //     int sum = 0;
    //     for(auto i : nums){
    //         sum += i;
    //     }
    //     if(sum%2 != 0){
    //         return false;
    //     }
    //     return solveRecursive(nums , sum/2 , 0);
    // }

    // // using memoization
    // bool canPartition(vector<int>& nums) {
    //     int sum = 0;
    //     for(auto i : nums){
    //         sum += i;
    //     }
    //     if(sum%2 != 0){
    //         return false;
    //     }
    //     int target = sum/2;
    //     vector<vector<int>>dp(nums.size() , vector<int>(target+1 , -1));
    //     return solveMemo(nums , sum/2 , 0 , dp);
    // }

    // // using tabulation
    // bool canPartition(vector<int>& nums) {
    //     int sum = 0;
    //     for(auto i : nums){
    //         sum += i;
    //     }
    //     if(sum%2 != 0){
    //         return false;
    //     }
    //     int target = sum/2;
    //     return solveTabulation(nums , sum);
    // }

    // using space optimized approach
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i : nums){
            sum += i;
        }
        if(sum%2 != 0){
            return false;
        }
        int target = sum/2;
        return solveSpaceOptimized(nums , sum);
    }
};

int main(){
    vector<int>nums = {1,5,11,5};
    Solution obj;
    bool ans = obj.canPartition(nums);

    (ans) ? cout<<"True"<<endl : cout<<"False"<<endl;
    return 0;
}