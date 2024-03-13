// first and last occurance 
#include<iostream>
using namespace std;
int first_occ(int arr[], int n, int k){
    int start=0,end=n-1;
    int ans=-1;
    int mid=start+(end-start)/2;
    while(start<=end){
        if(arr[mid]==k){
            ans=mid;
            end=mid-1;

        }
        else if(k<arr[mid]){
            end=mid-1;

        }
        else{
            start=mid+1;
        }
        mid=start+(end-start)/2;
    }
    return ans;
}

int last_occ(int arr[], int n, int k){
    int start=0,end=n-1;
    int ans=-1;
    int mid=start+(end-start)/2;
    while(start<=end){
        if(arr[mid]==k){
            ans=mid;
            start=mid+1;

        }
        else if(k<arr[mid]){
            end=mid-1;

        }
        else{
            start=mid+1;
        }
        mid=start+(end-start)/2;
    }
    return ans;
}

int main(){
    int arr1[6]={0,1,1,1,1,2};
    int arr2[8]={0,0,1,1,2,3,3,3};
    int first,last;
    first=first_occ(arr1,6,1);
    last=last_occ(arr1,6,1);
    cout<<first<<endl;
    cout<<last<<endl;
    
    first=first_occ(arr2,8,3);
    last=last_occ(arr2,8,3);
    cout<<first<<endl;
    cout<<last<<endl;
    return 0;
}