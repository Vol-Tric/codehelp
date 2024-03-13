// doubly linked list
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *prv;
    Node *next;

    Node (int data){
        this->data=data;
        this->prv=NULL;
        this->next=NULL;
    }

    // // destructor, manuaaly assinged for dynamically allocated memory
    // ~Node(){
    //     int val=this->data;
    //     if(next!=NULL){
    //         delete next;
    //         next =NULL;
    //     }
    //     cout<<"Memory deleted, destructor called"<<endl;
    // }
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
    head->prv=temp;
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
    n1->prv=temp;
    n1->next=NULL;

}

void insertAtMiddle(Node* &head,int data,int position){
    // when no node exist previously
    if(head==NULL){
        Node *node1=new Node(data);
        head=node1;
        return ;
    }
    
    // new node is added in between temp node and next of temp node

    // create temp node
    Node *temp=head;

    // traverse temp=temp->next; for i times where i<position to make it reach desired position
    for(int i=0;i<position-1;i++){
        temp=temp->next;
    }
    // create new node to be added
    Node *n1=new Node(data);

    // 1st make to next pointer of new_node=next pointer of temp
    n1->next=temp->next;

    // 2nd make previous pointer of new node points towards temp
    n1->prv=temp;

    // 3rd make previous of the next node is pointed towards the new node
    temp->next->prv=n1;

    // 4th allot the next pointer of temp to new node
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
        temp->next->prv=NULL;
        head=temp->next;
        temp->next=NULL;
        // delete temp;
        return;
    }
    // traverse temp=temp->next; for i times where i<position
    for(int i=0;i<position-1;i++){
        temp=temp->next;
    }
    // node between temp and next to next of temp is deleted
    // so the new next of temp is the previous next to next of temp
    
    // command to delete, it surpasses next node
    temp->next=temp->next->next;

    // set the previous pointer of the next of temp back to temp 
    temp->next->prv=temp;

    // delete temp
    // delete temp;
}

void deleteNodeValue(Node* &head,int value){
    // if no node exist
    if(head==NULL){
        cout<<"no node exist"<<endl;
        return ;
    }

    // case when the value is present in the 1st node only
    if(head->data==value){
        Node *temp=head;
        temp->next->prv=NULL;
        head=temp->next;
        temp->next=NULL;
        // delete temp;
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

    // set the previous pointer of the next of temp back to temp 
    temp->next->prv=temp;

    // delete temp
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
int getLength(Node* &head){
    Node *temp=head;
    
    int length=0;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    return length;
}

int main(){
    // doubly linked list initiated
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
    cout<<"length of the linked list is: "<<getLength(head)<<endl;

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
    deleteNodeValue(head,60);
    print_LL(head);
    cout<<"length of the linked list is: "<<getLength(head)<<endl;
    

    return 0;
}