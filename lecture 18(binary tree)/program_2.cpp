// count leaf nodes
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

void inOrderTraversal(node* &root, int &count){
    // base case
    if(root==NULL){
        return;
    }

    inOrderTraversal(root->left,count);

    // check for leaf node
    if(root->left==NULL && root->right==NULL){
        count++;
    }
    inOrderTraversal(root->right,count); 
}

int countLeafNodes(node* &root){
    int count=0;
    inOrderTraversal(root, count);
    return count;
}

int main(){
    node* root=NULL;

    // creating a tree
    root=buildTree(root);

    // data to be put in input
    // 10 5 2 -1 -1 4 -1 -1 15 6 -1 -1 8 -1 -1

    int ans=countLeafNodes(root);
    cout<<endl<<"number of leaf nodes are: "<<ans<<endl;
    return 0;
}
