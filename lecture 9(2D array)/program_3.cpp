// print like a wave
// 1 2
// 3 4
// the answer will be [1 3 4 2]

#include<iostream>
using namespace std;
int main(){
    int arr[3][3]={1,2,3,4,5,6,7,8,9};
    int nRows=3;
    int mCols=3;

    for(int i=0;i<mCols;i++){
        if(i%2==0){
            for(int j=0;j<nRows;j++){
                cout<<arr[j][i]<<" ";

            }
        }
        else{
            for(int j=nRows-1;j>=0;j--){
             cout<<arr[j][i]<<" ";
            
            }
        }
        
    }
    return 0;
}