// Binary search using reccursion
#include<iostream>
using namespace std;
void binary_search(int array[],int start, int end,int key){
    int mid=(end-start)/2;
    if(key==array[mid]){
        cout<<"element present";
    }
    else if(key<mid){
        binary_search(array,0,mid-1,key);
        
    }
    else{
        binary_search(array,mid+1,end,key);
    }
}


int main(){
    int n,key;
    int array[20];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    cout<<"Enter the element to be searched:";
    cin>>key;
    binary_search(array,0,n,key);
    return 0;

}