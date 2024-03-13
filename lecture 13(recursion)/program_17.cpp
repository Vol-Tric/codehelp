// merge sort using recursion
#include<iostream>
using namespace std;

void swap(char *a, char *b){
    char *temp=a;
    a=b;
    b=temp;
}

void merge(int *arr,int start, int end){
    int mid=start+(end-start)/2;

    int len1=mid-start+1;
    int len2=end-mid;

    int *first=new int[len1];
    int *second=new int[len2];

    int mainArrayIndex=start;

    for(int i=0;i<len1;i++){
        first[i]=arr[mainArrayIndex++];
    }

    mainArrayIndex=mid+1;
    for(int i=0;i<len2;i++){
        second[i]= arr[mainArrayIndex++];
    }

    // merge 2 arrays
    int index1=0;
    int index2=0;
    mainArrayIndex=start;

    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[mainArrayIndex++]=first[index1++];
        }
        else{
            arr[mainArrayIndex++]=second[index2++];
        }
    }

    while(index1<len1){
        arr[mainArrayIndex++]=first[index1++];
    }

    while(index2<len2){
        arr[mainArrayIndex++]=second[index2++];
    }


    
}

void merge_sort(int arr[], int start, int end){
    // base case
    if(start>=end){
        return ;
    }
    
    int mid=start+(end-start)/2;
    // left side
    merge_sort(arr,start,mid);
    // right side
    merge_sort(arr,mid+1,end);
    // 2 way merge
    merge(arr,start,end);
}




int main(){
    int arr[12]={2,3,5,1,6,4,7,4,8,6,9,3};
    int len=sizeof(arr)/sizeof(arr[0]);
    cout<<"before sorting"<<endl;
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    merge_sort(arr,0,len-1);
    cout<<"after sorting"<<endl;
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    return 0;

}