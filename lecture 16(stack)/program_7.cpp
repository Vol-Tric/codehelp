// reverse a stack using recursion

#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>& myStack, int x) 
{
    
    // base case
    if(myStack.empty()){
        myStack.push(x);
        return ;
    }

    int num=myStack.top();
    myStack.pop();
    insertAtBottom(myStack, x);
    myStack.push(num);
    
}

void reverseStack(stack<int> &stack) {
    // base case
    if(stack.empty()){
        return ;
    }

    int num=stack.top();
    stack.pop();

    reverseStack(stack);
    insertAtBottom(stack,num);

}

int main(){
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    

    reverseStack(s);

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}