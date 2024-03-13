// function using pointers
#include<iostream>
using namespace std;

void print(int *ptr){
    cout<<ptr<<endl;
    cout<<*ptr<<endl;
}

void update(int *ptr){
    *ptr=*ptr+1;
}

void getSum(int arr[],int num){
    
    cout<<sizeof(arr)<<endl;
    int sum=0;
    for(int i=0;i<num;i++){
        sum +=arr[i];
    }
    cout<<"sum is: "<<sum<<endl;
}

int main(){
    int value=10;
    int *p=&value;

    // print(p);

    // cout<<"before: "<<p<<endl;
    // update(p);
    // cout<<"after: "<<p<<endl;
    // as both are same, this is because the updation is occuring inside the function only by creating duplicate memory. therefore address is not changed

    // cout<<"before: "<<*p<<endl;
    // update(p);
    // cout<<"after: "<<*p<<endl;
    // // the value can be updated using a function;

    int arr[5]={1,2,3,4,5};

    
    getSum(arr,5);
    // this implies that a pointer to the array is passed in the function instead of the whole array
    // => we can send only a specific part of the array to the function 
    getSum(arr+2,3);

    return 0;
}