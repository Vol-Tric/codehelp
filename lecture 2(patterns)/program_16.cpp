// * * * * 
//  * * * 
//   * * 
//    *
//   * * 
//  * * * 
// * * * * 

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=4;

    for(int i=0; i<n; i++){
        // first spacing
        for(int j=0 ;j<i;j++){
            cout<<" ";
        }
        // inverted triangle
        for(int j=n-i ; j>=1 ; j--){
            cout<<"* ";
        }
        cout<<endl;
    }

    for(int i=0; i<n-1; i++){
        // second spacing
        for(int j=n-i-2 ; j>0 ; j--){
            cout<<" ";
        }
        
        //  triangle
        for(int j=0 ;j<=i+1;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}