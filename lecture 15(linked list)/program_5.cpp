// middle of linked list
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

int middleElement(Node* &head){
    if(head==NULL || head->next==NULL){
        return head->data;
    }
    // full_count traverse 2 nodes at once
    // gave ahead start to fast
    Node* full_count=head->next;
    // middle_count traverse only one node at once
    Node* middle_count=head;

    // we divided to double movement of fast in 2 sectors so that is full pass is not possible, half pass can take place (usually in cases of even no. of elements)
    while(full_count!=NULL){
        full_count=full_count->next;

        if(full_count!=NULL){
            full_count=full_count->next;
        }
        middle_count=middle_count->next;
    }
    return middle_count->data;
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
    insertAtHead(head,70);
     // print
    print_LL(head);

    int middle=middleElement(head);
    cout<<"Middle element is: "<<middle<<endl;

    return 0;

}