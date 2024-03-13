// // area under a histogram
// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> nextSmallerElement(vector<int>&arr, int n){
        vector<int>ans(n);
        stack<int> stk;
        stk.push(-1);

        for(int i=(n-1) ; i>=0 ; i--){
            int curr=arr[i];
            while(stk.top()!=-1 && arr[stk.top()] >= curr){
                stk.pop();
            }
            ans[i] = stk.top();
            stk.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int>&arr, int n){
        vector<int>ans(n);
        stack<int> stk;
        stk.push(-1);

        for(int i=0;i<n;i++){
            int curr=arr[i];
            while(stk.top()!=-1 && arr[stk.top()] >= curr){
                stk.pop();
            }
            ans[i] = stk.top();
            stk.push(i);
        }
        return ans;   
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();

        vector<int> next(n);
        next=nextSmallerElement(heights, n);

        vector<int> prev(n);
        prev=prevSmallerElement(heights, n);
        int area=INT_MIN;

        for(int i=0;i<n;i++){
            int l=heights[i];
            
            if(next[i]== -1 ){
                next[i]=n;
            }

            int b=next[i] - prev[i] - 1;
            
            int newArea=l*b;
            area=max(area,newArea);
        }
        return area;
    }
};

int main(){
    Solution s1;
    vector<int>heights;
    heights.push_back(2);
    heights.push_back(1);
    heights.push_back(5);
    heights.push_back(6);
    heights.push_back(2);
    heights.push_back(3);

    int ans=s1.largestRectangleArea(heights);
    cout<<"the answer is: "<<ans<<endl;
    return 0;
}