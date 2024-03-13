// row wise sum
// [1,2,3] = 6
// [4,5,6] = 15
// [7,8,9] = 24
// return [6,15,24]

#include<iostream>
using namespace std;
int max_row_sum(int arr[3][4]){
   int maxi=INT_MIN;
    for(int i=0;i<3;i++){
        int sum=0;
        for(int j=0;j<4;j++){
            sum=sum+arr[i][j];
        }
        if(sum>maxi){
            maxi=sum;
        }
    }
    return maxi;

}

int main(){
    int arr[3][4]={{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    int answer[3];
    for(int i=0;i<3;i++){
        int sum=0;
        for(int j=0;j<4;j++){
            sum=sum+arr[i][j];
        }
        answer[i]=sum;
    }
    for(int i=0;i<3;i++){
        cout<<answer[i]<<" ";
    }
    
    int max_sum=max_row_sum(arr);
    cout<<max_sum; 
    return 0;
}