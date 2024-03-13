// boundry traversal

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

void traverseLeft(node* root, vector<int> &ans){
    if(root == NULL || (root->left == NULL && root->right == NULL) ){
        return ;
    }
    
    ans.push_back(root->data);
    
    if(root->left){
        traverseLeft(root->left , ans);
    }
    
    else{
        traverseLeft(root->right , ans);
    }
}

void traverseLeaf(node* root, vector<int> &ans){
    if(root == NULL){
        return;
    }
    
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
    }
    
    traverseLeaf(root->left , ans);
    traverseLeaf(root->right , ans);
}

void traverseRight(node* root, vector<int> &ans){
    if(root == NULL || (root->left == NULL && root->right == NULL) ){
        return ;
    }
    
    // leaf node tak traverse karo aur fir vapis aao
    if(root->right){
        traverseRight(root->right , ans);
    }
    
    else{
        traverseRight(root->left , ans);
    }
    // wapis aa gye
    ans.push_back(root->data);
}


vector <int> boundary(node *root)
{
    vector<int> ans;
    
    // base case
    if(root == NULL){
        return ans;
    }
    ans.push_back(root->data);
    
    // traverse left side
    traverseLeft(root->left , ans);
    
    // traverse left leaf nodes
    traverseLeaf(root->left , ans);
    
    // traverse right leaf nodes
    traverseLeaf(root->right , ans);
    
    // traverse right side
    traverseRight(root->right , ans);
    
    return ans;
}

int main(){
    node* root=NULL;
    // creating a tree
    root=buildTree(root);

    // data to be put in input
    // 10 5 2 -1 -1 4 -1 -1 15 6 -1 -1 8 -1 -1

    vector<int>ans = boundary(root);
    cout<<endl<<"answer is "<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}