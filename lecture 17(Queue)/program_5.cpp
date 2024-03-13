// doubly ended queue using array
#include<iostream>
#include<queue>
using namespace std;

class Deque
{
    int *arr;
    int size;
    int front;
    int rear;
public:
    // Initialize your data structure.
    Deque(int n)
    {
        size=n;
        arr=new int[n];
        front=-1;
        rear=-1;
    }
    bool isEmpty(){
        if(front==-1){
            return true;
        }
        return false;
    } 

    bool isFull(){
        if((front == 0 && rear==size-1) || (front!=0) && (rear==(front-1) % (size-1) ) ){
            return true;
        }
        return false;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // check full
        if(isFull()){
            return false;
        }

        else if(isEmpty()){
            front=rear=0;
        }

        else if(front==0){
            front=size-1;
        }
        else{
            front--;
        }
        arr[front]=x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if(isFull()){
            return false;
        }
        // first element
        else if(isEmpty()){
            front=0;
            rear=0;    
        }
        else if(rear==size-1 && front!=0){
            rear=0;    
        }
        else{
            rear++;  
        }
        arr[rear]=x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if(isEmpty()){
            return -1;
        }
        int ans=arr[front];
        arr[front]=-1;

        // only one element present
        if(front==rear){
            front=rear=-1;
        }
        else if(front==size-1){
            front=0;

        }
        else{
            front++;
        }
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if(isEmpty()){
            return -1;
        }
        int ans=arr[rear];
        arr[rear]=-1;

        // only one element present
        if(front==rear){
            front=rear=-1;
        }
        else if(rear==0){
            rear=size-1;

        }
        else{
            rear++;
        }
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }

    
    
};

int main(){
    Deque d(5);
    d.pushFront(10);
    d.pushRear(20);
    return 0;
}