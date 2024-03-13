// 1
// 2 9
// 3 8 10
// 4 7 11 14
// 5 6 12 13 15

// K is used to find the wave tops for starting the next columns
// i.e. 5,9,10,13,15

#include<bits/stdc++.h>

using namespace std;
int main(){
    int n=5;

    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            int x=0;
            for(int k=0;k<j;k++){
                x=x+n-k;
            }
            if(j%2==0){
                cout<<x+i-j+1<<" ";
            }
            else{
                cout<<x+n-i<<" ";
            } 
        }
        cout<<endl;
    }
}