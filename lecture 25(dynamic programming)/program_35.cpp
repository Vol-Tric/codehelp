// longest common subsequence
// leetcode 1143
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solveRecursive(string str1 , string str2 , int i , int j){
        if(i >= str1.length() || j >= str2.length()){
            return 0;
        }
        int ans = 0;
        if(str1[i] == str2[j]){
            ans = 1 + solveRecursive(str1 , str2 , i+1 , j+1);
        }
        else{
            ans = max(solveRecursive(str1 , str2 , i , j+1) , solveRecursive(str1 , str2 , i+1 , j));
        }

        return ans;
    }

    int solveMemo(string str1 , string str2 , int i , int j , vector<vector<int>>&dp){
        if(i >= str1.length() || j >= str2.length()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 0;
        if(str1[i] == str2[j]){
            ans = 1 + solveMemo(str1 , str2 , i+1 , j+1 , dp);
        }
        else{
            ans = max(solveMemo(str1 , str2 , i , j+1 , dp) , solveMemo(str1 , str2 , i+1 , j , dp));
        }

        dp[i][j] = ans;
        return dp[i][j];
    }

    int solveTabulation(string str1 , string str2){
        int len1 = str1.length();
        int len2 = str2.length();

        vector<vector<int>>dp(len1 + 1 , vector<int>(len2 + 1 , 0));

        for(int i = len1-1 ; i >= 0 ; i--){
            for(int j = len2-1 ; j >= 0 ; j--){
                int ans = 0;
                if(str1[i] == str2[j]){
                    ans = 1 + dp[i+1][j+1];
                }
                else{
                    ans = max(dp[i][j+1] , dp[i+1][j]);
                }

                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int solveSpaceOptimized(string str1 , string str2){
        int len1 = str1.length();
        int len2 = str2.length();

        vector<int>curr(len2 + 1 , 0);//index+1
        vector<int>prev(len2 + 1 , 0);//index

        for(int i = len1-1 ; i >= 0 ; i--){
            for(int j = len2-1 ; j >= 0 ; j--){
                int ans = 0;
                if(str1[i] == str2[j]){
                    ans = 1 + curr[j+1];
                }
                else{
                    ans = max(prev[j+1] , curr[j]);
                }

                prev[j] = ans;
            }
            curr = prev;
        }
        return prev[0];
    }

public:

    // // using recursion
    // int longestCommonSubsequence(string text1, string text2) {
    //     return solveRecursive(text1 , text2 , 0 , 0);
    // }

    // // using memoization
    // int longestCommonSubsequence(string text1, string text2) {
    //     int len1 = text1.length();
    //     int len2 = text2.length();
    //     vector<vector<int>>dp(len1 + 1 , vector<int>(len2 + 1 , -1));
    //     return solveMemo(text1 , text2 , 0 , 0 , dp);
    // }

    // // using Tabulation S.C = O(len1 * len2)
    // int longestCommonSubsequence(string text1, string text2) {
    //     return solveTabulation(text1 , text2);
    // }

    // using Space optimized approach S.C = O(len2) or O(min(len1 , len2))
    int longestCommonSubsequence(string text1, string text2) {
        return solveSpaceOptimized(text1 , text2);
    }

    
};

int main(){
    string text1 = "abcde";
    string text2 = "ace";

    Solution obj;
    int ans = obj.longestCommonSubsequence(text1 , text2);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}