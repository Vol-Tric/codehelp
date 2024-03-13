// count inversions
// Inversion Count for an array indicates – how far (or close) the array is from being sorted. If the array is already sorted, then the inversion count is 0, but if the array is sorted in reverse order, the inversion count is the maximum. 
// Given an array arr[]. The task is to find the inversion count of arr[]. Where two elements arr[i] and arr[j] form an inversion if a[i] > a[j] and i < j.

// Examples: 
// Input: arr[] = {8, 4, 2, 1}
// Output: 6
// Explanation: Given array has six inversions: (8, 4), (4, 2), (8, 2), (8, 1), (4, 1), (2, 1).

// we do this using merge sort.
// the algo we use is 
// if(arr1[i]>=arr2[j]){
//     ans=ans+(len(arr)-i);
//     j++
// }
// if(arr1[i]<arr2[j]){
//     i++;
// }

#include<iostream>
using namespace std;


int count =0;
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
        int i=index1;
        int j=index2;
        // these 2 if statements are to count the number of inversions
        if(first[i]>=second[j]){
            count=count+(len1-i);
            j++;
        }
        if(first[i]<second[j]){
            i++;
        }
        // these are to 2 way merge
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
    int arr[5]={5,3,2,4,1};
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
    cout<<endl<<"number of inversions: "<<count<<endl;
    return 0;

}