// // construct a tree from inorder and preorder
// #include<bits/stdc++.h>
// using namespace std;

// class node{
//     public:
//     int data;
//     node *left;
//     node *right;

//     node(int value){
//         this->data=value;
//         this->left=NULL;
//         this->right=NULL;
//     }
// };
// class Solution{
    
//     void mapping(int in[] , map<int,int> &nodeToIndex , int n){
//         for(int i=0;i<n;i++){
//             nodeToIndex[in[i]] = i;
//         }
//     }
    
//     node* solve(int in[],int pre[],int preOrderIndex, int inOrderStart, int inOrderEnd, int n , map<int,int> nodeToIndex){
//         if(preOrderIndex >= n || inOrderStart > inOrderEnd){
//             return NULL;
//         }
        
//         int element = pre[preOrderIndex++];
//         node* root = new node(element);
//         int position = nodeToIndex[element];
        
//         // recursive calls
//         root->left = solve(in , pre , preOrderIndex , inOrderStart , position-1 , n , nodeToIndex);
//         root->right = solve(in , pre , preOrderIndex , position+1 , inOrderEnd , n , nodeToIndex);
        
//         return root;
        
//     }
    
    
    
//     public:
//     node* buildTree(int in[],int pre[], int n)
//     {
//         int preOrderIndex = 0;
//         map<int,int> nodeToIndex;
//         // create map for inorder
//         mapping(in , nodeToIndex , n);
//         node* ans = solve(in , pre , preOrderIndex , 0 , n-1 , n , nodeToIndex);
//         return ans;
//     }
    
    
// };