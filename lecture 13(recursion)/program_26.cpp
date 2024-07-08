// predict winner on circular game
// josephus algorithm

// the recursive algo is 
// solve(n,k) = solve(n-1 , k) + k . and if this value is greater than n , then ans % n.
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solveRecursive(int n , int k){
        if(n == 1){
            return 0;
        }

        return (solveRecursive(n-1 , k) + k) % n;
    }
public:
    int findTheWinner(int n, int k) {
        // +1 because the answer returned os after mod and mod is always 0 based indexing
        return solveRecursive(n , k) + 1;
    }
};

int main(){
    int n = 5;
    int k = 2;

    Solution obj;
    int ans = obj.findTheWinner(n , k);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}