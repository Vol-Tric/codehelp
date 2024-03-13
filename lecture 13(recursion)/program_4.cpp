// climbing stairs
// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Example 1:
// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps

#include<iostream>
using namespace std;

    int climbStairs(int n) {
        // base case, no stair exist
        if(n<0){
            return 0;
        }
        // base case, at ground, only one way
        else if(n==0){
            return 1;
        }
        // recurrance relation, only 2 ways possible to reach top, either from stair n-1 or stair n-2
        else{
            return climbStairs(n-1)+climbStairs(n-2);
        }
    }

int main(){
    int n=44;
    int ans=climbStairs(n);
    cout<<ans<<endl;
    return 0;
}