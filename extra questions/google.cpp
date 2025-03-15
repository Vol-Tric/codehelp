// given a matrix with 0 indicating water and 1 indicating land , find the square island with largest

// 101010
// 001001
// 011100
// 111101
// 011100
// 111111

// in this the largest area is of 9

// program 13 , DP series
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxArea(vector<vector<int>>&nums){
        int n = nums.size();
        int m = nums[0].size();

        vector<vector<int>>dp(n+1 , vector<int>(m+1 , 0));
        int maxi = 0;
        for(int i = n-1 ; i>=0 ; i--){
            for(int j = m-1 ; j>=0 ; j--){
                int right = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int down = dp[i+1][j];

                if(nums[i][j] == 1){
                    dp[i][j] = 1 + min({right , diagonal , down});
                    maxi = max(dp[i][j] , maxi);
                    
                }
                else{
                    dp[i][j] = 0;
                }    
            }
        }
        return maxi * maxi;
    }
};

int main(){
    vector<vector<int>>nums = {{1,0,1,0,1,0} , {0,0,1,0,0,1} , {0,1,1,1,0,0} , {1,1,1,1,0,1} , {0,1,1,1,0,0}, {1,1,1,1,1,1}};

    Solution obj;
    int ans = obj.maxArea(nums);
    cout<<"answer is : "<<ans<<endl;
    return 0;

}