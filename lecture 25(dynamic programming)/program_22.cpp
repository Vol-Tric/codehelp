// RTDS interview question
// you have N coins (0 to N-1) , your friend need M number of coins whose sum is K out of N coins. return the number of combination that can be derived
#include<bits/stdc++.h>
using namespace std;

class Solution{
    int solveRecursive(int N , int M , int K , int sum , int counter , int index){
        if(counter == M ){
            return (sum == K) ? 1 : 0;
        }

        if(index == N || sum > K || counter > M){
            return 0;
        }

        int include = solveRecursive(N , M , K , sum + index , counter+1 , index+1);
        int exclude = solveRecursive(N , M , K , sum , counter , index+1);

        return include + exclude;
    }

    int solveDP(int N , int M , int K){
        vector<vector<vector<int>>>dp(N+1 , vector<vector<int>>(M+1 , vector<int>(K+1 , 0)));

        // base case 
        dp[0][0][0] = 1;

        for(int i=1 ; i<=N ; i++){//for denomination
            for(int j=0 ; j<=M ; j++){//for number of coins
                for(int k=0 ; k<=K ; k++){//for sum of coins
                    int exclude = dp[i-1][j][k];
                    int include = 0;
                    if(j > 0 && k >= i-1){
                        include = dp[i-1][j-1][k - (i - 1)];
                    }
                    dp[i][j][k] = include + exclude;
                }
            }
        }
        return dp[N][M][K];
    }
    public:
    int numberOfCoins(int N , int M , int K){
        return solveRecursive(N , M , K , 0 , 0 , 0);
        // return solveDP(N , M , K);
    }
};

int main(){
    int N = 4;
    int M = 2;
    int K = 3;
    // ans should be 2
    Solution obj;
    int ans = obj.numberOfCoins(N , M , K);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}