// 0 1 knapsack
#include<bits/stdc++.h>
using namespace std;

class Solution{
    int solveRecursive(vector<int> weight, vector<int> value, int index, int maxCapacity){
        // base case , if only 1 item to steal , compare its weight with the max capacity
        if(index == 0){
            if(weight[0] <= maxCapacity){
                return value[0];
            }
            else{
                return 0;
            }
        }

        int include = 0;
        if(weight[index] <= maxCapacity){
            include =value[index] + solveRecursive(weight , value , index-1 , maxCapacity - weight[index]);
        }

        int exclude = 0 + solveRecursive(weight , value , index-1 , maxCapacity);
        return max(include , exclude);
    }



    int solveMemo(vector<int> weight, vector<int> value, int index, int maxCapacity , vector<vector<int>>&dp){
        if(index == 0){
            if(weight[0] <= maxCapacity){
                return value[0];
            }
            else{
                return 0;
            }
        }
        
        if(dp[index][maxCapacity] != -1){
            return dp[index][maxCapacity];
        }

        int include = 0;
        if(weight[index] <= maxCapacity){
            include =value[index] + solveMemo(weight , value , index-1 , maxCapacity - weight[index] , dp);
        }

        int exclude = 0 + solveMemo(weight , value , index-1 , maxCapacity , dp);

        dp[index][maxCapacity] = max(include , exclude);
        return dp[index][maxCapacity];
    }



    int solveTabulation(vector<int>weight , vector<int>value , int index , int maxCapacity){
        // step 1 , create a 2D D.P
        vector<vector<int>>dp(index , vector<int>(maxCapacity + 1 , 0));

        // step 2 , initialize base case
        for(int w = weight[0] ; w <= maxCapacity ; w++){
            if(weight[0] <= maxCapacity){
                dp[0][w] = value[0];
            }
            // reduntant , as everything in DP is initially 0
            else{
                dp[0][w] = 0;
            }
        }

        // step 3 , fill rest of the DP
        for(int i = 1 ; i<index ; i++){ // index
            for(int j = 0 ; j<=maxCapacity ; j++){ // maxCapacity
                int include = 0;
                if(weight[i] <= j){
                    include = value[i] + dp[i-1][j - weight[i]];
                }

                int exclude = 0 + dp[i-1][j];

                dp[i][j] = max(include , exclude);
            }
        }
        return dp[index-1][maxCapacity];
    }



    int solveOptimized(vector<int>weight , vector<int>value , int index , int maxCapacity){
        // step1 , initialize vectors
        vector<int>prev(maxCapacity + 1 , 0);
        vector<int>curr(maxCapacity + 1 , 0);

        // step 2 , initialize base case
        for(int w = weight[0] ; w <= maxCapacity ; w++){
            if(weight[0] <= maxCapacity){
                prev[w] = value[0];
            }
            // reduntant , as everything in DP is initially 0
            else{
                prev[w] = 0;
            }
        }

        // step 3 , fill rest of the DP
        for(int i = 1 ; i<index ; i++){ // index
            for(int j = 0 ; j<=maxCapacity ; j++){ // maxCapacity
                int include = 0;
                if(weight[i] <= j){
                    include = value[i] + prev[j - weight[i]];
                }

                int exclude = 0 + prev[j];

                curr[j] = max(include , exclude);
            }
            prev = curr;
        }

        return prev[maxCapacity];

    }


    int solveOptimizedMore(vector<int>weight , vector<int>value , int index , int maxCapacity){
        // step1 , initialize vectors
        vector<int>prev(maxCapacity + 1 , 0);
        // vector<int>curr(maxCapacity + 1 , 0);

        // step 2 , initialize base case
        for(int w = weight[0] ; w <= maxCapacity ; w++){
            if(weight[0] <= maxCapacity){
                prev[w] = value[0];
            }
            // reduntant , as everything in DP is initially 0
            else{
                prev[w] = 0;
            }
        }

        // step 3 , fill rest of the DP
        for(int i = 1 ; i<index ; i++){ // index
            for(int j = maxCapacity ; j >= 0 ; j--){ // maxCapacity
                int include = 0;
                if(weight[i] <= j){
                    include = value[i] + prev[j - weight[i]];
                }

                int exclude = 0 + prev[j];

                prev[j] = max(include , exclude);
            }
            // prev = curr;
        }

        return prev[maxCapacity];

    }



    public:

    // // using recursion 
    // int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){
    //     return solveRecursive(weight , value , n-1 , maxWeight);
    // }

    // // using Memoization
    // int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){
    //     vector<vector<int>> dp (n , vector<int>(maxWeight + 1 , -1));
    //     return solveMemo(weight , value , n-1 , maxWeight , dp);
    // }

    // // using Tabulation
    // int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){
    //     return solveTabulation(weight , value , n , maxWeight);
    // }

    // // using space Optimized approach
    // int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){
    //     return solveOptimized(weight , value , n , maxWeight);
    // }

    // using space More Optimized approach , using only one 1D vector for DP
    int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){
        return solveOptimizedMore(weight , value , n , maxWeight);
    }
};

int main(){
    vector<int>weight = {1,5,6,9,7,9,7};
    vector<int>value = {1,7,1,5,1,7,7};
    int n = 7;
    int maxWeight = 37;
    // ans should be 28

    

    Solution obj;

    int ans = obj.knapsack(weight , value , n , maxWeight);

    cout<<"answer is : "<<ans<<endl;

    return 0;
}