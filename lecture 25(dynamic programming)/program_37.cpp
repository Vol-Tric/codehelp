// edit distance (leetcode 72)

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solveRecursive(string& a , string& b , int i , int j){
        // base case
        if(i == a.length()){// a is smaller than b 
            return b.length() - j;
        }
        if(j == b.length()){
            return a.length() - i;
        }
        if(a[i] == b[j]){
            return solveRecursive(a , b , i+1 , j+1);
        }
        
        // insert
        int insertAns = 1 + solveRecursive(a , b, i , j+1);
        // delete
        int deleteAns = 1 + solveRecursive(a, b , i+1 , j);
        // update
        int updateAns = 1 + solveRecursive(a , b , i+1 , j+1);

        int ans = min(insertAns , min(deleteAns , updateAns));

        return ans;
    }

    int solveMemo(string& a , string& b , int i , int j , vector<vector<int>>&dp){
        if(i == a.length()){
            return b.length() - j;
        }
        if(j == b.length()){
            return a.length() - i;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(a[i] == b[j]){
            return solveMemo(a , b , i+1 , j+1 , dp);
        }
        // insert
        int insertAns = 1 + solveMemo(a , b , i , j+1 , dp);
        // delete
        int deleteAns = 1 + solveMemo(a , b , i+1 , j , dp);
        // update
        int updateAns = 1 + solveMemo(a , b , i+1 , j+1, dp);
        

        dp[i][j] = min(insertAns , min(updateAns , deleteAns));
        return dp[i][j];
    }

    int solveTabulation(string& a , string& b){
        int len1 = a.length();
        int len2 = b.length();

        if(len1 == 0){
            return len2;
        }
        if(len2 == 0){
            return len1;
        }
        vector<vector<int>>dp(len1 + 1 , vector<int>(len2 + 1 , 0));
        
        // base case 1
        for(int j=0 ; j<len2 ; j++){
            dp[len1][j] = len2 - j;
        }

        // base case 2
        for(int i=0 ; i<len1 ; i++){
            dp[i][len2] = len1 - i;
        }

        for(int i = len1 - 1 ; i >= 0 ; i--){
            for(int j = len2 - 1 ; j >= 0 ; j--){
               if(a[i] == b[j]){
                    dp[i][j] = dp[i+1][j+1];
                    continue;
                }
                // insert
                int insertAns = 1 + dp[i][j+1];
                // delete
                int deleteAns = 1 + dp[i+1][j];
                // update
                int updateAns = 1 + dp[i+1][j+1];
                
                dp[i][j] = min(insertAns , min(updateAns , deleteAns)); 
            }
        }
        return dp[0][0];
    }

    int solveSpaceOptimized(string& a , string& b){
        int len1 = a.length();
        int len2 = b.length();

        if(len1 == 0){
            return len2;
        }
        if(len2 == 0){
            return len1;
        }

        vector<int>curr(len1 + 1 , 0);//dp[i+1]
        vector<int>prev(len2 + 1 , 0);//dp[i]

        // base case 1
        for(int j=0 ; j<len2 ; j++){
            curr[j] = len2 - j;
        }

        for(int i = len1 - 1 ; i >= 0 ; i--){
            for(int j = len2 - 1 ; j >= 0 ; j--){
                prev[len2] = len1 - i;// base case 2 , most imp part of this question
               if(a[i] == b[j]){
                    prev[j] = curr[j+1];
                    continue;
                }
                // insert
                int insertAns = 1 + prev[j+1];
                // delete
                int deleteAns = 1 + curr[j];
                // update
                int updateAns = 1 + curr[j+1];
                
                prev[j] = min(insertAns , min(updateAns , deleteAns)); 
            }
            curr = prev;
        }
        return prev[0];

    }

public:
    // // using recursion
    // int minDistance(string word1, string word2) {
    //     return solveRecursive(word1 , word2 , 0 , 0);
    // }

    // // using Memoization
    // int minDistance(string word1, string word2) {
    //     int i = word1.length();
    //     int j = word2.length();
    //     vector<vector<int>>dp(i+1 , vector<int>(j+1 , -1));
    //     return solveMemo(word1 , word2 , 0 , 0 , dp);
    // }

    // // using Tabulation
    // int minDistance(string word1, string word2) {
    //     return solveTabulation(word1 , word2);
    // }

    // using Space optimized approach
    int minDistance(string word1, string word2) {
        return solveSpaceOptimized(word1 , word2);
    }
};

int main(){
    string word1 = "horse";
    string word2 = "ros";
    Solution obj;
    int ans = obj.minDistance(word1 , word2);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}