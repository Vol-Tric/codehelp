// basic stack operations using STL
#include<iostream>
#include<stack>
using namespace std;

int main(){
    // creation of stack
    stack<int> s;

    // push operation.
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    // top element;
    cout<<"top elements: "<<s.top()<<endl;

    // size of stack
    cout<<"size of stack: "<<s.size()<<endl;

    // // pop
    // s.pop();
    // // top element is popped
    // cout<<"top elements: "<<s.top()<<endl;


    // the only way to see all the elements of the stack is by printing each elements and the popping it
    while(!s.empty()){
        cout<<"top element: "<<s.top()<<endl;
        s.pop();
    }


    return 0;
}
