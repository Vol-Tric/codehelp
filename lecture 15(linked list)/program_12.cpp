// sort LL with 0,1,2 only as elements
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

// approach 1, count number of each zero, ones and twos, and the place them accordingly
// done using replacing the data
void sort_LL(Node* &head){
    if(head==NULL){
        return;
    }

    int zeroCount=0;
    int oneCount=0;
    int twoCount=0;

    Node* temp=head;
    // 1st loop is to count
    while(temp){
        if(temp->data==0){
            zeroCount++;
        
        }
        else if(temp->data==1){
            oneCount++;
            
        }
        else if(temp->data==2){
            twoCount++;
            
        }
        temp=temp->next;
    }
    // second loop is to replace data at each node accordingly
    temp=head;
    while(temp){
        if(zeroCount!=0){
            temp->data=0;
            zeroCount--;
        }
        else if(oneCount!=0){
            temp->data=1;
            oneCount--;
        }
        else if(twoCount!=0){
            temp->data=2;
            twoCount--;
        }
        temp=temp->next;
    }
}

// function of 2nd approach
void insertAtTail(Node* &tail, Node* &curr){
    tail->next=curr;
    tail=curr;
}

// 2nd approach, we create 3 seperate LL and then merge them, no replacement of data occurs
void sort_LL_2(Node* &head){

    // 6 pointer ready initially pointing at dummy
    Node* zeroHead=new Node(-1);
    Node* zeroTail=zeroHead;
    Node* oneHead=new Node(-1);
    Node* oneTail=oneHead;
    Node* twoHead=new Node(-1);
    Node* twoTail=twoHead;

    Node* curr=head;

    // seperate list created
    while(curr){
        if(curr->data==0){
            insertAtTail(zeroTail,curr);
        }
        else if(curr->data==1){
            insertAtTail(oneTail,curr);
        }
        else if(curr->data==2){
            insertAtTail(twoTail,curr);
        }
        curr=curr->next;
    }

    // connect the seperate list into one
    
    // is ones LL is NULL
    if(oneHead->next==NULL){
        zeroTail->next=twoHead->next;
    }
    zeroTail->next=oneHead->next;

    // connecting twos LL, no clause for it to be NULL as it is the ending LIST
    oneTail->next=twoHead->next;
    // make last elements as NULL
    twoTail->next=NULL;

    // redifine head
    head=zeroHead->next;
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
    Node *node1=new Node(2);
    cout<<node1->data<<endl;
    

    // head pointed to node1
    Node* head=node1;
    insertAtHead(head,1);
    insertAtHead(head,0);
    insertAtHead(head,0);
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtHead(head,0);
    insertAtHead(head,2);
     // print
    print_LL(head);
    
    cout<<endl;
    // sort_LL(head);
    // print_LL(head);

    sort_LL_2(head);
    print_LL(head);
    
    

    return 0;
}