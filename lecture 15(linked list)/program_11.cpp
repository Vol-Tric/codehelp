// split linked list in parts
// Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.
// The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.
// The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.
// Return an array of the k parts.

// example
// Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
// Output: [[1,2,3,4],[5,6,7],[8,9,10]]
// Explanation:
// The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.

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

// function to get length of the LL
int getLength(Node* &head){
    int len=0;
    Node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;
}

// function to split the LL
vector<Node*>splitListToParts(Node* &head, int k){

    int listlength=getLength(head);
    int partSize=listlength / k;
    int extraNodes=listlength % k;
    // this means that answer consist 'k' number of elements of type 'Node*' with initial value = NULL
    vector<Node*> answer(k,NULL);
    // 2 pointers to traverse the LL
    Node* curr=head;
    Node* prev=NULL;

    // this loop will run k times used to create k sublist
    // also "curr && i<k" means that the value of i will only be incremented if ,curr!=NULL and i<k
    for(int i=0;curr && i<k;i++){
        // current node added into the answer
        answer[i]=curr;

        // this loop will run for each sub LL adding desired number of elements to it
        // "(extraNodes>0 ? 1 : 0)" this is a conditional statement that works such a way, that if extraNodes>0 is true, return 1 else return 0
        
        for(int count=1; count<= partSize + (extraNodes>0 ? 1 : 0); count++){
            prev=curr;
            curr=curr->next;
        }

        prev->next=NULL;

        extraNodes--;
    }
    return answer;
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
    Node *node1=new Node(110);
    cout<<node1->data<<endl;
    

    // head pointed to node1
    Node* head=node1;
    insertAtHead(head,100);
    insertAtHead(head,90);
    insertAtHead(head,80);
    insertAtHead(head,70);
    insertAtHead(head,60);
    insertAtHead(head,50);
    insertAtHead(head,40);
    insertAtHead(head,30);
    insertAtHead(head,20);
    insertAtHead(head,10);
     // print
    print_LL(head);
    
    cout<<endl;
    
    vector<Node*>ans=splitListToParts(head,3);
    for(int i=0;i<ans.size();i++){
        print_LL(ans[i]);
        cout<<endl;
    }

    return 0;
}