// diameter, also called width, is the number of nodes on the longest path between 2 end nodes of the tree
// 2 approaches used for diameter
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

// approach 1, TC O(N*N), because 2 functions are called
int diameter(node* root) {
    // Your code here
    if(root==NULL){
        return 0;
    }
    
    int op1=diameter(root->left);
    int op2=diameter(root->right);
    int op3=height(root->left)+1+height(root->right);
    
    int ans=max(op1 , max(op2 , op3));
    return ans;
}

// approach 2, using a pair
pair<int,int> diameterFast(node* &root){
    // base case
    if(root==NULL){
        pair<int,int> p=make_pair(0,0);
        return p;
    }

    pair<int,int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root->right);

    int op1=left.first;
    int op2=right.first;
    int op3=left.second + right.second + 1;

    pair<int,int>ans;
    ans.first = max(op1 , max(op2 , op3));
    ans.second = max(left.second , right.second) + 1;
    return ans;
}

// returning function of approach 2
int diameter_2(node* &root){
    return diameterFast(root).first;
}

int main(){
    node* root=NULL;
    // creating a tree
    root=buildTree(root);

    // data to be put in input
    // 10 5 2 -1 -1 4 -1 -1 15 6 -1 -1 8 -1 -1

    int ans1=diameter(root);
    cout<<endl<<"diameter of tree is: "<<ans1<<endl;

    int ans2=diameter_2(root);
    cout<<endl<<"diameter of tree is: "<<ans2<<endl;
    return 0;
}