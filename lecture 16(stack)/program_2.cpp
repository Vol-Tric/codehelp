// stack implementation using class
#include<iostream>
using namespace std;

class Stack{
    // properties
    public:
    int *arr;
    int size;
    int top;

    // behaviour;
    Stack(int size){
        this->size=size;
        arr= new int[size];
        top=-1;
    }

    bool isEmpty(){
        if(top!=-1){
            return false;
        }
        return true;
    }

    void push(int element){
        if(top==size-1){
            cout<<"stack is full"<<endl;
            return;
        }
        else{
            top++;
            arr[top]=element;
        }
    }

    void pop(){
        if(isEmpty()){
            cout<<"stack is empty "<<endl;
            return;
        }
        else{
            top--;
        }
    }

    void peek(){
        if(isEmpty()){
            cout<<"stack is empty "<<endl;
            return;
        }
        else{
            cout<<"top element is: "<<arr[top]<<endl;
        }
    }

};

int main(){
    // creation of stack
    Stack s(5);

    // push operation
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    // seek operation
    s.peek();

    // // pop operation
    // s.pop();
    // s.peek();

    // popping all the elements
    while(!s.isEmpty()){
        s.peek();
        s.pop();
    
    }
    s.peek();
    s.pop();
    return 0;
}