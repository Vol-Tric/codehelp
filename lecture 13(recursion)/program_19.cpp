// quick sort using recursion
#include<iostream>
using namespace std;

void swap(char *a, char *b){
    char *temp=a;
    a=b;
    b=temp;
}

int partition(int arr[],int start, int end){

    int pivot=arr[start];
    int count=0;
    for(int i=start+1;i<end;i++){
        if(arr[i]<=pivot){
            count++;
        }
    }
    int pivot_index=start+count;
    swap(arr[pivot_index],arr[start]);
    int i=start;
    int j=end;
    while(i<pivot_index && j>pivot_index){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivot_index && j>pivot_index){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
        
    }
    return pivot_index;
}


void quick_sort(int arr[],int start, int end){
    if(start>=end){
        return;
    }
    int partition_element=partition(arr,start,end);
    quick_sort(arr,start,partition_element-1);
    quick_sort(arr,partition_element+1,end);
}

int main(){
    int arr[12]={2,3,5,1,6,4,7,4,8,6,9,3};
    int len=sizeof(arr)/sizeof(arr[0]);
    cout<<"before sorting"<<endl;
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    quick_sort(arr,0,len-1);
    cout<<"after sorting"<<endl;
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    return 0;

}