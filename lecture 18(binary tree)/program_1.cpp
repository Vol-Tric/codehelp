// creation of binary tree
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

// to print tree 
void levelOrderTraversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL); // seperator added to give it a tree like structure

    while(!q.empty()){
        node* temp=q.front();
        q.pop();

        if(temp==NULL){ //previous level is completely traversed
            cout<<endl;
            if(!q.empty()){ // queue has still left with some child nodes
                q.push(NULL);
            }
        }

        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void reverselevelOrderTraversal(node* root){
    stack<node*>s;
    queue<node*>q;
    q.push(root);
    q.push(NULL); // seperator added to give it a tree like structure

    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        s.push(root);

           
        if(temp->left){
            q.push(temp->left);
        }

        if(temp->right){
            q.push(temp->right);
        }
        
        
    }
    while(!s.empty()){
        root=s.top();
        cout<<root->data<<" ";
        s.pop();
    }
}

// LNR, Left Node Right
void inOrderTraversal(node* root){
    // base case
    if(root==NULL){
        return;
    }

    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right); 
}

// NLR, Node Left Right
void preOrderTraversal(node* root){
    // base case
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// LRN, Left Right Node
void postOrderTraversal(node* root){
    // base case
    if(root==NULL){
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

void buildFromLevelOrderTraversal(node* &root){
    queue<node*>q;
    cout<<"enter data for root"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp=q.front();
        q.pop();

        cout<<"enter left node for "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left=new node(leftData);
            q.push(temp->left);
        }

        cout<<"enter right node for "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData!=-1){
            temp->right=new node(rightData);
            q.push(temp->right);
        }
    }
}

int main(){
    node* root=NULL;

    // // creating a tree
    // root=buildTree(root);

    // data to be put in input
    // 10 5 2 -1 -1 4 -1 -1 15 6 -1 -1 8 -1 -1

    // create tree using level order
    buildFromLevelOrderTraversal(root);
    // 10 5 15 2 4 6 8 -1 -1 -1 -1 -1 -1 -1 -1

    // // level order
    // cout<<endl<<"level order traversal"<<endl;
    // levelOrderTraversal(root);

    // reverse level order traversal
    cout<<endl<<"reverse level order traversal"<<endl;
    reverselevelOrderTraversal(root);

    // cout<<endl<<"inorder traversal"<<endl;
    // inOrderTraversal(root);

    // cout<<endl<<"pre order traversal"<<endl;
    // preOrderTraversal(root);

    // cout<<endl<<"post order traversal"<<endl;
    // postOrderTraversal(root);
    return 0;
}