// pattern
//        *
//      * *
//    * * *
//  * * * *
#include<iostream>
using namespace std;
int main(){
    int n=4;
    for(int i=1;i<=n;i++){
        // loop for space (2 spaces used)
        for(int j=n-i;j>=0;j--){
            cout<<"  ";
        }
        // loop for *
        for(int k=1;k<=i;k++){
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}