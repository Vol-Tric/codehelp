// divide a circular linked list into 2 equal parts
#include<iostream>
#include<vector>
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

void insertNode(Node* &head, int element, int d) {
    

    //empty list
    if(head == NULL) {
        Node* newNode = new Node(d);
        head = newNode;
        newNode -> next = newNode;
    }
    else{
        //non-empty list
        //assuming that the element is present in the list

        Node* curr = head;

        while(curr->data != element) {
            curr = curr -> next;
        }
        
        //element found -> curr is representing element wala node
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;

    }

}    

// split function ,carried out using floyd method(2 pointers, fast and slow)
vector<Node*>split(Node* &head){
    // vector of Node* type created for ans
    vector<Node*>ans;

    // base case
    if(head==NULL){
        ans.push_back(head);
        return ans;
    }

    // 2 pointer fast and slow
    Node* fast=head->next;
    Node* slow=head;

    // traverse both the pointer
    while(fast->next!=head){
        fast=fast->next;
        if(fast->next!=head){
            fast=fast->next;
        }
        slow=slow->next;
    }
    // fast reaches the end of LL and slow reaches the mid point of the LL
    ans.push_back(head);
    // creating second sub LL
    fast->next=slow->next;
    ans.push_back(slow->next);
    // creating 1st sub LL
    slow->next=head;
    return ans;
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

    // insertNode(tail, 7, 8);
    // print(tail);
   
    cout<<endl;
    // printing both of the sub LL
    vector<Node*>ans=split(tail);
    for(int i=0;i<ans.size();i++){
        print(ans[i]);
        cout<<endl;
    }
    

    

    return 0;
}