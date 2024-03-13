// pivot element
// a sorted array is taken and some of the elements at the end are taken and inserted at the beginnning,
// arr[]={1,2,3,4,6,7,9}
// arr[]={7,9,1,2,3,4,6}
// here the pivot elements are 9 or 1 (some consider it to be 9 and some 1) both are correct
// this particular program gives out the index position of the pivot, the pivot element and the next element as it is also considered as the pivot element

#include<iostream>
using namespace std;
int pivot_element(int arr[],int n){
    int start=0;
    int end=n-1;
    int mid=start+(end-start)/2;
    while(start<=end){
        if(arr[mid]<arr[mid-1]&&arr[mid]<arr[mid+1]){
            return mid;
        }
        else if(arr[mid]>arr[mid-1]&&arr[mid]<arr[mid+1]){
            end=mid;
        }
        else{
            start=mid+1;
        }
        mid=start+(end-start)/2;
    }
    return -1;
}
int main(){
    int arr[20];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int pivot=pivot_element(arr,n);
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