// inheritence ambuiguity
#include<bits/stdc++.h>
using namespace std;

class A{
    public:
    void func(){
        cout<<"I am of class A "<<endl;
    }
};

class B{
    public:
    void func(){
        cout<<"I am of class B "<<endl;
    }
};

class C: public A, public B{
    public:
    void print(){
        cout<<"I am of class C "<<endl;
    }
};

int main(){
    C obj;
    // scope resolution operator (::) is used to deal with it
    obj.A::func();
    obj.B::func();
    obj.print();
    return 0;
}