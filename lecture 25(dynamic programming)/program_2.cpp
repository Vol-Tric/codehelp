// minimum cost climbing stairs
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // recursive
    int MCclimbingStairs(vector<int>&cost , int num){
        if(num == 0 || num == 1){
            return min(cost[num] , cost[num-1]);
        }
        return cost[num] + min(MCclimbingStairs(cost , num-1) , MCclimbingStairs(cost , num-2));
    }

    // top down DP
    int MCstairs_TopDown(vector<int>&cost , int num , vector<int>&dp){
        if(num == 0 || num == 1){
            return cost[num];
        }
        if(dp[num] != -1){
            return dp[num];
        }

        dp[num] =  cost[num] + min(MCclimbingStairs(cost , num-1) , MCclimbingStairs(cost , num-2));

        return dp[num];
    }
    // bottom up DP
    int MCStairs_BottomUp(vector<int>&cost , int num){
        int n = cost.size();
        vector<int>dp(n+1 , -1);
        if(num == 0 || num == 1){
            return min(cost[num] , cost[num-1]);
        }
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for(int i=2 ; i<=num ; i++){
            dp[i] = cost[i] + min(dp[i-1] , dp[i-2]);
        }

        return min(dp[num] , dp[num-1]);
    }

    // space optimized
    int MCStairs_optimized(vector<int>&cost , int num){
        if(num == 0 || num == 1){
            return min(cost[num] , cost[num-1]);
        }

        int first = cost[0];
        int second = cost[1];
        int sum = 0;
        for(int i=2 ; i<=num ; i++){
            sum = cost[i] + min(first , second);
            first = second;
            second = sum;
        }
        return min(first , second);
    }
};

int main(){
    Solution obj;
    int arr[10] = {1,100,1,1,1,100,1,1,100,1};
    int num = 9;
    vector<int>cost;
    for(auto i : arr){
        cost.push_back(i);
    }

    vector<int>dp(num+1 , -1);
    
    int ans = 0;
    ans = obj.MCclimbingStairs(cost , num);
    cout<<"answer , recursive : "<<ans<<endl;

    ans = obj.MCstairs_TopDown(cost , num , dp);
    cout<<"answer , top down : "<<ans<<endl;

    ans = obj.MCStairs_BottomUp(cost , num);
    cout<<"answer , bottom up : "<<ans<<endl;

    ans = obj.MCStairs_optimized(cost , num);
    cout<<"answer , optimized : "<<ans<<endl;

    return 0;
}