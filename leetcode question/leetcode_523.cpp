// conitnous subarray sum
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // we are using pre computation approach
        unordered_map<int,int>mp;
        mp[0]=-1;
        int sum=0;
        for(int i=0 ; i<nums.size() ; i++){
            sum += nums[i];
            int rem = sum % k;
            if(!mp.count(rem)){
                mp[rem]=i;
            }//storing index
            else if(i - mp[rem] > 1){
                return true;
            }// if window size > 2 
        }
        return false;
    
    }
};
// If the remainder is already in the map: This means there is a previous cumulative sum that had the same remainder. The indices of these two sums, i (current index) and mp[rem] (index of previous occurrence of the same remainder), can be used to determine the length of the subarray whose sum is a multiple of k. Specifically, if the difference between the current index and the index stored in the map is greater than 1 (i - mp[rem] > 1), then there is a subarray of at least length 2 whose sum is a multiple of k, and the function returns true.


int main(){
    vector<int>nums = {23,2,6,4,7};
    int k = 13;
    Solution obj;
    bool ans = obj.checkSubarraySum(nums , k);
    (ans) ? cout<<"true" : cout<<"false";
    return 0;
}