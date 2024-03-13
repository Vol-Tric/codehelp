// implement queue using stack
#include<bits/stdc++.h>
using namespace std;

class Queue{
    stack<int>s;

    public:
    
    void push(int data){
        if(s.empty()){
            s.push(data);
            return;
        }
        else{
            stack<int>s1;
            while(!s.empty()){
                s1.push(s.top());
                s.pop();
            }
            s.push(data);
            while(!s1.empty()){
                s.push(s1.top());
                s1.pop();
            }
            return;
        }
    }

    void pop(){
        if(s.empty()){
            cout<<"queue overflow"<<endl;
            return;
        }
        else{
            s.pop();
            return;
        }
    }

    int front(){
        if(s.empty()){
            return -1;
        }
        else{
            return s.top();
        }
    }

    bool isEmpty(){
        return s.empty();
    }
};

int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    while(!q.isEmpty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}