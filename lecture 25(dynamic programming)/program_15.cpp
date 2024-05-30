// minimum sideways jumps
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solveRecursive(vector<int>& obstacles , int currPos , int currLane){
        // base case
        if(currPos == obstacles.size() - 1){
            return 0;
        }

        if(obstacles[currPos+1] != currLane){
            return solveRecursive(obstacles , currPos+1 , currLane);
        }
        else{
            // sideways jump
            int ans = INT_MAX;
            for(int i=1 ; i<=3 ; i++){
                if(i != currLane && obstacles[currPos] != i){
                    ans = min(ans , 1 + solveRecursive(obstacles , currPos , i));
                }
            }
            return ans;
        }
        
    }

    int solveMemo(vector<int>& obstacles , int currPos , int currLane , vector<vector<int>>&dp){
        // base case
        if(currPos == obstacles.size() - 1){
            return 0;
        }

        if(dp[currLane][currPos] != -1){
            return dp[currLane][currPos];
        }

        if(obstacles[currPos+1] != currLane){
            return solveMemo(obstacles , currPos+1 , currLane , dp);
        }
        else{
            // sideways jump
            int ans = INT_MAX;
            for(int i=1 ; i<=3 ; i++){
                if(i != currLane && obstacles[currPos] != i){
                    ans = min(ans , 1 + solveMemo(obstacles , currPos , i , dp));
                }
            }
            dp[currLane][currPos] = ans;
            return dp[currLane][currPos];
        }
    }

    int solveTabulation(vector<int>& obstacles){
        int n = obstacles.size();
        vector<vector<int>>dp(4 , vector<int>(n , INT_MAX));

        for(int i=0 ; i<=3 ; i++){
            dp[i][n-1] = 0;
        }

        for(int pos = n-2 ; pos >= 0 ; pos--){
            for(int lane = 1 ; lane <= 3 ; lane++){
                if(obstacles[pos+1] != lane){
                    dp[lane][pos] = dp[lane][pos+1];
                }
                else{
                    // sideways jump
                    int ans = INT_MAX;
                    for(int i=1 ; i<=3 ; i++){
                        if(i != lane && obstacles[pos] != i){
                            ans = min(ans , 1 + dp[i][pos+1]);
                        }
                    }
                    dp[lane][pos] = ans;
                    
                }
            }
        }
        return min(dp[2][0] , min(1+dp[1][0] , 1+dp[3][0]));

    }

    int solveSpaceOptimized(vector<int>& obstacles){
        int n = obstacles.size();

        vector<int>next(4 , INT_MAX);
        vector<int>curr(4 , INT_MAX);

        for(int i=0 ; i<=3 ; i++){
            next[i] = 0;
        }

        for(int pos = n-2 ; pos >= 0 ; pos--){
            for(int lane = 1 ; lane <= 3 ; lane++){
                if(obstacles[pos+1] != lane){
                    curr[lane] = next[lane];
                }
                else{
                    int ans = INT_MAX;
                    for(int i=1 ; i<=3 ; i++){
                        if(i != lane && obstacles[pos] != i){
                            ans = min(ans , 1 + next[i]);
                        }
                    }
                    curr[lane] = ans;
                }
            }
            next = curr;
        }

        return min(next[2] , min(1+next[1] , 1+next[3]));


    }
    public:

    // // using recursion
    // int minSideJumps(vector<int>& obstacles) {
    //     return solveRecursive(obstacles , 0 , 2);
    // }

    // // using Memoization
    // int minSideJumps(vector<int>& obstacles) {
    //     int n = obstacles.size();
    //     vector<vector<int>>dp(4 , vector<int>(obstacles.size() , -1));
    //     return solveMemo(obstacles , 0 , 2 , dp);
    // }

    // // using recursion
    // int minSideJumps(vector<int>& obstacles) {
    //     return solveTabulation(obstacles);
    // }

    // using space optimized approach , S.C O(1) , as only 8 block f memory are used
    int minSideJumps(vector<int>& obstacles) {
        return solveSpaceOptimized(obstacles);
    }
};

int main(){
    vector<int>obstacles = {0,1,2,3,0};
    // ans should be 2
    Solution obj;
    int ans = obj.minSideJumps(obstacles);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}