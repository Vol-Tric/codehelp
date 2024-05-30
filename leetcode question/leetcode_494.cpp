// target sum
#include<bits/stdc++.h>
using namespace std;
class Solution {
    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum  = 0;
        for(auto i : nums){
            sum += i;
        }

        // base case
        if(sum < abs(target) || (sum + target)%2 != 0){
            return 0;
        }

        int temp = (sum + target)/2;

        vector<int>dp(temp+1 , 0);
        dp[0] = 1;
        for(auto i : nums){
            for(int j = temp ; j >= i ; j--){
                dp[j] += dp[j-i];
            }
        }
        return dp[temp];

    }
};

int main(){
    vector<int>nums = {1,1,1,1,1};
    int target = 3;
    // ans is 5

    Solution obj;
    int ans = obj.findTargetSumWays(nums , target);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}