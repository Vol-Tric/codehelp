// linear search using recursion
#include<iostream>
using namespace std;

bool linearSearch(int arr[],int size,int key){
    // base case
    if(size==0){
        return false;
    }
    // process
    if(arr[0]==key){
        return true;
    }
    // reccurance relation
    return linearSearch(arr+1,size-1,key);
}

int main(){
    int arr[10]={1,2,3,4,5,7,6,8,9,10};
    int size=sizeof(arr)/sizeof(arr[0]);
    int key=11;
    bool ans=linearSearch(arr,size,key);
    cout<<ans<<endl;
    return 0;
}