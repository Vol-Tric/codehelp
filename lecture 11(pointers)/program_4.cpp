// double pointer
#include<iostream>
using namespace std;

void update(int **p){
    // p = p + 1;
    // 1st try
    // no changes at all

    // *p = *p + 1;
    // // 2nd try
    // change in the value of 1st pointer (ptr2)

    **p = **p + 1;
    // // 3rd try
    // value of i changes (5 increments to 6)
}

int main(){
    // int i=5;
    // int *ptr1=&i;
    // cout<<ptr1<<endl;

    // // Double pointer ptr2 using **
    // int**ptr2=&ptr1;
    // cout<<ptr2<<endl;
    // cout<<&ptr1<<endl;
    // cout<<*ptr2<<endl;
    // // => ptr1=*ptr2
    // // => ptr2=&ptr1
    // cout<<**ptr2<<endl;
    // cout<<*ptr1<<endl;
    // // ** derefrences 2 times and takes us to the value of i

    int i=5;
    int *ptr1=&i;
    int **ptr2=&ptr1;

    cout<<"before"<<endl;
    cout<<i<<endl;
    cout<<ptr1<<endl;
    cout<<ptr2<<endl;
    update(ptr2);
    cout<<"after"<<endl;
    cout<<i<<endl;
    cout<<ptr1<<endl;
    cout<<ptr2<<endl;




}