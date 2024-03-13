// Dynamic memory allocation
#include<iostream>
using namespace std;

int main(){
    int i=5;
    // &j=i is used to allocate j the memory space of i, i.e both of them point to the same memory space so my making changes in any of them, same value gets changed. 
    int &j=i;
    cout<<i<<endl<<j<<endl;
    i++;
    cout<<i<<endl;
    j++;
    cout<<j<<endl;
    cout<<i<<endl;

    return 0;
}