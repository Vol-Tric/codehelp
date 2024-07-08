// longest AP with give difference "d"

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int , int>dp;
        int ans = 0;
        // minimum could be 1
        int maxi = 1;

        for(int i=0 ; i<arr.size() ; i++){
            int temp = arr[i] - difference;
            if(dp.count(temp)){
                dp[arr[i]] = 1 + dp[temp];
                maxi = max(maxi , dp[arr[i]]);
            }
            else{
                dp[arr[i]] = 1;
            }
        }
        return maxi;
    }
};

int main(){
    vector<int>nums = {1,5,7,8,5,3,4,2,1};
    int difference = -2;
    Solution obj;
    int ans = obj.longestSubsequence(nums , difference);
    cout<<"answer is : "<<ans<<endl;
    return 0;

}