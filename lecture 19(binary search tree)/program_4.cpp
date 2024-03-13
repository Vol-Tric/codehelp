// deletion in BST
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

Node* minOfBST(Node* root){
    if(root == NULL){
        return NULL;
    }

    Node* temp = root;

    while(temp->left != NULL){
        temp = temp->left;    
    }
    return temp;
}


Node* deleteFromBST(Node* root , int val){
    // base case
    if(root == NULL){
        return root;
    }

    if(root->data == val){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // 1 child

        // left child
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // right child
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if(root->left != NULL && root->right != NULL){
            int mini = minOfBST(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right , mini);
        }

    }
    else if(val > root->data){
        root->right = deleteFromBST(root->right , val);
        return root;
    }

    else{
        root->left = deleteFromBST(root->left , val);
        return root;
    }
}

int main(){
    Node* root = NULL;

    cout<<"enter the data to create a BST"<<endl;
    // function to build tree
    takeInput(root);
    // input
    // 10 6 14 2 8 12 16 1 3 7 9 11 13 15 20 -1

    cout<<endl<<"the tree before deletion is "<<endl;
    levelOrderTraversal(root);

    // element to be deleted;
    int del;
    Node* ans = NULL;

    // 0 child
    ans = root;
    del = 13;
    ans = deleteFromBST(ans , del);
    cout<<endl<<"the tree after deletion is "<<endl;
    levelOrderTraversal(ans);

    // 1 child
    ans = root;
    del = 16;
    ans = deleteFromBST(ans , del);
    cout<<endl<<"the tree after deletion is "<<endl;
    levelOrderTraversal(ans);

    // 2 child
    ans = root;
    del = 6;
    ans = deleteFromBST(ans , del);
    cout<<endl<<"the tree after deletion is "<<endl;
    levelOrderTraversal(ans);

    

    return 0;

}
