// // merge 2 BST
// it consist 3 different questions in it.
// 1) flatten a BST into doubly Linked List.
// 2) merge 2 sorted DLL.
// 3) create a BST from sorted DLL

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int value){
        this->data=value;
        this->left=NULL;
        this->right=NULL;
    }
};

// flatten a BST into sorted Doubly Linked List
void convertToSortedDLL(Node* root , Node* &head){
    if(root == NULL){
        return;
    }

    convertToSortedDLL(root->right, head);

    root->right = head;
    if(head != NULL){
        head->left = root;
    }
    head = root;

    convertToSortedDLL(root->left, head);
}

// merge 2 sorted DLL into 1
Node* mergeDLL(Node* &head1 , Node* &head2){
    Node* head = NULL;
    Node* tail = NULL;

    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            if(head == NULL){
                head = head1;
                tail = head1;
                head = head1->right;
            }
            else{
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }

        else{
            if(head == NULL){
                head = head2;
                tail = head2;
                head = head2->right;
            }
            else{
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    while(head1 != NULL){
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while(head2 != NULL){
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head1 = head2->right;
    }
    return head;
}

// count number of nodes of LL
int countNodes(Node* head){
    int count = 0;
    while(head){
        count++;
        head = head->right;
    }
    return count;
}

// create a BST from sorted DLL
Node* sortedLLToBST(Node* &head ,int n){
    // base case
    if(n <=0 || head == NULL){
        return NULL;
    }

    Node* left = sortedLLToBST(head , n/2);
    Node* root = head;
    root->left = left;
    head = head->right;

    root->right = sortedLLToBST(head , n - (n/2) - 1);
    return root;

}

// combining function
Node* mergeBST(Node* root1 ,Node* root2){
    Node* head1 = NULL;
    Node* head2 = NULL;

    // flatten BST into LL
    convertToSortedDLL(root1 ,head1);
    convertToSortedDLL(root2 ,head2);

    // merge 2 sorted LL
    Node* head = NULL;
    head = mergeDLL(head1, head2);

    // create BST from LL
    int nodes = countNodes(head);

    Node* root = NULL;
    root = sortedLLToBST(head , nodes);
    return root;

}

// to print tree 
void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL); // seperator added to give it a tree like structure

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        if(temp==NULL){ //previous level is completely traversed
            cout<<endl;
            if(!q.empty()){ // queue has still left with some child nodes
                q.push(NULL);
            }
        }

        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

Node* insertIntoBST(Node* root , int d){
    if(root == NULL){
        root = new Node(d);
        return root ;
    }

    if(d > root->data){
        // insert at right part
        root->right = insertIntoBST(root->right , d);
    }
    else{
        // insert into left part
        root->left = insertIntoBST(root->left , d);
    }
    return root;

}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root , data);
        cin>> data;
    }
}

int main(){
    Node* root1 = NULL;
    Node* root2 = NULL;

    cout<<"enter the data to create 1st BST"<<endl;
    // function to build tree
    takeInput(root1);
    // input
    // 10 6 14 2 8 12 16 1 3 7 9 11 13 15 20 -1

    cout<<endl<<"enter the data to create 2nd a BST"<<endl;
    // function to build tree
    takeInput(root2);
    // input
    // 10 6 14 2 8 12 16 1 3 7 9 11 13 15 20 -1

    Node* ans = NULL;
    ans = mergeBST(root1 , root2);

    cout<<endl<<"the merged tree is "<<endl;
    levelOrderTraversal(ans);

}

