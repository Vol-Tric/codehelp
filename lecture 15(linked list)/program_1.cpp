// singly linked list
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

void insertAtTail(Node* &head, int data){
    // when no node exist previously
    if(head==NULL){
        Node *node1=new Node(data);
        head=node1;
        return ;
    }

    // create new node
    Node *temp=head;
    // temp->next!=NULL, this will make us reach the last node
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node *n1=new Node(data);
    temp->next=n1;
    n1->next=NULL;

}

void insertAtMiddle(Node* &head,int data,int position){
    // when no node exist previously
    if(head==NULL){
        Node *node1=new Node(data);
        head=node1;
        return ;
    }

    // create new node
    Node *temp=head;
    // traverse temp=temp->next; for i times where i<position
    for(int i=0;i<position-1;i++){
        temp=temp->next;
    }
    Node *n1=new Node(data);
    // 1st make to next of new_node=next of temp
    n1->next=temp->next;
    // 2nd allot the next of temp to new node
    // done in this order so that no data is misplaced
    temp->next=n1;

}

void deleteNodePosition(Node* &head, int position){
    // if no node exist
    if(head==NULL){
        cout<<"no node exist"<<endl;
        return ;
    }

    // create new node
    Node *temp=head;
    // this is to delete the 0th index value
    if(position==0){
        head=temp->next;
        return;
    }
    // traverse temp=temp->next; for i times where i<position
    for(int i=0;i<position-1;i++){
        temp=temp->next;
    }
    // command to delete, it surpasses next node
    temp->next=temp->next->next;
    // delete temp;
}

void deleteNodeValue(Node* &head,int value){
    // if no node exist
    if(head==NULL){
        cout<<"no node exist"<<endl;
        return ;
    }

    // create new node
    Node *temp=head;
    // temp->next!=NULL, this will make us reach the last node
    while(temp->next!=NULL){
        // this will break the loop where the value matches
        if(temp->next->data==value){
            break;
        }
        temp=temp->next;
    }
    // command to delete, it surpasses next node
    temp->next=temp->next->next;
    // delete temp;
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
    cout<<node1->next<<endl;

    // head pointed to node1
    Node* head=node1;
    insertAtHead(head,20);
    insertAtHead(head,30);
    insertAtHead(head,40);
    insertAtHead(head,50);
    insertAtHead(head,60);
     // print
    print_LL(head);

    // insert an end
    insertAtTail(head,70);
    print_LL(head);

    // insert in between
    // 4 indicate that the element inserted should be after 4 existing elements
    insertAtMiddle(head, 80,4);
    print_LL(head);

    // delete by position
    // 4 indicate that the element deleted should be after 4 existing elements
    deleteNodePosition(head, 4);
    print_LL(head);

    // delete by value
    deleteNodeValue(head,30);
    print_LL(head);

    // delete 0th position
    deleteNodePosition(head, 0);
    print_LL(head);
    return 0;
}