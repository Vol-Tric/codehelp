#include<iostream>
using namespace std;

int main(){
    int num=5;
    cout<<num<<endl;
    cout<<endl;

    // address of num (done by using &)
    cout<<&num<<endl;
    cout<<endl;

    // creating a pointer
    int *ptr=&num;
    cout<<ptr<<endl;
    cout<<endl;

    // address of the pointer
    cout<<&ptr<<endl;
    cout<<endl;

    // defrerence of a pointer 
    cout<<*ptr<<endl;
    cout<<endl;

    // changing value of the original variable using pointer
    (*ptr)++;
    cout<<*ptr<<endl;
    cout<<endl;

    // copying a pointer
    int *ptr2=ptr;
    cout<<ptr2<<endl;
    cout<<*ptr2<<endl;
    cout<<endl;

    // pointer addition
    ptr++;
    cout<<ptr<<endl;
    cout<<endl;

    // Array in pointer
    int arr[10]={2,4,7,8,9};
    cout<<endl;

    // locating address of array
    cout<<arr<<endl;
    cout<<&arr[0]<<endl;
    cout<<endl;

    // derefrence on pointer in array
    cout<<*arr<<endl;
    

    // rendom stuff in array
    cout<<*arr+1<<endl;
    cout<<*(arr+1)<<endl;
    cout<<endl;

    // arr[i]==*(arr+i)
    // also
    // i[arr]==*(i+arr)
    // both of them are same
    cout<<arr[2]<<endl;
    cout<<*(arr+2)<<endl;
    cout<<2[arr]<<endl;
    cout<<*(2+arr)<<endl;
    cout<<endl;

    // size of 
    int *ptr3=&arr[0];
    cout<<sizeof(arr)<<endl;
    cout<<sizeof(ptr3)<<endl;
    cout<<sizeof(*ptr3)<<endl;
    return 0;
}