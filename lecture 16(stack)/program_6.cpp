// insert at bottom of the stack
#include <bits/stdc++.h>
using namespace std;

void solve(stack<int>& myStack, int x){
    // base case
    if(myStack.empty()){
        myStack.push(x);
        return ;
    }

    int num=myStack.top();
    myStack.pop();
    solve(myStack, x);
    myStack.push(num);
}

void pushAtBottom(stack<int>& myStack, int x) 
{
    int count=0;
    solve(myStack, x);
    
}

int main(){
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    

    pushAtBottom(s, 70);

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}