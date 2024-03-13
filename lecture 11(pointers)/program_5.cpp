// MCQ Practice
#include<iostream>
using namespace std;

int main(){

    // int first=8;
    // int *p=&first;
    // cout<<(*p)++<<endl;
    // cout<<first<<endl;

    // int arr[5];
    // int *p;
    // cout<<sizeof(arr)<<" "<<sizeof(p)<<endl;
    // // arr is of size 20 only (5x4)

    // int arr[6]={11,21,31,41};
    // cout<<arr<<" "<<&arr<<endl;
    // // both print same address, infact arr, &arr, &arr[0], all print same adress that is starting address of the array

    // int arr[6]={11,21,31,41};
    // int *p=arr;
    // cout<<p[2]<<endl;
    // // p[2] prints the value at index=2 in thw array as it is same as of arr[2]

    // int arr[6]={11,21,31,41};
    // int *p=arr++;
    // cout<<*p<<endl;
    // // here arr++ gives error because it is trying to update symbol table ehic is not possible
    // // p=p+1 i.e pointer updation is possible but not array incrementation

    char arr[]= "abcde";
    char *p= &arr[0];
    cout<<p<<endl;
    // output is abcde as cout works differently for char

    char arr[]= "abcde";
    char *p= &arr[0];
    p++;
    cout<<p<<endl;
    // output is bcde as it prints the whole array starting from index=1
    return 0;

}