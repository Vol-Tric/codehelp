// LCA, lowest common ancestor
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

node* lca(node* root ,int n1 ,int n2 ){
    //base case
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    
    node* leftAns = lca(root->left , n1 , n2);
    node* rightAns = lca(root->right , n1 , n2);
    
    if(leftAns != NULL && rightAns != NULL){
        return root;
    }
    
    else if(leftAns == NULL && rightAns != NULL){
        return rightAns;
    }
    
    else if(leftAns != NULL && rightAns == NULL){
        return leftAns;
    }
}

int main(){
    node* root=NULL;
    // creating a tree
    root=buildTree(root);

    // data to be put in input
    // 10 5 2 -1 -1 4 -1 -1 15 6 -1 -1 8 -1 -1
    int n1 = 4;
    int n2 = 1;
    node* ans=lca(root , n1 ,n2);
    cout<<endl<<"LCA of "<<n1<<" ans "<<n2<<" is: "<<ans->data<<endl;
    return 0;
}
