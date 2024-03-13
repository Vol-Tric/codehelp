// sum of elements of array using recursion
#include<iostream>
using namespace std;

int sumArray(int arr[],int size,int sum){
    // base case
    if(size==0){
        return sum;
    }
    // process
    sum+=arr[0];
    // reccurance relation
    return sumArray(arr+1,size-1,sum);
}

int main(){
    int arr[10]={1,2,3,4,5,7,6,8,9,10};
    int size=sizeof(arr)/sizeof(arr[0]);
    int sum=0;
    int ans=sumArray(arr,size,sum);
    cout<<ans<<endl;
    return 0;
}