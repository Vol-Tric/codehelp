// method overriding / function overriding
#include<bits/stdc++.h>
using namespace std;

class A{
    public:
    void func(){
        cout<<"I am of class A "<<endl;
    }
};

class C: public A{
    public:
    void func(){
        cout<<"I am of class C "<<endl;
    }
};

int main(){
    C obj;
    
    // using scope resolution operator (::), function of parent class is used
    obj.A::func();
    // normal defining, function of current class is used
    // function overrided
    obj.func();
    return 0;
}