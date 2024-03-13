// min and max value in a BST
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

int minOfBST(Node* root){
    if(root == NULL){
        return -1;
    }

    Node* temp = root;

    while(temp->left != NULL){
        temp = temp->left;    
    }
    return temp->data;
}

int maxOfBST(Node* root){
    if(root == NULL){
        return -1;
    }

    Node* temp = root;

    while(temp->right != NULL){
        temp = temp->right;    
    }
    return temp->data;
}

int main(){
    Node* root = NULL;

    cout<<"enter the data to create a BST"<<endl;
    // function to build tree
    takeInput(root);
    // input
    // 10 6 14 2 8 12 16 1 3 7 9 11 13 15 20 -1

    int ans;

    ans = minOfBST(root);
    cout<<endl<<"Min of BST is : "<<ans;

    ans = maxOfBST(root);
    cout<<endl<<"Min of BST is : "<<ans;
    
    


    




    return 0;

}
