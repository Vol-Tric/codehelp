// validate a BST
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

bool isBST(Node *root , int min , int max){
    if(root == NULL){
        return true;
    }
    if(root->data > min && root->data < max){
        bool left = isBST(root->left , min , root->data);
        bool right = isBST(root->right , root->data , max);
        return left && right;
    }

    return false;
}
bool validateBST(Node *root) {
    // Write your code here
    return isBST(root , INT_MIN , INT_MAX);
}

int main(){
    Node* root = NULL;

    cout<<"enter the data to create a BST"<<endl;
    // function to build tree
    takeInput(root);
    // input
    // 10 6 14 2 8 12 16 1 3 7 9 11 13 15 20 -1

    bool ans = validateBST(root);
    if(ans){
        cout<<endl<<"it is a valid BST"<<endl;
    }
    else{
        cout<<endl<<"it is not a valid BST"<<endl;
    }


    return 0;

}