// normal to balanced BST
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

void inOrderTraversal(Node* root , vector<int> &inorderVal){
    // base case
    if(root==NULL){
        return ;
    }

    inOrderTraversal(root->left , inorderVal);
    inorderVal.push_back(root->data);
    inOrderTraversal(root->right , inorderVal); 
}

Node* inorderToBST(int s , int e , vector<int> inorderVal){
    // base case
    if(s>e){
        return NULL;
    }

    int mid = (s+e)/2;
    Node* root = new Node(inorderVal[mid]);
    root->left = inorderToBST(s, mid-1, inorderVal);
    root->right = inorderToBST(mid+1, e, inorderVal);
    return root;

}
Node* balancedBst(Node* root) {
    // Write your code here.
    vector<int> inorderVal;
    inOrderTraversal(root, inorderVal);

    Node* ans = inorderToBST(0, inorderVal.size()-1, inorderVal);
    return ans;

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
    Node* root = NULL;

    cout<<"enter the data to create a BST"<<endl;
    // function to build tree
    takeInput(root);
    // input
    // 10 9 8 7 6 5 4 3 2 1 -1
    levelOrderTraversal(root);

    Node* ans = balancedBst(root);
    cout<<endl<<"the balanced BST is "<<endl;

    levelOrderTraversal(ans);


    return 0;

}

