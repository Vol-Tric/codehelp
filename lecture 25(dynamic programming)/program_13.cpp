// maximum square sub matrix
#include<bits/stdc++.h>
using namespace std;

class Solution{
    int solveRecursive(vector<vector<int>>&mat , int i , int j , int &maxi){
        // base case
        if(i >=mat.size() || j >= mat[0].size()){
            return 0;
        }

        int right = solveRecursive(mat , i , j+1 , maxi);
        int diagonal = solveRecursive(mat , i+1 , j+1 , maxi);
        int down = solveRecursive(mat , i+1 , j , maxi);

        if(mat[i][j] == 1){
            int ans = 1 + min(right , min(diagonal , down));
            maxi = max(ans , maxi);
            return ans;
        }
        else{
            return 0;
        }   
    }
    


    int solveMemo(vector<vector<int>>&mat , int i , int j , int &maxi , vector<vector<int>>&dp){
        // base case
        if(i >=mat.size() || j >= mat[0].size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int right = solveMemo(mat , i , j+1 , maxi , dp);
        int diagonal = solveMemo(mat , i+1 , j+1 , maxi , dp);
        int down = solveMemo(mat , i+1 , j , maxi , dp);

        if(mat[i][j] == 1){
            dp[i][j] = 1 + min(right , min(diagonal , down));
            maxi = max(dp[i][j] , maxi);
            return dp[i][j];
        }
        else{
            return 0;
        } 
    }


    int solveTabulation(vector<vector<int>>&mat , int n , int m , int &maxi){
        vector<vector<int>>dp(n+1 , vector<int>(m+1 , 0));

        for(int i = n-1 ; i>=0 ; i--){
            for(int j = m-1 ; j>=0 ; j--){
                int right = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int down = dp[i+1][j];

                if(mat[i][j] == 1){
                    dp[i][j] = 1 + min(right , min(diagonal , down));
                    maxi = max(dp[i][j] , maxi);
                    
                }
                else{
                    dp[i][j] = 0;
                }    
            }
        }
        return dp[0][0];
    }

    // S.C = O(m)
    int solveSpaceOptimized(vector<vector<int>>&mat , int n , int m , int &maxi){
        vector<int>curr(m+1 , 0);
        vector<int>next(m+1 , 0);
        // dp[i] is curr , dp[i+1] is next

        for(int i = n-1 ; i>=0 ; i--){
            for(int j = m-1 ; j>=0 ; j--){
                int right = curr[j+1];
                int diagonal = next[j+1];
                int down = next[j];

                if(mat[i][j] == 1){
                    curr[j] = 1 + min(right , min(diagonal , down));
                    maxi = max(curr[j] , maxi);
                    
                }
                else{
                    curr[j] = 0;
                }    
            }
            next = curr;

        }
        return next[0];
    }


    int solveSpaceOptimizedMore(vector<vector<int>>&mat , int n , int m , int &maxi){
        // vector<int>curr(m+1 , 0);
        // vector<int>next(m+1 , 0);
        int one = 0; // curr[j]
        int two = 0; //curr[j+1]
        int three = 0; //next[j]
        int four = 0;  //next[j+1]
        // dp[i] is curr , dp[i+1] is next

        for(int i = n-1 ; i>=0 ; i--){
            for(int j = m-1 ; j>=0 ; j--){
                int right = two;
                int diagonal = four;
                int down = three;

                if(mat[i][j] == 1){
                    one = 1 + min(right , min(diagonal , down));
                    maxi = max(one , maxi);
                    
                }
                else{
                    one = 0;
                }    
            }
            // three = one; four = two;
            two = one ; three = four;
            // four = one ; three = two;

        }
        return one;
    }
public:
    // // using recursion
    // int maxSquare(int n, int m, vector<vector<int>> mat){
    //     int maxi = 0;
    //     solveRecursive(mat , 0 , 0 , maxi);
    //     return maxi;
    // }

    // // using memoization
    // int maxSquare(int n, int m, vector<vector<int>> mat){
    //     int maxi = 0;
    //     vector<vector<int>>dp(n , vector<int>(m , -1));
    //     solveMemo(mat , 0 , 0 , maxi , dp);
    //     return maxi;
    // }

    // // using Tabulation
    // int maxSquare(int n, int m, vector<vector<int>> mat){
    //     int maxi = 0;
    //     solveTabulation(mat , n , m , maxi);
    //     return maxi;
    // }

    // using Space optimized
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi = 0;
        solveSpaceOptimized(mat , n , m , maxi);
        return maxi;
    }  

    // // using More Space optimized
    // int maxSquare(int n, int m, vector<vector<int>> mat){
    //     int maxi = 0;
    //     solveSpaceOptimizedMore(mat , n , m , maxi);
    //     return maxi;
    // }  
};

int main(){
    vector<vector<int>>mat;
    int m = 4;
    int n = 4;
    int temp[4][4] = {{1,1,1,1} , {1,1,1,1} , {1,1,1,1} , {1,1,1,1}};
    for(int i = 0 ; i<m ; i++){
        vector<int>arr;
        for(int j = 0 ; j<m ; j++){
            arr.push_back(temp[i][j]);
        }
        mat.push_back(arr);
    }

    Solution obj;
    int ans = obj.maxSquare(n , m , mat);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}