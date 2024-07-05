// all ancestors of a node in a DAG
#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int x, int curr, vector<vector<int>>& ans, vector<vector<int>>& directChild) {
        for (int ch : directChild[curr]) {
            if (ans[ch].empty() || ans[ch].back() != x) {
                ans[ch].push_back(x);
                dfs(x, ch, ans, directChild);
            }
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n), directChild(n);
        for (auto& e : edges) {
            directChild[e[0]].push_back(e[1]);
        }
        for (int i = 0; i < n; i++) {
            dfs(i, i, ans, directChild);
        }
        return ans;
    }
};

int main(){
    int n = 8;
    vector<vector<int>> edges = {{0,3},{0,4},{1,3},{2,4},{2,7},{3,5},{3,6},{3,7},{4,6}};

    Solution obj;
    vector<vector<int>>ans;
    ans = obj.getAncestors(n , edges);

    cout<<"answer is "<<endl;
    for(auto i : ans){
        cout<<"[ ";
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<"]  ";
    }
    return 0;
}