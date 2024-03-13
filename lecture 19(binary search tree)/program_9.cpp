// 2 sum in a BST
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

bool twoSumInBST(Node* root, int target) {
	//Write your code here
    vector<int> inorderVal;
    inOrderTraversal(root, inorderVal);
    int i=0;
    int j=inorderVal.size()-1;
    while(i<j){
        if(inorderVal[i] + inorderVal[j] == target){
            return true;
        }

        else if(inorderVal[i] + inorderVal[j] < target){
            i++;
        }

        else if(inorderVal[i] + inorderVal[j] > target){
            j--;
        }
    }
    return false;
}

int main(){
    Node* root = NULL;

    cout<<"enter the data to create a BST"<<endl;
    // function to build tree
    takeInput(root);
    // input
    // 10 6 14 2 8 12 16 1 3 7 9 11 13 15 20 -1

    int target = 37;
    bool ans = twoSumInBST(root , target);
    if(ans){
        cout<<endl<<"true";
    }
    else{
        cout<<endl<<"false";
    }


    return 0;

}

