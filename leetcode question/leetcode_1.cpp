// two sum
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int , int>mp;
        int n = nums.size();
        for(int i=0 ; i<n ; i++){
            int comp = target - nums[i];
            if(mp.count(comp)){
                return {i , mp[comp]};
            }
            mp[nums[i]] = i;

        }
        return {};
    }
};

int main(){
    vector<int>nums = {2,7,11,15};
    int target = 9;
    // output should be [0,1]
    Solution obj;
    vector<int>ans = obj.twoSum(nums , target);
    cout<<"answer is "<<endl;
    for(auto i : ans){
        cout<<i<<" "; 
    }
    cout<<endl;
    return 0;
}