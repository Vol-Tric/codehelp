// zig-zag traversal
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;

    node(int value){
        this->data=value;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildTree(node* root){
    cout<<"enter the data: ";
    int data;
    cin>>data;
    root=new node(data);

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

vector <int> zigZagTraversal(node* root){
    vector<int>result;
    if(root == NULL){
        return result;
    }
    
    queue<node*> q;
    q.push(root);
    
    bool leftToRight = true;

    while(!q.empty()){
        int size=q.size();
        vector<int>ans(size);
        
        for(int i=0;i<size;i++){
            node* frontNode = q.front();
            q.pop();
            
            int index = leftToRight ? i : size-i-1;
            ans[index]=frontNode->data;
            
            if(frontNode->left){
                q.push(frontNode->left);
            }
            
            if(frontNode->right){
                q.push(frontNode->right);
            }
        }
        // direction change
        leftToRight = !leftToRight;
        
        for(auto i:ans){
            result.push_back(i);
        }
    
    }
    
    return result;
}



int main(){
    node* root=NULL;
    // creating a tree
    root=buildTree(root);

    // data to be put in input
    // 10 5 2 -1 -1 4 -1 -1 15 6 -1 -1 8 -1 -1

    vector<int>ans = zigZagTraversal(root);
    cout<<endl<<"answer is "<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}