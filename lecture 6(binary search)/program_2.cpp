// binary search without reccursion
// this method is useful to find the index position of the searced element as it is not possible to find it in reccursion
// mid=(start+end)/2 is equal to mid=(start+(end-start)/2)
#include<iostream>
using namespace std;
int binary_search(int array[],int size,int key){
    int start=0;
    int end=size-1;
    int mid=(start+(end-start)/2);
    while(start<=end){
        if(array[mid]==key){
            return mid;
        }
        else if(key>array[mid]){
            start=mid+1;

        }
        else{
            end=mid-1;
        }
        mid=(start+(end-start)/2);
    }
    return -1;
}

int main(){
    int arr1[5]={1,3,5,7,9};
    int arr2[8]={1,2,3,4,5,6,7,80};

    int ans;
    ans=binary_search(arr1,5,7);
    cout<<ans<<endl;
    ans=binary_search(arr2,8,34);
    cout<<ans<<endl;
    return 0;
}