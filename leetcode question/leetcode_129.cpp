// leetcode 129
// You are given the root of a binary tree containing digits from 0 to 9 only.

// Each root-to-leaf path in the tree represents a number.

// For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
// Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value){
        this->val=value;
        this->left=NULL;
        this->right=NULL;
    }
};

void buildFromLevelOrderTraversal(TreeNode* &root){
    queue<TreeNode*>q;
    cout<<"enter data for root"<<endl;
    int data;
    cin>>data;
    root=new TreeNode(data);
    q.push(root);

    while(!q.empty()){
        TreeNode* temp=q.front();
        q.pop();

        cout<<"enter left node for "<<temp->val<<endl;
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left=new TreeNode(leftData);
            q.push(temp->left);
        }

        cout<<"enter right node for "<<temp->val<<endl;
        int rightData;
        cin>>rightData;

        if(rightData!=-1){
            temp->right=new TreeNode(rightData);
            q.push(temp->right);
        }
    }
}



class Solution {
    void numbers(TreeNode* root , vector<int>& nums , int num){
        if(root == NULL){
            return ;
        }

        num = num*10 + root->val;

        if(!root->left && !root->right){
            nums.push_back(num);
            return ;
        }
        // left
        numbers(root->left , nums , num);
        // right
        numbers(root->right , nums , num);
    }
public:
    int sumNumbers(TreeNode* root) {
        vector<int>nums;
        int num = 0;
        numbers(root , nums , num);
        int ans = 0;
        for(auto i : nums){
            ans += i;
        }
        return ans;
    }
};

int main(){
    TreeNode* root=NULL;

    // create tree using level order
    buildFromLevelOrderTraversal(root);
    // 4 9 0 5 1 -1 -1 -1 -1 -1 -1

    Solution obj;
    int ans = obj.sumNumbers(root);

    cout<<"ans is "<<ans<<endl;
    return 0;
}