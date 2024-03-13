// check if a tree is a heap tree
#include<bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    int nodeCount(struct Node* root){
        if(root == NULL){
            return 0;
        }
        
        int ans = 1 + nodeCount(root->left) + nodeCount(root->right);
        return ans;
    }
    
    bool isCBT(struct Node* root , int index , int count){
        if(root == NULL){
            return true;
        }
        
        if(index >= count){
            return false;
        }
        else{
            bool left = isCBT(root->left , 2*index+1 , count);
            bool right = isCBT(root->right , 2*index+2 , count);
            return (left && right);
        }
        return false;
        
    }
    
    bool maxHeap(struct Node* root){
        if(root->left == NULL && root->right == NULL){
            return true;
            
        }
        if(root->right == NULL){
            return (root->data > root->left->data);
        }
        
        else{
            bool left = maxHeap(root->left);
            bool right = maxHeap(root->right);
            return (left && right && (root->data > root->left->data && root->data > root->right->data));
        }
    }
  public:
    bool isHeap(struct Node* tree) {
        // code here
        int index = 0;
        int count = nodeCount(tree);
        return (isCBT(tree , index , count) && maxHeap(tree) );
    }
};