// reverse linked list in k groups of elements


#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node (int data){
        this->data=data;
        this->next=NULL;
    }
};

void insertAtHead(Node* &head, int data){
    // when no node exist previously
    if(head==NULL){
        Node *node1=new Node(data);
        head=node1;
        return ;
    }

    // create new node
    Node *temp=new Node(data);
    temp->next=head;
    head=temp;
}


void print_LL(Node* &head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* kReverse(Node* &head, int k){
    // base case
    if(head==NULL){
        return NULL;
    }

    // step 1, reverse the elements in the k group;
    Node *forward=NULL;
    Node *curr=head;
    Node *prv=NULL;
    int count=0;
    while(count<k && curr!=NULL){
        forward=curr->next;
        curr->next=prv;
        prv=curr;
        curr=forward;
        count++;
    }

    // step 2, recursive call
    if(forward!=NULL){
        head->next=kReverse(forward,k);
    }

    return prv;
}

int main(){
    // create a node
    Node *node1=new Node(10);
    cout<<node1->data<<endl;
    

    // head pointed to node1
    Node* head=node1;
    insertAtHead(head,20);
    insertAtHead(head,30);
    insertAtHead(head,40);
    insertAtHead(head,50);
    insertAtHead(head,60);
     // print
    print_LL(head);

    // reverseIterative(head);
    // print_LL(head);

    // reverseRecursive_1(head);
    // print_LL(head);

    // Node* newHead=reverseRecursive_2(head);
    // print_LL(newHead);

    Node* newHead=kReverse(head,4);
    print_LL(newHead);

    return 0;
}
