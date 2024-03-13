// check sum tree
// value of node = sum of left subtree + sum of right subtree

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

pair<bool,int> isSumTreeFast(node* root){
    // base case
    if(root == NULL){
        pair<bool,int> p =make_pair(true,0);
        return p;    
    }
    // leaf node
    if(root->left == NULL && root->right == NULL){
        pair<bool,int> p =make_pair(true,root->data);
        return p;    
    }
    
    pair<bool,int> left = isSumTreeFast(root->left);
    pair<bool,int> right = isSumTreeFast(root->right);
    
    bool op1 = left.first;
    bool op2 = right.first;
    bool op3 = (left.second + right.second) == root->data;
    
    pair<bool,int> ans;
    ans.second = root->data + left.second + right.second;
    
    if(op1 && op2 && op3){
        ans.first=true;
    }
    else{
        ans.first=false;
    }
    return ans;
}

bool isSumTree(node* root){
        
    return isSumTreeFast(root).first;
}

int main(){
    node* root=NULL;
    // creating a tree
    root=buildTree(root);

    // data to be put in input
    // 10 5 2 -1 -1 4 -1 -1 15 6 -1 -1 8 -1 -1

    bool ans=isSumTree(root);
    cout<<endl<<ans<<endl;

    
    return 0;
}