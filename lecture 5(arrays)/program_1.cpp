// MIN and MAX in a array;
#include<iostream>
using namespace std;
int max_ele(int array[],int n){
    
    int MAX=array[0];
    for(int i=0;i<n;i++){
        if(array[i]>MAX){
            MAX=array[i];
        }
    }
    return MAX;
}

int min_ele(int array[],int n){
    
    int MIN=array[0];
    for(int i=0;i<n;i++){
        if(array[i]<MIN){
            MIN=array[i];
        }
    }
    return MIN;
}
int main(){
    int array[20];
    int num,max,min;
    cout<<"Enter the number of elements:";
    cin>>num;
    for(int i=0;i<num;i++){
        cout<<"enter element"<<i+1<<":";
        cin>>array[i];
    }
    max=max_ele(array,num);
    min=min_ele(array,num);
    cout<<"the minimum element of array is "<<min<<endl;
    cout<<"the maximum element of the array is"<<max<<endl;
    return 0;


}