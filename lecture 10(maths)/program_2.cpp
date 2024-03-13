// GCD using euclid algorithm
// Euclid Algorithm:
// GCD(a,b)=GCD(a-b,b)
// to find LCM(a,b):
// LCM(a,b)*GCD(a,b)=a*b

#include<iostream>
using namespace std;

int gcd(int a,int b){
    if(a==0){
        return b;
    }
    else if(b==0){
        return a;
    }
    else if(a>b){
        gcd(a-b,b);
    }
    else{
        gcd(a,b-a);
    }
}
int main(){

    int a=5;
    int b=25;

    int GCD=gcd(a,b);
    int LCM=(a*b)/GCD;
    cout<<"GCD = "<<GCD<<" and LCM = "<<LCM;
    return 0;
}