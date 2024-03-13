// subsets, output should be the power set of the entered array
// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]


#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    void solve(vector<int> nums, vector<int>output ,int index,vector<vector<int>>& ans){
        // base case
        if(index>=nums.size()){
            ans.push_back(output);
            return ;
        }
        // exclude
        solve(nums,output,index+1,ans);

        // include
        int element=nums[index];
        output.push_back(element);
        solve(nums,output,index+1,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index=0;
        solve(nums,output,index,ans);
        return ans;
    }
};

int main(){
    Solution sol1;
    vector<int>nums={1,2,3};
    vector<vector<int>> ans;
    ans=sol1.subsets(nums);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<", ";
    }

}