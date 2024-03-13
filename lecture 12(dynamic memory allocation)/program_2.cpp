// pass by value VS pass by refrence
#include<iostream>
using namespace std;

// the function uses pass by value
// here n just makes another copy of the variable i haivng same value as of i, as n=i
void update1(int n){
    n++;
}

// this function uses pass by refrence as it create a dynamically allocated variable pointing to the same memory address
// here n is the refrence variable as &n=i
void update2(int &n){
    n++;
}

int main(){
    int i=5;
    cout<<"before pass by value: "<<i<<endl;
    update1(i);
    cout<<"after pass by value: "<<i<<endl;

    cout<<endl;

    cout<<"before pass by refrence: "<<i<<endl;
    update2(i);
    cout<<"after pass by refrence: "<<i<<endl;
    return 0;
}