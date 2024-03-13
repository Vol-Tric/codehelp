// max rectangle area in binary matrix
// Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.
// Input:
// n = 4, m = 4
// M[][] = {{0 1 1 0},
//          {1 1 1 1},
//          {1 1 1 1},
//          {1 1 0 0}}
// Output: 8
// Explanation: For the above test case the
// matrix will look like
// 0 1 1 0
// 1 1 1 1
// 1 1 1 1
// 1 1 0 0
// the max size rectangle is 
// 1 1 1 1
// 1 1 1 1
// and area is 4 *2 = 8.
#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    vector<int> nextSmallerElement(vector<int> &arr, int n){
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

    vector<int> prevSmallerElement(vector<int> &arr, int n){
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
    
    int largestRectangleArea(vector<int> &heights, int n) {
        // int n=heights.size();

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
  public:
    int maxArea(vector<vector<int>> &M, int n, int m) {
        
        //compute area for first row
        int area = largestRectangleArea(M[0], m);
        
        for(int i = 1; i<n; i++) {
            for(int j = 0; j<m; j++) {
                
                //row udpate: by adding previous row's value
                if(M[i][j] != 0)
                    M[i][j] = M[i][j] + M[i-1][j];
                else
                    M[i][j] = 0;
            }
            
            //entire row is updated now
            area = max(area, largestRectangleArea(M[i],m));
            
        }
        return area;
    }
};

int main(){
    int n;
    cin>>n;
    
    vector<vector<int>> M(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>M[i][j];
        }
    }

    Solution s1;
    cout<<"max area is: "<<s1.maxArea(M,n,n);
    return 0;
}