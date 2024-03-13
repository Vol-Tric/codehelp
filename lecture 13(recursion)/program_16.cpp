// selection sort
#include<iostream>
using namespace std;

void swap(char *a, char *b){
    char *temp=a;
    a=b;
    b=temp;
}


void selection_sort(int arr[],int len){
    // base case
    if(len==0){
        return;
    }
    
    // process
    int min_index=0;
    for(int i=0;i<len;i++){
        if(arr[i]<arr[min_index]){
            min_index=i;
        }
    }
    swap(arr[0],arr[min_index]);
    // recursive relation
    return selection_sort(arr+1,len-1);
}

int main(){
    int arr[]={2,3,5,1,6,4,7,4,8,6,9,3};
    int len=sizeof(arr)/sizeof(arr[0]);
    cout<<"before sorting"<<endl;
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    selection_sort(arr,len);
    cout<<"after sorting"<<endl;
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    return 0;

}