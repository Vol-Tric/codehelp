// pattern
//       1
//     1 2 1
//   1 2 3 2 1
// 1 2 3 4 3 2 1

#include<iostream>
using namespace std;
int main(){
    int n=4;
    for(int i=1;i<=n;i++){
        // for space
        for(int j=n-i;j>=0;j--){
            cout<<"  ";
        }
        // for 1st triangle
        for(int k=1;k<=i;k++){
            cout<<k<<" ";
        }
        // for 2nd triangle
        for(int m=i-1;m>=1;m--){
            cout<<m<<" ";
        }
        cout<<endl;
    }
    return 0;
}