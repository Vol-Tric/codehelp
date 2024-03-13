// check if given array is sorted using recursion
#include<iostream>
using namespace std;

bool checkSorted(int arr[],int size){
    // base case
    if(size==0 || size==1){
        return true;
    }
    // process
    else if(arr[0]>arr[1]){
        return false;
    }
    // reccurance relation
    else{
        return checkSorted(arr+1,size-1);
    }
}

int main(){
    int arr[10]={1,2,3,4,5,7,6,8,9,10};
    int size=sizeof(arr)/sizeof(arr[0]);
    bool ans=checkSorted(arr,size);
    cout<<ans<<endl;
    return 0;
}