// bubble sort
// places the ith largest element in the right spot in the ith sorting
// largest element gets sorted first
#include<iostream>
using namespace std;

void print_arr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void bubble_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
        cout<<"after "<<i+1<<" swap"<<endl;
        print_arr(arr,n);
        cout<<endl;
    }
}
int main(){
    int arr[10]={ 8, 22, 7, 9, 31, 5, 13};
    int n=7;
    bubble_sort(arr,n);
    return 0;
}