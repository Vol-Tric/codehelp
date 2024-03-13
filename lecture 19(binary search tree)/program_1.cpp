// creation of binary search tree

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

// to print tree 
void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL); // seperator added to give it a tree like structure

    while(!q.empty()){
        Node* temp=q.front();
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

// LNR, Left Node Right
void inOrderTraversal(Node* root){
    // base case
    if(root==NULL){
        return;
    }

    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right); 
}

// NLR, Node Left Right
void preOrderTraversal(Node* root){
    // base case
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// LRN, Left Right Node
void postOrderTraversal(Node* root){
    // base case
    if(root==NULL){
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

int main(){
    Node* root = NULL;

    cout<<"enter the data to create a BST"<<endl;
    // function to build tree
    takeInput(root);
    // input
    // 10 6 14 2 8 12 16 1 3 7 9 11 13 15 20 -1


    cout<<endl<<"the tree using level order traversal is "<<endl;
    levelOrderTraversal(root);

    cout<<endl<<"the tree using inorder traversal is "<<endl;
    inOrderTraversal(root);

    cout<<endl<<"the tree using preorder traversal is "<<endl;
    preOrderTraversal(root);

    cout<<endl<<"the tree using postorder traversal is "<<endl;
    postOrderTraversal(root);




    return 0;

}
