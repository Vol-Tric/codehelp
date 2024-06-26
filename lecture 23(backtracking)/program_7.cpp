// subsets
#include<bits/stdc++.h>
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
    vector<int> nums = {3,4,5,6,7,8};
    Solution obj;
    vector<vector<int>>ans = obj.subsets(nums);
    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";

        }
        cout<<endl;
    }
    return 0;
}