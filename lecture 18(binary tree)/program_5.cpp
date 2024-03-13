// check for Balanced tree
// A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 
// Input:
//       1
//     /
//    2
//     \
//      3 
// Output: 0
// Explanation: The max difference in height
// of left subtree and right subtree is 2,
// which is greater than 1. Hence unbalanced
// Input:
//        10
//      /   \
//     20   30 
//   /   \
//  40   60
// Output: 1
// Explanation: The max difference in height
// of left subtree and right subtree is 1.
// Hence balanced. 

// 2 approaches used

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

int height(node* root){
    // base case
    if(root==NULL){
        return 0;
    }
    
    int left=height(root->left);
    int right=height(root->right);
    
    int ans=max(left,right)+1;
    return ans;
}

// approach 1, TC O(N*N)
bool isBalanced(node *root){
    //  base case
    if(root==NULL){
        return true;
    }
    
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    
    bool diff = abs(height(root->left) - height(root->right)) <= 1;
    
    if(left && right && diff){
        return true;
    }
    else{
        return false;
    }
}

// approach 2, same as of diameter, TC O(N)
pair<bool,int> isBalancedFast(node* root){
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }
    
    pair<bool,int> left =isBalancedFast(root->left);
    pair<bool,int> right =isBalancedFast(root->right);
    
    bool op1 = left.first;
    bool op2 = right.first;
    bool op3 = abs(left.second - right.second) <= 1;
    
    pair<bool,int> ans;
        
    ans.second = max(left.second , right.second) + 1;
    if(op1 && op2 && op3){
        ans.first=true;
    }
    else{
        ans.first=false;
        
    }
    return ans;
}
// returning function of approach 2
bool isBalanced_2(node* root){
    return isBalancedFast(root).first;
}


int main(){
    node* root=NULL;
    // creating a tree
    root=buildTree(root);

    // data to be put in input
    // 10 5 2 -1 -1 4 -1 -1 15 6 -1 -1 8 -1 -1

    bool ans=isBalanced(root);
    cout<<endl<<ans<<endl;

    bool ans1=isBalanced_2(root);
    cout<<endl<<ans1<<endl;
    return 0;
}