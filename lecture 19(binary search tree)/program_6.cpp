// find kth smallest element in a BST
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

int solve(Node* root, int &i, int k){
    // base case
    if(root == NULL){
        return -1;
    }

    // L
    int left = solve(root->left , i , k);

    if(left != -1){
        return left;
    }

    // N
    i++;
    if(i == k){
        return root->data;
    }

    // R
    return solve(root->right , i , k);
}
int kthSmallest(Node* root, int k) {
   int i=0;
   int ans = solve(root , i , k);
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
    int ans = kthSmallest(root , k);
    cout<<endl<<"the kth smallest elements of the BST is "<<ans<<endl;


    return 0;

}