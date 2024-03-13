// search in binary search tree
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

// search using recursion
bool RecursiveSearchInBST(Node* root, int x) {
    // base case
    if(root == NULL){
        return false;
    }
    else if(root->data == x){
        return true;
    }

    else{
        if(x > root->data){
            // traverse right subtree
            RecursiveSearchInBST(root->right, x);
        }

        else{
            // traverse left subtree
            RecursiveSearchInBST(root->left, x);
        }
    }   
}

bool IterativeSearchInBST(Node* root , int x){
    if(root == NULL){
        return false;
    }

    Node* temp = root;

    while(temp != NULL){
        if(temp->data == x){
            return true;
        }
        else if(x > temp->data){
            temp = temp->right;
        }
        else{
            temp = temp->left;
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

    int x = 7;

    cout<<endl<<"recursive search "<<endl;
    cout<<IterativeSearchInBST(root , x);

    cout<<endl<<"recursive search "<<endl;
    cout<<RecursiveSearchInBST(root , x);


    




    return 0;

}
