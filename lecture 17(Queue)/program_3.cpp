// circular queue using array;
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
        if((front == 0 && rear==size-1) || (rear==(front-1) % (size-1) ) ){
            return true;
        }
        return false;
    }  
    
    // enqueue, official term used for push
    void enQueue(int data){
        if(isFull()){
            cout<<"queue overfull"<<endl;
            return;
        }
        // first element
        else if(front == -1){
            front=0;
            rear=0;
            arr[rear]=data;
        }
        else if(rear==size-1 && front!=0){
            rear=0;
            arr[rear]=data;
        }
        else{
            rear++;
            arr[rear]=data;
        }
    }

    // dequeue, official term used for pop
    int deQueue(){
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

    void displayQueue(){
        if(isEmpty()){
            cout<<"queue is empty "<<endl;

        }
        cout<<"elements in circular queue are:"<<endl;
        if(front<=rear){
            for(int i=front;i<=rear;i++){
                cout<<arr[i]<<" ";
            }
        }
        else{
            for(int i=front;i<size;i++){
                cout<<arr[i]<<" ";
            }
            for(int i=0;i<rear;i++){
                cout<<arr[i]<<" ";
            }
        }
    }
};

int main(){
    Queue q(5);
 
    // Inserting elements in Circular Queue
    q.enQueue(14);
    q.enQueue(22);
    q.enQueue(13);
    q.enQueue(16);
 
    // Display elements present in Circular Queue
    q.displayQueue();
 
    // Deleting elements from Circular Queue
    printf("\nDeleted value = %d", q.deQueue());
    printf("\nDeleted value = %d", q.deQueue());
    cout<<endl;
    q.displayQueue();
 
    q.enQueue(9);
    q.enQueue(20);
    q.enQueue(5);
 
    q.displayQueue();
 
    q.enQueue(20);
    return 0;
}