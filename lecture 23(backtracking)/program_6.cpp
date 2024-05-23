// sub sets XOR sum
#include<bits/stdc++.h>
using namespace std;

class Solution{
    void solve(vector<int>&nums , vector<int>&subset , vector<vector<int>>& ans , int index){
        ans.push_back(subset);

        for(int i = index ; i<nums.size() ; i++){
            subset.push_back(nums[i]);
            solve(nums , subset , ans , i+1);
            subset.pop_back();
        }
    }
    public:
    vector<vector<int>>subSets(vector<int>&nums){
        vector<vector<int>>ans;
        vector<int>subset;
        int index = 0;
        solve(nums , subset , ans , index);
        return ans;

    }

    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>>ans = subSets(nums);
        int cost = 0;
        for(auto i : ans){
            int temp = 0;
            for(auto j : i){
                temp = temp ^ j;
            }

            cost = cost + temp;
        }
        return cost;
    }
};

int main(){
    vector<int> nums = {3,4,5,6,7,8};
    Solution obj;
    vector<vector<int>>ans = obj.subSets(nums);
    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";

        }
        cout<<endl;
    }

    cout<<endl<<"NEXT"<<endl;

    int cost = obj.subsetXORSum(nums);
    cout<<"cost is : "<<cost<<endl;
    return 0;
}