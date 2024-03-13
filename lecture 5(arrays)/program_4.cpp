// reverse an array using for loop
// using another array
#include<iostream>
using namespace std;
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void reverse(int arr[],int n){
    int arr2[n];
    for(int i=0;i<n;i++){
        arr2[i]=arr[n-i-1];
    }
    print(arr2,n);
}
int main(){
    int array1[5]={1,2,3,45,5};
    int array2[8]={99,88,77,66,55,44,33,22};

    reverse(array1,5);
    cout<<endl;
    reverse(array2,8);
    cout<<endl;
    return 0;
}