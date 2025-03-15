#include<bits/stdc++.h>
using namespace std;


class Solution{

    bool solveRecursive(vector<int>stones , int box1 , int box2 , int index){
        if(index == stones.size()){
            return box1 == box2;
        }

        bool opt1 = solveRecursive(stones , box1 + stones[index] , box2 , index + 1);
        bool opt2 = solveRecursive(stones , box1 , box2 + stones[index] , index + 1);

        return opt1 || opt2;
    }

    bool solveDP(vector<int>stones){
        int sum = accumulate(stones.begin() , stones.end() , 0);

        if(sum % 2 != 0){
            return false;
        }

        int target = sum / 2;

        vector<bool>dp(target + 1 , false);
        dp[0] = true;

        for(auto stone : stones){
            for(int j = target ; j >= stone ; --j){
                dp[j] = dp[j] || dp[j - stone];
            }
        }

        return dp[target];
    }

    public:
    bool isPossible(vector<int>stones){
        int box1 = 0 , box2 = 0 , index = 0;
        // return solveRecursive(stones , box1 , box2 , index);
        return solveDP(stones);
    }
};

int main(){
    vector<int>stones = {2,3,4,9};
    Solution obj;
    bool ans = obj.isPossible(stones);

    (ans) ? cout<<"TRUE"<<endl : cout<<"FALSE"<<endl;
    return 0;
    
}