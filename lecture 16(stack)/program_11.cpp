// next smaller element
// You are given an array 'ARR' of integers of length N. Your task is to find the next smaller element for each of the array elements.
// Next Smaller Element for an array element is the first element to the right of that element which has a value strictly smaller than that element.
// If for any array element the next smaller element does not exist, you should print -1 for that array element.

// For Example:
// If the given array is [ 2, 3, 1], we need to return [1, 1, -1]. Because for  2, 1 is the Next Smaller element. For 3, 1 is the Next Smaller element and for 1, there is no next smaller element hence the answer for this element is -1.


#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n){
    vector<int>ans(n);

    stack<int> stk;
    stk.push(-1);

    for(int i=(n-1) ; i>=0 ; i--){
        int curr=arr[i];

        while(stk.top() >= curr){
            stk.pop();
        }
        ans[i] = stk.top();
        stk.push(curr);

    }
    return ans;

}

int main(){
    vector<int>v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);

    vector<int>ans=nextSmallerElement(v,4);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}