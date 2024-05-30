// combination sum
#include<bits/stdc++.h>
using namespace std;

class Solution{
    int solveRecursive(vector<int>nums , int target){
        // base case
        if(target == 0){
            return 1;
        }
        if(target < 0){
            return 0;
        }

        int ans = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            ans += solveRecursive(nums , target-nums[i]);
        }

        return ans;
    }

    int solveMemo(vector<int>nums , int target , vector<int>dp){
        // base case
        if(target == 0){
            return 1;
        }
        if(target < 0){
            return 0;
        }

        if(dp[target] != -1){
            return dp[target];
        }

        int ans = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            ans += solveMemo(nums , target-nums[i] , dp);
        }
        dp[target] = ans;
        return dp[target];
    }

    int solveTabulation(vector<int>nums , int target){
        vector<int>dp(target+1 , 0);
        if(target == 0){
            return 1;
        }
        if(target < 0){
            return 0;
        }
        dp[0] = 1;

        for(int i = 1 ; i<=target ; i++){
            for(int j = 0 ; j<nums.size() ; j++){
                if(i - nums[j] >= 0){
                    dp[i] += dp[i - nums[j]];
                }
                    
            }
        }
        return dp[target];
    }
    public:
    // // using recursive
    // int findWays(vector<int> &num, int tar){
    //     return solveRecursive(num , tar);
    // }

    // // using Memoization
    // int findWays(vector<int> &num, int tar){
    //     vector<int>dp(tar+1 , -1);
    //     return solveMemo(num , tar , dp);
    // }

    // using Memoization
    int findWays(vector<int> &num, int tar){
        
        return solveTabulation(num , tar);
    }
};

int main(){
    vector<int>nums = {1,2,5};
    int target = 5;

    Solution obj;
    int ans = obj.findWays(nums , target);
    cout<<"answer is : "<<ans<<endl;

    return 0;
    
}
