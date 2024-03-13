// merge 2 sorted LL
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

// merge function

Node* merge_LL(Node* &head1, Node* &head2){
    // base case, id any one of list is null
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    // 2 pointer for head1
    Node* prev=head1;
    Node* curr1=head1->next;
    //pointer for head 2
    
    Node* h2=head2;
    Node* curr2=head2->next;
    

    while(curr1!=NULL && h2!=NULL){
        
        if(prev->data <= h2->data && h2->data <= curr1->data){
            prev->next=h2;
            curr2=h2->next;
            h2->next=curr1;
            prev=h2;
            h2=curr2;

        }
        else{
            prev=curr1;
            curr1=curr1->next;
            
            // if 1st LL ends
            if(curr1==NULL){
                prev->next=h2;
                return head1;
            }
            
        }
    }
    return head1;
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

    Node *node2=new Node(9);
    cout<<node2->data<<endl;
    

    // head1 and head2 pointed to node1 and node2 resp
    Node* head1=node1;
    Node* head2=node2;
    insertAtHead(head1,8);
    insertAtHead(head1,6);
    insertAtHead(head1,4);
    insertAtHead(head1,2);

    insertAtHead(head2,7);
    insertAtHead(head2,5);
    insertAtHead(head2,3);
    insertAtHead(head2,1);
    
    // print
    print_LL(head1);
    print_LL(head2);
    
    cout<<endl;

    Node* newNode=merge_LL(head2,head1);
    print_LL(newNode);
    
    

    return 0;
}