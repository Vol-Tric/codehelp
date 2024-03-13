// kth smallest element
#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k) {
    
    // create heap
    priority_queue<int> heap;

    

    // step 1 , push first k elements into heap
    for(int i=0;i<=r;i++){
        heap.push(arr[i]);

        if(heap.size() > k){
            heap.pop();
        }
    }
    return heap.top();
    
}

int main(){
    int arr[6]={7, 10, 4, 3, 20, 15};
    int size=6;
    int ans = kthSmallest(arr , 0 , 5 , 3);
    cout<<ans<<endl;
    return 0;
}