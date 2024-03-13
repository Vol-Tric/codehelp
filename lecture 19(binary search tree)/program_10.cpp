// flatten a BST into a Sorted LL
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

void inOrder(Node* root , vector<Node*> &inorderNode){
    if(root == NULL){
        return ;
    }

    inOrder(root->left , inorderNode);
    inorderNode.push_back(root);
    inOrder(root->right, inorderNode);
}

Node* flatten(Node* root)
{
    // creating a vector of Nodes
    vector<Node*> inorderNode;
    // storing inorder traversal into vector
    inOrder(root , inorderNode);

    int size = inorderNode.size();

    // traversing the whole vector except last element
    for (int i = 0; i < size - 1; i++) {
        inorderNode[i]->left = NULL;
        inorderNode[i]->right = inorderNode[i+1];
    }
    // last element of vector
    inorderNode[size-1]->left = NULL;
    inorderNode[size-1]->right = NULL;

    // returning 1st element of vector
    return inorderNode[0];
}

int main(){
    Node* root = NULL;

    cout<<"enter the data to create a BST"<<endl;
    // function to build tree
    takeInput(root);
    // input
    // 10 6 14 2 8 12 16 1 3 7 9 11 13 15 20 -1

    Node* ans = flatten(root);
    cout<<endl<<"the linked list is "<<endl;

    while(ans){
        cout<<ans->data<<" ";
        ans = ans->right;
    }



    return 0;
}