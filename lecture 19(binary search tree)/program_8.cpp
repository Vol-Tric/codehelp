// LCA in a BST
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

Node *LCAinaBST(Node *root, Node *P, Node *Q)
{
    // Write your code here.
    if(root == NULL){
        return NULL;
    }

    
    if(root->data < P->data && root->data < Q->data){
        return LCAinaBST(root->right, P, Q);
    }

    else if(root->data > P->data && root->data > Q->data){
        return LCAinaBST(root->left, P, Q);
    }

    else {
        return root;
    }
    
}

int main(){
    Node* root = NULL;

    cout<<"enter the data to create a BST"<<endl;
    // function to build tree
    takeInput(root);
    // input
    // 10 6 14 2 8 12 16 1 3 7 9 11 13 15 20 -1

    Node* P = new Node(7);
    Node* Q = new Node(14);
    Node* ans = LCAinaBST(root , P , Q);
    cout<<endl<<"the LCA of "<<P->data<<" and "<<Q->data<<" is "<<ans->data<<endl;


    return 0;

}