// implementation of queue using arrays
#include<iostream>
#include<queue>
using namespace std;

class Queue{
    private:
    int *arr;
    int size;
    int front;
    int rear;

    public:
    Queue(int size){
        this->size=size;
        arr=new int[size];
        front=0;
        rear=0;
    }
    bool isEmpty(){
        if(front==rear){
            return true;
        }
        return false;
    }
    
    // enqueue, official term used for push
    void enqueue(int data){
        if(rear<size){
            arr[rear]=data;
            rear++;
        }
        else{
            cout<<"Queue overflow"<<endl;
            return ;
        }
    }

    // dequeue, official term used for pop
    void dequeue(){
        if(!isEmpty()){
            front++;
        }
        else{
            cout<<"queue empty"<<endl;
            return ;
        }
    }

    int top(){
        if(!isEmpty()){
            return arr[front];
        }
        else{
            return -1;
        }
    }

    int length(){
        int length=rear-front;
        return length;
    }
};

int main(){
    Queue q(6);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);


    // extra enqueue
    q.enqueue(70);


    while(!q.isEmpty()){
        cout<<"front : "<<q.top()<<endl;
        cout<<"size : "<<q.length()<<endl;
        cout<<endl;
        q.dequeue();
    }
    // extra dequeue
    q.dequeue();
    return 0;

}