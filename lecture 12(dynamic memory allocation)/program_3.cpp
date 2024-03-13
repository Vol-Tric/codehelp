// allocating memory in internal stack and heap
#include<iostream>
using namespace std;

int getSum(int *arr,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}

int main(){
    int n;
    cin>>n;
    // variable size array
    int *arr=new int[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=getSum(arr,n);
    cout<<sum<<endl;

     
    return 0;
}