// pattern
// A A A 
// B B B 
// C C C
#include<iostream>
using namespace std;
int main(){
    int n=4;
    // 65==A, refer to ASCII table
    char ch=65; 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<ch<<" ";
        }
        ch++;
        cout<<endl;
    }
    return 0;
}