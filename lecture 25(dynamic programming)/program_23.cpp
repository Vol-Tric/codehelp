// minimum swap to make arrays stricting increasing
#include<bits/stdc++.h>
using namespace std;

class Solution {

    int solveRecursive(vector<int>&nums1 , vector<int>&nums2 , int index  , bool swapped){
        if(index == nums1.size()){
            return 0;
        }

        int ans = INT_MAX;
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        // catch
        if(swapped){
            swap(prev1 , prev2);
        }

        // noSwap
        if(nums1[index] > prev1 && nums2[index] > prev2){
            ans = solveRecursive(nums1 , nums2 , index+1 , false);
        }

        // yesSwap
        if(nums1[index] > prev2 && nums2[index] > prev1){
            ans = min(ans , 1 + solveRecursive(nums1 , nums2 , index+1 , true));
        }

        return ans;
    }

    int solveMemo(vector<int>&nums1 , vector<int>&nums2 , int index  , bool swapped , vector<vector<int>>&dp){
        if(index == nums1.size()){
            return 0;
        }

        if(dp[index][swapped] != -1){
            return dp[index][swapped];
        }

        int ans = INT_MAX;
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        // catch
        if(swapped){
            swap(prev1 , prev2);
        }

        // noSwap
        if(nums1[index] > prev1 && nums2[index] > prev2){
            ans = solveMemo(nums1 , nums2 , index+1 , false , dp);
        }

        // yesSwap
        if(nums1[index] > prev2 && nums2[index] > prev1){
            ans = min(ans , 1 + solveMemo(nums1 , nums2 , index+1 , true , dp));
        }
        dp[index][swapped] = ans;
        return dp[index][swapped];
    }

    int solveTablutation(vector<int>&nums1 , vector<int>&nums2){
        vector<vector<int>>dp(nums1.size()+1 , vector<int>(2 , 0));

        for(int index = nums1.size()-1 ; index >=1 ; index--){
            for(int swapped = 1 ; swapped >= 0 ; swapped--){
                int ans = INT_MAX;
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                // catch
                if(swapped){
                    swap(prev1 , prev2);
                }

                // noSwap
                if(nums1[index] > prev1 && nums2[index] > prev2){
                    ans = dp[index+1][0];
                }

                // yesSwap
                if(nums1[index] > prev2 && nums2[index] > prev1){
                    ans = min(ans , 1 + dp[index+1][1]);
                }

                dp[index][swapped] = ans;
            }
        }
        return dp[1][0];
    }

    int solveSpaceOptimized(vector<int>&nums1 , vector<int>&nums2){
        int Swap = 0;
        int noSwap = 0;
        int currSwap = 0;
        int currNoSwap = 0;

        for(int index = nums1.size()-1 ; index >=1 ; index--){
            for(int swapped = 1 ; swapped >= 0 ; swapped--){
                int ans = INT_MAX;
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                // catch
                if(swapped){
                    swap(prev1 , prev2);
                }

                // noSwap
                if(nums1[index] > prev1 && nums2[index] > prev2){
                    ans = noSwap;
                }

                // yesSwap
                if(nums1[index] > prev2 && nums2[index] > prev1){
                    ans = min(ans , 1 + Swap);
                }


                (swapped) ? currSwap = ans : currNoSwap = ans;
            }
            Swap = currSwap;
            noSwap = currNoSwap;
        }
        return currNoSwap;
    }
public:
    // // using recursion
    // int minSwap(vector<int>& nums1, vector<int>& nums2) {
    //     nums1.insert(nums1.begin() , -1);
    //     nums2.insert(nums2.begin() , -1);
    //     return solveRecursive(nums1 , nums2 , 1 , false);
    // }

    // // using Memoization
    // int minSwap(vector<int>& nums1, vector<int>& nums2) {
    //     nums1.insert(nums1.begin() , -1);
    //     nums2.insert(nums2.begin() , -1);
    //     vector<vector<int>>dp(nums1.size() , vector<int>(2 , -1));
    //     return solveMemo(nums1 , nums2 , 1 , false , dp);
    // }

    // // using Tabulation
    // int minSwap(vector<int>& nums1, vector<int>& nums2) {
    //     nums1.insert(nums1.begin() , -1);
    //     nums2.insert(nums2.begin() , -1);
    //     return solveTablutation(nums1 , nums2);
    // }

    // using Space Optimized Approach
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin() , -1);
        nums2.insert(nums2.begin() , -1);
        return solveSpaceOptimized(nums1 , nums2);
    }
};

int main(){
    vector<int>nums1 = {3,3,8,9,10};
    vector<int>nums2 = {1,7,4,6,8};
    Solution obj;
    int ans = obj.minSwap(nums1 , nums2);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}