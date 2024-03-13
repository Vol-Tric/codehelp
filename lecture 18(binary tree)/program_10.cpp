// vertical order traversal
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

vector<int> verticalOrder(node *root){
    map< int , map< int , vector<int> > > nodes;
    queue< pair< node* , pair<int , int> > >q;
    vector<int>ans;
    
    if(root==NULL){
        return ans;
    }
    
    q.push(make_pair(root , make_pair(0 , 0)));
    
    while(!q.empty()){
        pair< node* , pair<int,int>> temp = q.front();
        q.pop();
        node* frontNode = temp.first;
        int hd = temp.second.first;
        int level = temp.second.second;
        
        nodes[hd][level].push_back(frontNode->data);
        
        if(frontNode->left){
            q.push(make_pair(frontNode->left , make_pair(hd-1 , level+1) ) );
        }
        
        if(frontNode->right){
            q.push(make_pair(frontNode->right , make_pair(hd+1 , level+1) ) );
        }
    }
    for(auto i : nodes){
        for(auto j : i.second){
            for(auto k : j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;
}

int main(){
    node* root=NULL;
    // creating a tree
    root=buildTree(root);

    // data to be put in input
    // 10 5 2 -1 -1 4 -1 -1 15 6 -1 -1 8 -1 -1

    vector<int>ans = verticalOrder(root);
    cout<<endl<<"answer is "<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}