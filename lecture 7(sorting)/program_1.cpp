// selection sort
// find the smallest element and place it in the front in each pass
#include<iostream>
using namespace std;
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}
int main(){
    int position,n,swap;
    int arr[10]={10,9,8,7,6,5,4,3,2,1};
    n=10;
    for(int i=0;i<n-1;i++){
        position=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                position=j;
            }

        }
        swap=arr[i];
        arr[i]=arr[position];
        arr[position]=swap;
        print(arr,n);
        cout<<endl;
    }
    cout<<"array after sort is";
    print(arr,n);
}
