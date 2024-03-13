// burning tree
// Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
// Note: The tree contains unique values.

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

Node* buildTree(Node* root){
    cout<<"enter the data: ";
    int data;
    cin>>data;
    root=new Node(data);

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

class Solution {
    // create nodeToParent mapping
    // return target node
    Node* createMapping(Node* root , int target , map<Node*,Node*> &nodeToParent ){
        Node* res =NULL;
        
        queue<Node*> q;
        q.push(root);
        nodeToParent[root] = NULL;
        
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            
            if(front->data == target){
                res = front;
            }
            
            if(front->left){
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            
            if(front->right){
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
            
            
        }
        return res;
    }
    
    void burnTree(Node* root , map<Node*,Node*> &nodeToParent , int &ans){
        map<Node*,bool>visited;
        queue<Node*>q;
        
        q.push(root);
        visited[root] = true;
        
        while(!q.empty()){
            bool flag=0;
            
            int size = q.size();
            for(int i=0;i<size;i++){
                
                // process neighbouring nodes
                Node* front = q.front();
                q.pop();
                
                // check left child
                if(front->left && !visited[front->left]){
                    q.push(front->left);
                    visited[front->left] = true;
                    flag=1;
                }
                
                // check right child
                if(front->right && !visited[front->right]){
                    q.push(front->right);
                    visited[front->right] = true;
                    flag=1;
                }
                
                // check parent node
                if(nodeToParent[front] && !visited[nodeToParent[front]]){
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = true;
                    flag=1;
                }
            }
            if(flag == 1){
                ans++;
            }
        }
    }
    
  public:
    int minTime(Node* root, int target) 
    {
        //algo
        // step 1 : create nodeToParent mapping , done using level Order Traversal
        // step 2 : find target node
        // step 3 : burn tree in min time
        
        int ans=0;
        map<Node*,Node*> nodeToParent;
        Node* targetNode = createMapping(root , target , nodeToParent);
        burnTree(targetNode , nodeToParent , ans);
        return ans;
        
    }
};

int main(){
    Node* root=NULL;
    // creating a tree
    root=buildTree(root);
    Solution obj;

    // data to be put in input
    // 1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 -1 6 -1 9 -1 10 -1 -1
    int target;
    cout<<endl<<"enter the target node: ";
    cin>>target;
    int ans=obj.minTime(root,target);
    cout<<endl<<"minimum time required to burn the whole binary tree is : "<<ans<<endl;
    return 0;
}