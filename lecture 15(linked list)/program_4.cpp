// reverse a linked list using both iterative and recursive method
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

void reverseIterative(Node* &head){
    // case when 0 ar 1 item present in the list
    if(head==NULL || head->next==NULL){
        return;
    }

    Node* prv=NULL;
    Node* curr=head;
    Node* forward=NULL;

    while(curr!=NULL){
        forward=curr->next;
        curr->next=prv;
        prv=curr;
        curr=forward;
    }
    head=prv;
    
}

void reverse(Node* &head, Node* curr, Node* prv){
    // base case
    if(curr==NULL){
        head=prv;
        return;
    }

    Node* forward=curr->next;
    reverse(head,forward,curr);
    curr->next=prv;
}

void reverseRecursive_1(Node* &head){
    // case when 0 ar 1 item present in the list
    if(head==NULL || head->next==NULL){
        return;
    }

    Node* prv=NULL;
    Node* curr=head;
    reverse(head,curr,prv);


}



Node* reverseRecursive_2(Node* &head){
    // base case
    if(head==NULL || head->next==NULL){
        return head;
    }

    // recersively traverse to the last element of list, and make it a ChotaHead
    Node* chotaHead=reverseRecursive_2(head->next);

    // reversal
    head->next->next=head;
    head->next=NULL;

    // chotaHead is the Head of reversed linked list
    return chotaHead;
}



void print_LL(Node* &head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
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

    Node* newHead=reverseRecursive_2(head);
    print_LL(newHead);

    return 0;
}
