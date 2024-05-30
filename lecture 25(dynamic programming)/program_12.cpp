// minimum cost of tickets
#include<bits/stdc++.h>
using namespace std;


class Solution {
    int solveRecursive(int n , vector<int>days , vector<int>costs , int index){

        // base case
        if(index >= n){
            return 0;
        }

        // 1 day pass
        int option1 = costs[0] + solveRecursive(n , days , costs , index + 1); 

        // 7 days pass
        int i = 0;
        for(i = index ; i<n && days[i]<days[index] + 7 ; i++);
        // here i is now index + 7
        int option2 = costs[1] + solveRecursive(n , days , costs , i);

        // 30 days pass
        i = 0;
        for(i = index ; i<n && days[i]<days[index] + 30 ; i++);
        // here i is now index + 30
        int option3 = costs[2] + solveRecursive(n , days , costs , i);

        return min(option1 , min(option2 , option3));
    }



    int solveMemo(int n , vector<int>days , vector<int>costs , int index , vector<int>dp){

        // base case
        if(index >= n){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        // 1 day pass
        int option1 = costs[0] + solveRecursive(n , days , costs , index + 1); 

        // 7 days pass
        int i = 0;
        for(i = index ; i<n && days[i]<days[index] + 7 ; i++);
        // here i is now index + 7
        int option2 = costs[1] + solveRecursive(n , days , costs , i);

        // 30 days pass
        i = 0;
        for(i = index ; i<n && days[i]<days[index] + 30 ; i++);
        // here i is now index + 30
        int option3 = costs[2] + solveRecursive(n , days , costs , i);

        dp[index] = min(option1 , min(option2 , option3));
        return dp[index];
    }


    int solveTabulation(int n , vector<int>days , vector<int>costs , int index){
        vector<int>dp(n+1 , INT_MAX);
        // base case
        if(index >= n){
            return 0;
        }

        dp[n] = 0;

        for(int k = n-1 ; k>=0 ; k--){
           // 1 day pass
            int option1 = costs[0] + dp[k+1]; 

            // 7 days pass
            int i = 0;
            for(i = k ; i<n && days[i]<days[k] + 7 ; i++);
            // here i is now index + 7
            int option2 = costs[1] + dp[i];

            // 30 days pass
            i = 0;
            for(i = k ; i<n && days[i]<days[k] + 30 ; i++);
            // here i is now index + 30
            int option3 = costs[2] + dp[i]; 

            dp[k] = min(option1 , min(option2 , option3));
        }
        return dp[index];
    }


    int solveSpaceOptimized(int n , vector<int>days , vector<int>costs , int index){
        queue<pair<int , int>>monthly;
        queue<pair<int , int>>weekly;

        int ans = 0;

        for(auto day : days){
            // step 1
            while(!monthly.empty() && monthly.front().first + 30 <= day){
                monthly.pop();
            }
            while(!weekly.empty() && weekly.front().first + 7 <= day){
                weekly.pop();
            }

            // step 2
            weekly.push(make_pair(day , ans + costs[1]));
            monthly.push(make_pair(day , ans + costs[2]));

            // step 3;
            ans = min(ans + costs[0] , min(monthly.front().second , weekly.front().second));
        }
        return ans;
    }
public:
    // // using recursive
    // int mincostTickets(vector<int>& days, vector<int>& costs) {
    //     int n = days.size();
    //     return solveRecursive(n , days , costs , 0);
    // }

    // // using memoization
    // int mincostTickets(vector<int>& days, vector<int>& costs) {
    //     int n = days.size();
    //     vector<int>dp(n+1 , -1);
    //     return solveMemo(n , days , costs , 0 , dp);
    // }

    // // using recursive
    // int mincostTickets(vector<int>& days, vector<int>& costs) {
    //     int n = days.size();
    //     return solveTabulation(n , days , costs , 0);
    // }

    // using space Optimized
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        return solveSpaceOptimized(n , days , costs , 0);
    }
};

int main(){
    vector<int>days = {1,4,6,7,8,20};
    vector<int>costs = {2,7,15};
    // ans should be 11
    Solution obj;
    int ans = obj.mincostTickets(days , costs);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}