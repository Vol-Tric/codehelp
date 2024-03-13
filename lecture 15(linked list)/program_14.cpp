// check whether the LL is palindrome or not
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

// approach 1, using array
bool checkPalindrome(Node* &head){
    if(head==NULL || head->next==NULL){
        return true;
    }
    vector<int>ans;
    Node* temp=head;
    while(temp){
        ans.push_back(temp->data);
        temp=temp->next;
    }

    int end=ans.size()-1;
    int start=0;
    while(start<end){
        if(ans[start]!=ans[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
    
}

Node* middleNode(Node* &head){
    Node* fast=head->next;
    Node* slow=head;

    while(fast){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
    }
    return slow;
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


// approach 2, for S.C= O(1)
// find middle, reverse rest of the LL starting from middle, compare
bool checkPalindrome_2(Node* &head){
    if(head==NULL || head->next==NULL){
        return true;
    }

    Node* temp=head;
    // find middle of LL
    Node* middle=middleNode(head);
    // reverse the LL starting from the middle
    Node* temp2=reverseList(middle);
    
    // compare both parts
    while(temp && temp2){
        if(temp->data != temp2->data){
            return false;
        }
        temp=temp->next;
        temp2=temp2->next;
    }
    // return the List in orginal condition
    temp=middle->next;
    middle->next=reverseList(temp);
    return true;

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
    Node *node1=new Node(1);
    cout<<node1->data<<endl;
    

    // head pointed to node1
    Node* head=node1;
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,4);
    insertAtHead(head,5);
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    
     // print
    print_LL(head);
    
    cout<<endl;
    
    // bool ans=checkPalindrome(head);
    // cout<<ans<<endl;

    bool ans=checkPalindrome_2(head);

    print_LL(head);
    cout<<endl;
    cout<<ans<<endl;
    
    

    return 0;
}