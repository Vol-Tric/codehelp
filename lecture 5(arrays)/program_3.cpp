// swap alternate elements of an array
// for eg: A=[2,4,6,8,10,12]
// A after swapping should be A=[4,2,8,6,12,10]

#include<iostream>
using namespace std;

void alternate_swap(int array[],int num){
    for(int i=0;i<num;i=i+2){
        swap(array[i],array[i+1]);
    }
}

int main(){
    int array[20];
    int num;
    cout<<"enter the number of elements:";
    cin>>num;
    for(int i=0;i<num;i++){
        cout<<"Enter the element:";
        cin>>array[i];
    }
    alternate_swap(array,num);
    cout<<"the swapped array is"<<endl;
    for(int i=0;i<num;i++){
        cout<<array[i]<<" ";
        
    }
    return 0;
}