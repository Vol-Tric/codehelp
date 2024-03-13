// pivot element using recursion
// a sorted array is taken and some of the elements at the end are taken and inserted at the beginnning,
// arr[]={1,2,3,4,6,7,9}
// arr[]={7,9,1,2,3,4,6}
// here the pivot elements are 9 or 1 (some consider it to be 9 and some 1) both are correct
// this particular program gives out the index position of the pivot, the pivot element and the next element as it is also considered as the pivot element
// considring pivot as 1

#include<iostream>
using namespace std;
int pivot_element(int arr[],int start,int end){
    // base case
    if(start>end){
        return -1;
    }
    // process
    int mid=start+(end-start)/2;
    if(arr[mid]<arr[mid-1]&&arr[mid]<arr[mid+1]){
        return mid;
    }
    // reccurance relation
    else if(arr[mid]>arr[mid-1]&&arr[mid]<arr[mid+1]){
        return pivot_element(arr,start,mid-1);
    }
    else{
        return pivot_element(arr,mid+1,end);
    }
    
    
}
int main(){
    int arr[7]={7,9,1,2,3,4,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    
    int pivot=pivot_element(arr,0,size);
    cout<<"ans"<<endl;
    
    if(pivot!=-1){
        cout<<"pivot exist"<<endl;
        cout<<arr[pivot]<<endl<<arr[pivot-1];
    }
    else{
        cout<<"pivot doesn't exist";
    }
    
    return 0;
}