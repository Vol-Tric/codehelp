// remove duplicate from linked list sorted and unsorted
#include<iostream>
#include<map>
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

Node* removeDuplicateSorted(Node* &head){
    if(head==NULL){
        return head;
    }

    Node* curr=head;
    Node* check=head->next;

    while(check!=NULL){
        if(curr->data==check->data){
            check=check->next;
            // delete(curr->next);
            curr->next=check;

        }
        else{
            curr=check;
            check=check->next;
        }
    }
    return head;
}

// unsorted LL approach 1, nested loops
Node* removeDuplicateUnsorted_1(Node* &head){
    if(head==NULL){
        return head;
    }

    Node* curr=head;
    

    while(curr!=NULL){
        Node* check=curr->next;
        Node* prev=check;

        while(check!=NULL){
            if(curr->data==check->data){
                prev->next=check->next;
                delete(check);
                check=prev->next;
                // delete(curr->next);
            }
            else{
                prev=check;
                check=check->next;
            }
        }
        curr=curr->next;
    }
    return head;
}

// method 2, using map<int,bool> keeping the data of visited nodes
Node* removeDuplicateUnsorted_2(Node* &head){
    if(head==NULL){
        return head;
    }

    // map consist of int that stores data of node and bool that tells if visited or not
    map<int,bool> visited;
    
    Node* curr=head;
    Node* prev=NULL;

    while(curr!=NULL){
        if(visited[curr->data]==true){
            prev->next=curr->next;
            // delete(curr);
            curr=prev->next;
        }
        else{
            visited[curr->data]=true;
            prev=curr;
            curr=curr->next;
        }
    }
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
    // // create a node
    // Node *node1=new Node(60);
    // cout<<node1->data<<endl;
    

    // // head pointed to node1
    // Node* head=node1;
    // insertAtHead(head,50);
    // insertAtHead(head,50);
    // insertAtHead(head,40);
    // insertAtHead(head,40);
    // insertAtHead(head,40);
    // insertAtHead(head,30);
    // insertAtHead(head,30);
    // insertAtHead(head,20);
    // insertAtHead(head,20);
    // insertAtHead(head,10);
    //  // print
    // print_LL(head);

    
    // Node* newHead=removeDuplicateSorted(head);
    // print_LL(newHead);


    // Node *node1=new Node(60);
    // cout<<node1->data<<endl;
    

    // // head pointed to node1
    // Node* head=node1;
    // insertAtHead(head,30);
    // insertAtHead(head,20);
    // insertAtHead(head,10);
    // insertAtHead(head,20);
    // insertAtHead(head,40);
    // insertAtHead(head,50);
    // insertAtHead(head,40);
    // insertAtHead(head,30);
    // insertAtHead(head,20);
    // insertAtHead(head,10);
    //  // print
    // print_LL(head);

    
    // Node* newHead=removeDuplicateUnsorted_1(head);
    // print_LL(newHead);


    Node *node1=new Node(60);
    cout<<node1->data<<endl;
    

    // head pointed to node1
    Node* head=node1;
    insertAtHead(head,30);
    insertAtHead(head,20);
    insertAtHead(head,10);
    insertAtHead(head,20);
    insertAtHead(head,40);
    insertAtHead(head,50);
    insertAtHead(head,40);
    insertAtHead(head,30);
    insertAtHead(head,20);
    insertAtHead(head,10);
     // print
    print_LL(head);

    
    Node* newHead=removeDuplicateUnsorted_2(head);
    print_LL(newHead);

    return 0;
}
