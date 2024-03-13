// inorder predecessor ans successor
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

pair<int, int> predecessorSuccessor(Node *root, int key)
{
    // find the key
    Node* temp = root;
    int succ = -1;
    int pred = -1;

    while(temp->data != key){
        
        if(temp->data > key){
            succ = temp->data;
            temp = temp->left;
            
        }
        else{
            pred = temp->data;
            temp = temp->right;
            
        }
    }

    // pred , max of left subtree
    Node* leftTemp = temp->left;
    while(leftTemp){
        pred = leftTemp->data;
        leftTemp = leftTemp->right;
    }

    // succ , min of right subtree
    Node* rightTemp = temp->right;
    while(rightTemp){
        succ = rightTemp->data;
        rightTemp = rightTemp->left;

    }

    pair<int,int> ans = make_pair(pred , succ);
    
    return ans;



}

int main(){
    Node* root = NULL;

    cout<<"enter the data to create a BST"<<endl;
    // function to build tree
    takeInput(root);
    // input
    // 10 6 14 2 8 12 16 1 3 7 9 11 13 15 20 -1

    int k = 3;
    pair<int,int> ans = predecessorSuccessor(root , k);
    cout<<endl<<"the inorder predecessor and successor of "<<k<<" is "<<ans.first<<" "<<ans.second<<endl;


    return 0;

}