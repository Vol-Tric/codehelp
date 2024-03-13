// heapify
#include<bits/stdc++.h>
using namespace std;

// this heapify is based on 1 place indexing
void heapify(int arr[] , int n , int i){
    int largest = i;
    int leftChild = 2*i;
    int rightChild = 2*i + 1;

    if(leftChild <= n && arr[largest] < arr[leftChild]){
        largest = leftChild;
    }

    if(rightChild <= n && arr[largest] < arr[rightChild]){
        largest = rightChild;
    }

    if(largest != i){
        swap(arr[largest] , arr[i]);
        heapify(arr , n, largest);
    }
}

// // this heapify is based on 0 place indexing
// void heapify(int arr[] , int n , int i){
//     int largest = i;
//     int leftChild = 2*i + 1;
//     int rightChild = 2*i + 2;

//     if(leftChild < n && arr[largest] < arr[leftChild]){
//         largest = leftChild;
//     }

//     if(rightChild < n && arr[largest] < arr[rightChild]){
//         largest = rightChild;
//     }

//     if(largest != i){
//         swap(arr[largest] , arr[i]);
//         heapify(arr , n, largest);
//     }
// }

int main(){
    int arr[6] = {-1,54,53,55,52,50};
    int n=6;
    int i=1;
    // for 1 based indexing
    for(int i = n/2 ; i>0 ; i--){
        heapify(arr,n,i);
    }

    // // for 0 based indexing
    // for(int i = n/2 -1  ; i>=0 ; i--){
    //     heapify(arr,n,i);
    // }
    
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}