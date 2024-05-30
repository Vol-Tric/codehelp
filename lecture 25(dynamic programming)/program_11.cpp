// perfect square sum
#include<bits/stdc++.h>
using namespace std;


class Solution{
    int solveRecursive(int num){
        // base case
        if(num == 0){
            return 0;
        }
        int ans = num;
        for(int i=1 ; i*i <= num ; i++){
            int temp = i*i;
            ans = min(ans , 1 + solveRecursive(num - temp));
        }
        return ans;
    }

    int solveMemo(int num , vector<int>&dp){
        // base case
        if(num == 0){
            return 0;
        }
        if(dp[num] != -1){
            return dp[num];
        }
        int ans = num;
        for(int i=1 ; i*i <= num ; i++){
            int temp = i*i;
            ans = min(ans , 1 + solveMemo(num - temp , dp));
        }
        dp[num] = ans;
        return dp[num];
    }

    int solveTabulation(int num){
        vector<int>dp(num+1 , INT_MAX);
        if(num == 0){
            return 0;
        }
        dp[0] = 0;
        for(int i = 1 ; i<=num ; i++){
            for(int j = 1 ; j*j <= i ; j++){
                int temp = j*j;
                dp[i] = min(dp[i] , 1+dp[i - temp]);
            }
        }
        return dp[num];
    }
	public:
    // // using recursion
	// int MinSquares(int n){
	//     return solveRecursive(n);
	// }

    // // using recursion
	// int MinSquares(int n){
    //     vector<int>dp(n + 1 , -1);
	//     return solveMemo(n , dp);
	// }

    // using recursion
	int MinSquares(int n){
	    return solveTabulation(n);
	}
};

int main(){
    int n = 24;
    Solution obj;
    int ans = obj.MinSquares(n);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}