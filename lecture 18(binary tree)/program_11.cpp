// sum of longest blood line
// sum of the nodes on the longest path from root to leaf on the tree
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

void solve(node* root , int sum , int &maxSum , int len , int &maxLen ){
    if(root == NULL){
        if(len > maxLen){
            maxLen = len;
            maxSum = sum;
        }
        else if(len == maxLen){
            maxSum = max(sum , maxSum);
        }
        return;
    }
    
    sum = sum + root->data;
    
    solve(root->left , sum , maxSum , len+1 , maxLen);
    solve(root->right , sum , maxSum , len+1 , maxLen);
}

int sumOfLongRootToLeafPath(node *root)
{
    int len = 0;
    int maxLen = 0;
    
    int sum = 0;
    int maxSum = INT_MIN;
    
    solve(root , sum , maxSum , len , maxLen);
    return maxSum;
}

int main(){
    node* root=NULL;
    // creating a tree
    root=buildTree(root);

    // data to be put in input
    // 10 5 2 -1 -1 4 -1 -1 15 6 -1 -1 8 -1 -1

    int ans=sumOfLongRootToLeafPath(root);
    cout<<endl<<"sum of longest path of tree is: "<<ans<<endl;
    return 0;
}