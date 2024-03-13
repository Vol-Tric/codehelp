// merge sort on linked list
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

Node* findMid(Node* head) {
    Node* slow = head;
    Node* fast = head -> next;
    
    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next; 
    }
    return slow;
}


Node* merge(Node* &left, Node* &right) {
    
    if(left == NULL)
        return right;
    
    if(right == NULL)
        return left;
    
    Node* ans = new Node(-1);
    Node* temp = ans;
    
    //merge 2 sorted Linked List
    while(left != NULL && right != NULL) {
        if(left -> data < right -> data ) {
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else
        {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }
    
    while(left != NULL) {
        temp -> next = left;
        temp = left;
        left = left -> next;
    }
    
    while(right != NULL) {
        temp -> next = right;
        temp = right;
        right = right -> next;
    }
    
    ans = ans -> next;
    return ans;
    
}


Node* mergeSort(Node* &head) {
    // Write your code here.
    // base case
    if(head==NULL || head->next==NULL){
        return head;
    }

    // break LL into 2 halfes
    Node* mid=findMid(head);

    Node* left=head;
    Node* right=mid->next;
    mid->next=NULL;

    // recursive calls
    left=mergeSort(left);
    right=mergeSort(right);

    // merge both left and right
    Node* result=merge(left,right);

    return result;

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
    Node *node1=new Node(15);
    cout<<node1->data<<endl;
    

    // head pointed to node1
    Node* head=node1;
    insertAtHead(head,44);
    insertAtHead(head,1);
    insertAtHead(head,5);
    insertAtHead(head,27);
    insertAtHead(head,3);
    insertAtHead(head,20);
    insertAtHead(head,3);
    insertAtHead(head,11);
    insertAtHead(head,10);
    insertAtHead(head,9);
     // print
    print_LL(head);
    
    cout<<endl;
    
    Node* ans=mergeSort(head);
    print_LL(ans);
    
    

    return 0;
}