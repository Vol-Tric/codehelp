// kth largest sum subarray

#include<bits/stdc++.h>
using namespace std;

// approach 1
int KthLargest_1(vector<int>&arr, int k){
    vector<int>ans;

    for(int i=0;i<arr.size();i++){
        int sum=0;
        for(int j=i;j<arr.size();j++){
            sum += arr[j];
            ans.push_back(sum);
        }
    }
    sort(ans.begin(), ans.end()); 

    // as the sorting is done in ascending order
    return ans[ans.size()-k];
}

// approach 2
int KthLargest_2(vector<int>&arr, int k){
    priority_queue<int ,vector<int> ,greater<int>> minheap;
    int n = arr.size();
    for(int i=0; i<n;i++){
        int sum =0;
        for(int j=i ; j<n ; j++){
            sum += arr[j];
            if(minheap.size()<k){
                minheap.push(sum);
            }
            else{
                if(sum > minheap.top()){
                    minheap.pop();
                    minheap.push(sum);
                }
            }
        }
    }

    return minheap.top();
}

int main(){
    vector<int>arr;
    arr.push_back(1);
    arr.push_back(-2);
    arr.push_back(3);
    arr.push_back(-4);
    arr.push_back(5);
    int k=2;

    int ans=0;
    ans = KthLargest_1(arr,k);
    cout<<"answer by first method "<<ans<<endl;
    ans = KthLargest_2(arr,k);
    cout<<"answer by second method "<<ans<<endl;
    return 0;


}