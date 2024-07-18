// huffmann coding
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

class cmp{
    public:
    bool operator()(Node* a , Node* b){
        return a->data > b->data;
    }
};



class Solution{
    void traverse(Node* &root , vector<string>&ans , string temp){
        if(!root->left && !root->right){
            ans.push_back(temp);
            return;
        }

        traverse(root->left , ans , temp + '0');
        traverse(root->right , ans , temp + '1');
    }
	public:
    vector<string> huffmanCodes(string S,vector<int> f,int N){
        // Code here
        priority_queue<Node* , vector<Node*> , cmp>pq;
        for(int i=0 ; i<N ; i++){
            Node* temp = new Node(f[i]);
            pq.push(temp);
        }

        while(pq.size() > 1){
            Node* l = pq.top();
            pq.pop();

            Node* r = pq.top();
            pq.pop();

            Node* temp = new Node(l->data + r->data);
            temp->left = l;
            temp->right = r;

            pq.push(temp);
        }

        Node* root = pq.top();
        vector<string>ans;
        string temp = "";
        traverse(root , ans , temp);
        return ans;
    }
};

int main(){
    string S = "abcdef";
    vector<int> f = {5, 9, 12, 13, 16, 45};
    int N = 6;

    Solution obj;
    vector<string> ans = obj.huffmanCodes(S , f , N);
    cout<<"answer is "<<endl;
    for(auto i : ans){
        cout<<i<<endl;
    }
    return 0;

}