// check identical trees
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;

    node(int value){
        this->data=value;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildTree(node* root){
    cout<<"enter the data: ";
    int data;
    cin>>data;
    root=new node(data);

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

bool isIdentical(node *r1, node *r2){
    //base case
    if(r1 == NULL && r2 == NULL){
        return true;
    }
    
    if(r1 == NULL && r2 != NULL){
        return false;
    }
    
    if(r1 != NULL && r2 == NULL){
        return false;
    }
    
    
    bool left = isIdentical(r1->left , r2->left);
    bool right = isIdentical(r1->right , r2->right);
    
    bool value = r1->data == r2->data;
    
    if(left && right && value){
        return true;
    }
    else{
        return false;
    }
    
}