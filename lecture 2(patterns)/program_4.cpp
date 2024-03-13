// pattern
// 1 2 3 4
// 1 2 3 4
// 1 2 3 4
// 1 2 3 4

#include<iostream>
using namespace std;
int main(){
    int n,i;
    for(i=1;i<=4;i++){
        for(n=1;n<=4;n++){
            cout<<n<<" ";
        }
        cout<<endl;
    }
    return 0;
}