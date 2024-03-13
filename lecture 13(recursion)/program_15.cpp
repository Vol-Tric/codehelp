// bubble sort using recursion
#include<iostream>
using namespace std;

void swap(char *a, char *b){
    char *temp=a;
    a=b;
    b=temp;
}


void bubble_sort(int arr[],int len){
    if(len==0){
        return;
    }
    for(int i=0;i<len;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    return bubble_sort(arr,len-1);
}

int main(){
    int arr[]={2,3,5,1,6,4,7,4,8,6,9,3};
    int len=sizeof(arr)/sizeof(arr[0]);
    cout<<"before sorting"<<endl;
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    bubble_sort(arr,len-1);
    cout<<"after sorting"<<endl;
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    return 0;

}