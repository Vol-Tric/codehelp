// star of a graph
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int u1 = edges[0][0];
        int v1 = edges[0][1];

        int u2 = edges[1][0];
        int v2 = edges[1][1];

        if(u1 == u2 || u1 == v2){
            return u1;
        }
        else{
            return v1;
        }

        return 0;
    }
};

int main(){
    vector<vector<int>>edges = {{1,2} , {5,1} , {1,3} , {1,4}};
    Solution obj;
    int ans = obj.findCenter(edges);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}