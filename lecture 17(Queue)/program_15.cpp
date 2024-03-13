// implement stack using queue
#include<bits/stdc++.h>
using namespace std;

class Stack{
    queue<int>q;

    public:
    
    void push(int data){
        if(q.empty()){
            q.push(data);
            return;
        }

        else{
            queue<int>q1;
            while(!q.empty()){
                q1.push(q.front());
                q.pop();
            }
            q.push(data);
            while(!q1.empty()){
                q.push(q1.front());
                q1.pop();
            }
            return ;
        }
    }    

    void pop(){
        if(q.empty()){
            cout<<"stack underflow"<<endl;
            return;
        }
        else{
            q.pop();
            return;
        }
    }

    int top(){
        if(q.empty()){
            return -1;
        }
        else{
            return q.front();
        }
    }

    bool isEmpty(){
        return q.empty();
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}