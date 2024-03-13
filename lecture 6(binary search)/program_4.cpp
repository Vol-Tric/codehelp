// peak mountain
#include<iostream>
using namespace std;
int peak_mountain(int arr[],int n){
    int start=0;
        
    int end=n-1;
    int mid=(start+(end-start)/2);
    int ans=-1;
    while(start<=end){
        if(arr[mid]>arr[mid+1]&&arr[mid]>arr[mid-1]){
            return mid;

        }
        else if(arr[mid]<arr[mid+1]&&arr[mid]>arr[mid-1]){
            start=mid+1;

        }
        else if(arr[mid]>arr[mid+1]&&arr[mid]<arr[mid-1]){
            end=mid;
        }
        mid=(start+(end-start)/2);
    }
    return ans;
}
int main(){
    int arr[20];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int peak=peak_mountain(arr,n);
    cout<<"answer"<<peak<<endl;
    return 0;
    
}