// peak mountain using recursion
#include<iostream>
using namespace std;
int peak_mountain(int arr[],int start, int end){
    // base case
    if(start>end){
        return -1;
    }

    // process
    int mid=(start+(end-start)/2);
    if(arr[mid]>arr[mid+1]&&arr[mid]>arr[mid-1]){
        return arr[mid];

    }

    // recursive relation
    else if(arr[mid]<arr[mid+1]&&arr[mid]>arr[mid-1]){
        return peak_mountain(arr,mid+1,end);

    }
    else if(arr[mid]>arr[mid+1]&&arr[mid]<arr[mid-1]){
        return peak_mountain(arr,start,mid-1);
    }
    else{
        return -1;
    }
    
}
int main(){
    int arr[8]={1,2,3,4,7,4,3,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    int peak=peak_mountain(arr,0,size);
    cout<<"answer "<<peak<<endl;
    return 0;
    
}