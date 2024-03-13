// add 2 numbers represented by a linked list
#include<iostream>
#include<vector>

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

Node* reverseList(Node* &head){
    Node* prv=NULL;
    Node* curr=head;
    Node* forward=NULL;

    while(curr!=NULL){
        forward=curr->next;
        curr->next=prv;
        prv=curr;
        curr=forward;
    }
    return prv;
}

void insertAtTail(Node* &head, Node* &tail, int digit){
    Node* temp= new Node(digit);

    if(head==NULL){
        head=temp;
        tail=temp;
        return ;
    }
    else{
        tail->next=temp;
        tail=temp;
    }
}

Node* add(Node* &head_1, Node* &head_2){
    int carry=0;
    
    Node* ans_head=NULL;
    Node* ans_tail=NULL;
    
    while(head_1!=NULL || head_2!=NULL || carry!=0){
        int val1=0;
        if(head_1!=NULL){
            val1=head_1->data;
        }
        int val2=0;
        if(head_2!=NULL){
            val2=head_2->data;
        }

        int sum=val1 + val2 + carry;
        carry=sum/10;
        int digit=sum%10;
        insertAtTail(ans_head,ans_tail,digit);

        if(head_1!=NULL){
            head_1=head_1->next;
        }
        if(head_2!=NULL){
            head_2=head_2->next;
        }
    }
    return ans_head;
    
}
Node* addLinkedList(Node* &head1, Node* &head2){
    // step 1, reverse linked List
    // head1=reverseList(head1);
    // head2=reverseList(head2);

    // step 2, add LL
    Node* ans= add(head1,head2);

    // step 3, reverse final LL
    // ans=reverseList(ans);

    return ans;   
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
    Node *node1=new Node(9);
    cout<<node1->data<<endl;

    Node *node2=new Node(9);
    cout<<node2->data<<endl;
    

    // head1 and head2 pointed to node1 and node2 resp
    Node* head1=node1;
    Node* head2=node2;
    insertAtHead(head1,4);
    insertAtHead(head1,2);
    // insertAtHead(head1,9);
    // insertAtHead(head1,9);
    // insertAtHead(head1,9);
    // insertAtHead(head1,9);

    insertAtHead(head2,4);
    insertAtHead(head2,6);
    insertAtHead(head2,5);
    // insertAtHead(head2,1);
    
    // print
    print_LL(head1);
    print_LL(head2);
    
    cout<<endl;

    Node* newNode=addLinkedList(head1,head2);
    print_LL(newNode);
    return 0;
}