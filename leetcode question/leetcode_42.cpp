// trapping rain water
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int trap(vector<int>& heights){
        int n = heights.size();

        // pointers for vector
        int left = 0;
        int right = n-1;

        int leftMax = INT_MIN;
        int rightMax = INT_MIN;

        int ans = 0;

        while(left < right){
            leftMax = max(leftMax , heights[left]);
            rightMax = max(rightMax , heights[right]);

            // normal if else statement
            if(leftMax < rightMax){
                ans += leftMax - heights[left++];
            }
            else{
                ans += rightMax - heights[right--];
            }
            
            // // same if else statement using ternary operator
            // ans += (leftMax < rightMax) ? leftMax - heights[left++] : rightMax - heights[right--];

        }
        return ans;
    }
};

int main(){
    Solution obj;

    int arr[12] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = 12;

    vector<int>height(n);
    for(auto i:arr){
        height.push_back(i);
    }

    int ans = obj.trap(height);
    cout<<"ans is: "<<ans<<endl;
    return 0;

}