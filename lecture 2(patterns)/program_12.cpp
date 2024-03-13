//      *
//     ***
//    *****
//   *******
//  *********
// ***********
// 36
#include<iostream>
using namespace std;
int main(){
    int n=6;
    int sum=0;
    for(int i=1;i<=n;++i){
        for(int space=n-i-1;space>=0;space--){
            cout<<" ";
        }
        int k=1;
        while(k!=2*(i)){
            cout<<"*";
            ++k;
            sum++;
        }
        cout<<endl;

    }
    cout<<sum;
    return 0;
}