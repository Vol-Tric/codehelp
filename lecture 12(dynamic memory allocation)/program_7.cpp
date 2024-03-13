// macro
#include<iostream>
using namespace std;

#define PI 3.14
// PI is a macro 
int main(){
    int area=PI*7*7;
    cout<<area;
    return 0;
}

// macro are a peice of code that is replaced by the assigned value of it during compile
// no new memory is created for them so they optimize the space
// also no changes can be done to it in the code
// eg: PI = PI + 1 , will not work at all