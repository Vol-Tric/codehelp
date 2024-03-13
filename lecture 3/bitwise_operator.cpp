// bitwise operator
// & AND 
// | OR 
// ~ NOT 
// ^ XOR

// left and right shift operator
// left shift <<
// right shift >>

#include<iostream>
using namespace std;
int main(){
    int a=4;
    int b=6;
    cout<<"a&b="<<(a&b)<<endl;
    cout<<"a|b="<<(a|b)<<endl;
    cout<<"a~b="<<~a<<endl;
    cout<<"a^b="<<(a^b)<<endl;

    cout<<"15>>3="<<(15>>3)<<endl;
    cout<<"8<<3="<<(8<<3)<<endl;
}