// permutation
// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
#include<iostream>
#include<vector>
using namespace std;
// here instead of creating anoter array for output, we swap the digits in nums itself
class Solution {
private:
    void solve(vector<int> nums, int index, vector<vector<int>>&ans){
        // base case
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }
        

        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            solve(nums,index+1,ans);
            // backtracking
            swap(nums[index],nums[i]);
        }

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;

        int index=0;
        solve(nums,index,ans);
        return ans;
    }
};

int main(){
    Solution sol1;
    vector<int> nums={1,2,3};
    vector<vector<int>> ans;
    ans=sol1.permute(nums);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<", ";
    }
    return 0;

}