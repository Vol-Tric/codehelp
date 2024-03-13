// create BST from preorder
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

Node* solve(vector<int> &preorder , int mini , int maxi , int &i){
    if(i >= preorder.size()){
        return NULL;
    }

    if(preorder[i] < mini || preorder[i] > maxi){
        return NULL;
    }

    Node* root = new Node(preorder[i++]);
    root->left = solve(preorder , mini , root->data , i);
    root->right = solve(preorder , root->data , maxi , i);
    return root;
}
Node *preorderToBST(vector<int> &preorder) {

    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solve(preorder, mini, maxi, i);
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


int main(){
    vector<int> v;
    v.push_back(20);
    v.push_back(10);
    v.push_back(5);
    v.push_back(15);
    v.push_back(13);
    v.push_back(35);
    v.push_back(30);
    v.push_back(42);

    Node* ans = NULL;
    ans = preorderToBST(v);
    cout<<"BST is"<<endl;
    levelOrderTraversal(ans);
    return 0;

}