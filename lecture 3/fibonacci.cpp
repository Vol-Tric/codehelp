// FIBONACCI SEQUENCE
#include<iostream>
using namespace std;
int main(){
    int n=8;
    int n1=0,n2=1,sum;
    sum=n1+n2;
    cout<<n1<<" "<<n2<<" ";
    for(int i=2;i<n;i++){
        cout<<sum<<" ";
        n1=n2;
        n2=sum;
        sum=n1+n2;
    }
    return 0;
}
