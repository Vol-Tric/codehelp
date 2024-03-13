// remove nth node from end of list

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

// done using a single traverse
Node* removeNthFromEnd(Node* head, int n) {
    Node* fast = head;
    Node* slow = head;

    for(int i=0;i<n;i++){
        fast = fast->next;
    }

    while(fast){
        fast = fast->next;
        slow = slow->next;
    }
    Node* dummy = slow->next;
    slow->next = dummy->next;
    delete dummy;
    
    return head;
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
    Node *node1=new Node(50);
    

    // head pointed to node1
    Node* head=node1;
    insertAtHead(head,40);
    insertAtHead(head,30);
    insertAtHead(head,20);
    insertAtHead(head,10);
    
     // print
    print_LL(head);
    cout<<endl;
    
    int n=2;
    Node* ans = removeNthFromEnd(head , n);

    print_LL(ans);

    
    return 0;
}