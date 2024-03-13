// binary search using recursion
#include<iostream>
using namespace std;

bool binarySearch(int arr[],int low,int high,int key){
    // base case
    if(low>high){
        return false;
    }
    // process
    int mid=low+(high-low)/2;
    if(arr[mid]==key){
        return true;
    }
    // recursive relation, either of them willbe called
    else if(key>arr[mid]){
        return binarySearch(arr,mid+1,high,key);
    }
    else{
        return binarySearch(arr,low,mid-1,key);
    }
    
}

int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int size=sizeof(arr)/sizeof(arr[0]);
    int key=1;
    bool ans=binarySearch(arr,0,size,key);
    cout<<ans<<endl;
    return 0; 
}