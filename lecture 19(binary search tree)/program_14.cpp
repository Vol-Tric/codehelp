// find a BST out of a binary tree
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


class info{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;

};

info solve(Node* root , int &maxSize){
    // base case
    if(root == NULL){
        return {INT_MIN , INT_MAX , true , 0};
    }

    info left = solve(root->left , maxSize);
    info right = solve(root->right , maxSize);

    info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data , right.maxi);
    currNode.mini = min(root->data , left.mini);

    if(left.isBST && right.isBST && (left.maxi < root->data && root->data < right.mini)){
        currNode.isBST = true;
    }
    else{
        currNode.isBST = false;
    }

    // update answer
    if(currNode.isBST){
        maxSize = max(maxSize , currNode.size);
    }
    return currNode;
}


int largestBST(Node *root) {
    int maxSize = 0;
    info temp = solve(root , maxSize);
    return maxSize;


}