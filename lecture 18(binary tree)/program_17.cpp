// flatten a binary tree into linked list without using extra space
// we use morris traversal
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

Node* buildTree(Node* root){
    cout<<"enter the data: ";
    int data;
    cin>>data;
    root=new Node(data);

    if(data==-1){
        return NULL;
    }
    // recursive call for left node
    cout<<"enter data for left child of "<<data<<endl;
    root->left=buildTree(root->left);
    // recursive call for right node
    cout<<"enter data for right child of "<<data<<endl;
    root->right=buildTree(root->right);

    return root;
}
void flatten(Node *root){
    Node* curr = root;
    while(curr != NULL){
        
        
        if(curr->left){
            Node* pred = curr->left;
            while(pred->right){
                pred=pred->right;
            }
            pred->right=curr->right;
            curr->right = curr->left;
            curr->left = NULL;
            
        }
        curr = curr->right;
        
    }
    
}

int main(){
    Node* root=NULL;
    // creating a tree
    root=buildTree(root);
    

    // data to be put in input
    // 1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 -1 6 -1 9 -1 10 -1 -1
    
    flatten(root);
    cout<<endl<<"the linked list prints here "<<endl;
    while(root){
        cout<<root->data<<" ";
        root=root->right;
    }
    return 0;
}