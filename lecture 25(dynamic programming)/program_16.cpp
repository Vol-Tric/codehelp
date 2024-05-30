// reducing dishes
// based on 0-1 knapsack
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solveRecursive(vector<int>& satisfaction , int index , int time){
        sort(satisfaction.begin() , satisfaction.end());
        // base case
        if(index == satisfaction.size()){
            return 0;
        }

        int include = satisfaction[index] * (time + 1) + solveRecursive(satisfaction , index+1 , time+1);

        int exclude = 0 + solveRecursive(satisfaction , index + 1 , time);

        return max(include , exclude);
    }

    int solveMemo(vector<int>& satisfaction , int index , int time , vector<vector<int>>dp){
        sort(satisfaction.begin() , satisfaction.end());
        // base case
        if(index == satisfaction.size()){
            return 0;
        }

        if(dp[index][time] != -1){
            return dp[index][time];
        }

        int include = satisfaction[index] * (time + 1) + solveMemo(satisfaction , index+1 , time+1 , dp);

        int exclude = 0 + solveMemo(satisfaction , index+1 , time , dp);

        dp[index][time] = max(include , exclude);
        return dp[index][time];
    }

    int solveTabulation(vector<int>& satisfaction){
        sort(satisfaction.begin() , satisfaction.end());
        int n = satisfaction.size();
        vector<vector<int>>dp(n+1 , vector<int>(n+1 , 0)); //dp[index][time]
        
        // base case
        // no need of base case as all the values are initally zero


        for(int index = n-1 ; index >= 0 ;index--){
            for(int time = index ; time >= 0 ; time--){
                int include = satisfaction[index]*(time + 1) + dp[index+1][time+1];
                int exclude = 0 + dp[index+1][time];

                dp[index][time] = max(include , exclude);
            }
        }

        return dp[0][0];
    }

    int solveSpaceOptimized(vector<int>&satisfaction){
        sort(satisfaction.begin() , satisfaction.end());
        int n = satisfaction.size();

        vector<int>curr(n+1 , 0); // curr = dp[index]
        vector<int>next(n+1 , 0);

        for(int index = n-1 ; index >= 0 ; index--){
            for(int time = 0 ; time <= n ; time++){
                int include = satisfaction[index] * (time + 1) + next[time+1];
                int exclude = 0 + next[time];

                curr[time] = max(include , exclude);
            }
            next = curr;
        }
        return curr[0];
    }

    

    public:
    // // using Recursion
    // int maxSatisfaction(vector<int>& satisfaction) {
    //     return solveRecursive(satisfaction , 0 , 0);
    // }

    // // using Memoization
    // int maxSatisfaction(vector<int>& satisfaction) {
    //     int n = satisfaction.size();
    //     vector<vector<int>>dp(n , vector<int>(n , -1));
    //     return solveMemo(satisfaction , 0 , 0 , dp);
    // }

    // // using tabulation S.C = O(N*N)
    // int maxSatisfaction(vector<int>& satisfaction){
    //     return solveTabulation(satisfaction);
    // }

    // using space optimized approach S.C = O(N)
    int maxSatisfaction(vector<int>& satisfaction){
        return solveSpaceOptimized(satisfaction);
    }

    
};

int main(){
    vector<int>satisfaction = {4,3,2};
    // ans should be 14
    Solution obj;
    int ans = obj.maxSatisfaction(satisfaction);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}