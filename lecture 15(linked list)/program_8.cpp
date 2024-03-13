// detect a loop in a give linked list
// to remove loop from linked list
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    //constrcutor
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }

};

void insertNode(Node* &tail, int element, int d) {
    

    //empty list
    if(tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        //non-empty list
        //assuming that the element is present in the list

        Node* curr = tail;

        while(curr->data != element) {
            curr = curr -> next;
        }
        
        //element found -> curr is representing element wala node
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;

    }

}    

// method 1 (using map) to detect cycle
bool checkLoop(Node* &head){
    if(head==NULL || head->next==NULL){
        return false;
    }

    map<Node*,bool>visited;
    Node* temp=head;
    while(temp->next!=head || temp!=NULL){
        // cycle present
        if(visited[temp]==true){
            cout<<"present on element "<<temp->data<<endl;
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}

// method 2 (using floyd cycle) to detect cycle
bool loopDetectionFloydCycle(Node* &head){
    if(head==NULL || head->next==NULL){
        return false;
    }

    Node* fast=head;
    Node* slow=head;

    while(slow->next!=head || slow!= NULL){
        if(fast==slow){
            return true;
        }
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;

    }
    return false;
}

// find starting node of loop using floyd method
Node* loopStartingFloydCycle(Node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* fast=head;
    Node* slow=head;

    while(slow->next!=head || slow!= NULL){
        if(fast==slow){
            slow=head;
            break;
        }
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;

    }

    while(slow->next!=head || slow!= NULL){
        if(fast==slow){
            return fast;
        }
        fast=fast->next;
        slow=slow->next;
    }
    return fast;
}

// to remove loop
void removeLoop(Node* &head){
    if(head==NULL){
        return ;
    }

    Node* startOfLoop=loopStartingFloydCycle(head);
    Node* temp=startOfLoop;

    while(temp->next!=startOfLoop){
        temp=temp->next;
    }
    temp->next=NULL;
    cout<<"Loop removed"<<endl; 
}

void print(Node* tail) {

    Node* temp = tail;

    //empty list
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }

    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);

    cout << endl;
} 

void deleteNode(Node* &tail, int value) {

    //empty list
    if(tail == NULL) {
        cout << " List is empty, please check again" << endl;
        return;
    }
    else{
        //non-empty

        //assuming that "value" is present in the Linked List
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        //1 Node Linked List
        if(curr == prev) {
            tail = NULL;
        }

        //>=2 Node linked list
        else if(tail == curr ) {
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;

    }

}




int main() {

    Node* tail = NULL;

    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);


    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    insertNode(tail, 5, 6);
    print(tail);
    
    insertNode(tail, 9, 10);
    print(tail);

    insertNode(tail, 3, 4);
    print(tail);
    
    // bool check=checkLoop(tail);
    // if(check==0){
    //     cout<<"Loop is not present "<<endl;
    // }
    // else{
    //     cout<<"Loop Present"<<endl;
    // }    

    bool check=loopDetectionFloydCycle(tail);
    if(check==0){
        cout<<"Loop is not present "<<endl;
    }
    else{
        cout<<"Loop Present"<<endl;
    }  

    Node* newNode(tail);
    cout<<"cycle present at node: "<<newNode->data<<endl; 

    removeLoop(tail);
    check=loopDetectionFloydCycle(tail);
    if(check==0){
        cout<<"Loop is not present "<<endl;
    }
    else{
        cout<<"Loop Present"<<endl;
    }
    
    
    return 0;
}