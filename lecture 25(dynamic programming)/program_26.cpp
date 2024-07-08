// longest AP subsequence
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        
        // If there are only two elements, the longest arithmetic subsequence is of length 2
        if (n == 2){
            return 2;
        }
        
        // dp[i] will store a map of differences and their lengths ending at index i
        vector<unordered_map<int, int>> dp(n);
        
        // Initialize the maximum length of the arithmetic subsequence found
        int maxLength = 2;
        
        // Iterate through each element in the array
        for (int i = 0; i < n; ++i) {
            // Compare current element with all previous elements
            for (int j = 0; j < i; ++j) {
                // Calculate the difference between nums[i] and nums[j]
                int diff = nums[i] - nums[j];
                
                // Check if there's already an entry for this difference ending at index j
                if (dp[j].find(diff) != dp[j].end()) {
                    // If found, update dp[i][diff] to be one more than dp[j][diff]
                    dp[i][diff] = dp[j][diff] + 1;
                } else {
                    // Otherwise, initialize dp[i][diff] as 2 since we have nums[j] and nums[i]
                    dp[i][diff] = 2;
                }
                
                // Update the maxLength with the maximum of its current value or dp[i][diff]
                maxLength = max(maxLength, dp[i][diff]);
            }
        }
        
        // Return the maximum length of any arithmetic subsequence found
        return maxLength;
    }
};

int main(){
    vector<int>nums = {9,4,7,2,10};
    Solution obj;
    int ans = obj.longestArithSeqLength(nums);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}