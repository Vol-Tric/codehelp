// wildcard pattern matching
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool solveRecursive(string &s , string &p , int i , int j){
        // 3 base cases (imp for this question)
        if(i < 0 && j < 0){ // both string and pattern are fully consumed
            return true;
        }
        if(i >= 0 && j < 0){ // string not consumed but pattern is fully consumed
            return false;
        }
        if(i < 0 && j >= 0){ // string consumed but pattern not consumed
            // 2 cases arise
            // 1st that some character is left in the pattern , (in that case return false)
            // 2nd only * is left in the pattern (in that case , * can be replace by empty string and the ans would be true)
            // for this we will traverse the left section of pattern
            for(int k = 0 ; k<=j ; k++){
                if(p[k] != '*'){
                    return false;
                }
            }
            return true;
        }


        // match
        if(p[j] == '?' || s[i] == p[j]){
            return solveRecursive(s , p , i-1 , j-1);
        }
        // '*'
        else if(p[j] == '*'){
            return (solveRecursive(s , p , i-1 , j) || solveRecursive(s , p , i , j-1));
        }
        else{
            return false;
        }
    }

    bool solveMemo(string &s , string &p , int i , int j , vector<vector<int>>&dp){
        // 3 base cases (imp for this question)
        if(i < 0 && j < 0){ // both string and pattern are fully consumed
            return 1;
        }
        if(i >= 0 && j < 0){ // string not consumed but pattern is fully consumed
            return 0;
        }
        if(i < 0 && j >= 0){ // string consumed but pattern not consumed
            // 2 cases arise
            // 1st that some character is left in the pattern , (in that case return false)
            // 2nd only * is left in the pattern (in that case , * can be replace by empty string and the ans would be true)
            // for this we will traverse the left section of pattern
            for(int k = 0 ; k<=j ; k++){
                if(p[k] != '*'){
                    return 0;
                }
            }
            return 1;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 0;
        // match
        if(p[j] == '?' || s[i] == p[j]){
            ans = solveMemo(s , p , i-1 , j-1 , dp);
        }
        // '*'
        else if(p[j] == '*'){
            ans = (solveMemo(s , p , i-1 , j , dp) || solveMemo(s , p , i , j-1 , dp));
        }
        else{
            ans = 0;
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    // 1 based indexing for Tabulation method
    bool solveTabulation(string &s , string &p){
        int len1 = s.length();
        int len2 = p.length();
        vector<vector<bool>>dp(len1 + 1 , vector<bool>(len2 + 1 , false));

        // base case 1
        dp[0][0] = true;
        // base case 2
        for(int j = 1 ; j <= len2 ; j++){
            bool flag = true;
            for(int k = 1 ; k<=j ; k++){
                if(p[k-1] != '*'){
                    flag = false;   
                    break;
                }
            }
            dp[0][j] = flag;
        }

        for(int i = 1 ; i <= len1 ; i++){
            for(int j = 1 ; j <= len2 ; j++){
                bool ans = false;
                // match
                if(p[j-1] == '?' || s[i-1] == p[j-1]){
                    ans = dp[i-1][j-1];
                }
                // '*'
                else if(p[j-1] == '*'){
                    ans = (dp[i-1][j] || dp[i][j-1]);
                }
                else{
                    ans = false;
                }
                dp[i][j] = ans;   
            }
        }
        return dp[len1][len2];
    }

    bool solveSpaceOptimized(string &s , string &p){
        int len1 = s.length();
        int len2 = p.length();

        vector<bool>curr(len2 + 1 , false); //dp[i+1]
        vector<bool>prev(len2 + 1 , false); // dp[i]

        // base case 1
        prev[0] = true;
        // base case 2
        for(int j = 1 ; j <= len2 ; j++){
            bool flag = true;
            for(int k = 1 ; k<=j ; k++){
                if(p[k-1] != '*'){
                    flag = false;   
                    break;
                }
            }
            prev[j] = flag;
        }

        for(int i = 1 ; i <= len1 ; i++){
            for(int j = 1 ; j <= len2 ; j++){
                bool ans = false;
                // match
                if(p[j-1] == '?' || s[i-1] == p[j-1]){
                    ans = prev[j-1];
                }
                // '*'
                else if(p[j-1] == '*'){
                    ans = (prev[j] || curr[j-1]);
                }
                else{
                    ans = false;
                }
                curr[j] = ans;   
            }
            prev = curr;
        }
        return prev[len2];
    }
public:
    // // using recursion
    // bool isMatch(string s, string p) {
    //     return solveRecursive(s , p , s.length() - 1 , p.length() - 1);
    // }

    // // using Memoization
    // bool isMatch(string s, string p) {
    //     int len1 = s.length();
    //     int len2 = p.length();
    //     vector<vector<int>>dp(len1 + 1 , vector<int>(len2 + 1 , -1));
    //     return solveMemo(s , p , len1 - 1 , len2 - 1 , dp);
    // }

    // // using Tabulation
    // bool isMatch(string s, string p) {
    //     return solveTabulation(s , p);
    // }

    // using Space optimized approach
    bool isMatch(string s, string p) {
        return solveSpaceOptimized(s , p);
    }
};

int main(){
    string s = "aa";
    string p = "*";

    Solution obj;
    bool ans = obj.isMatch(s , p);
    (ans) ? cout<<"True"<<endl : cout<<"False"<<endl;
    return 0;
}