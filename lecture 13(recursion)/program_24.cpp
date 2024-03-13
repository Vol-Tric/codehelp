#include<bits/stdc++.h>
using namespace std;
class Solution{
    private:
    bool isSafe(int x, int y, int n,vector<vector<int>> &visited,vector<vector<int>>& m ){
        if((x>=0 && x<n) && (y>=0 && y<n) && (visited[x][y]==0)  && (m[x][y]==1)){
            return true;
        }
        return false;
    }
    
    void solve(vector<vector<int>> m, int n,vector<string>& ans,int src_x, int src_y, vector<vector<int>> &visited, string path){
        // base case
        if(src_x==n-1 && src_y==n-1){
            ans.push_back(path);
            return ;
        }
        // marking the visited block 
        visited[src_x][src_y]=true;
        
        int new_x,new_y;
        
        // down
        new_x=src_x+1;
        new_y=src_y;
        if(isSafe(new_x,new_y,n,visited,m)){
            path.push_back('D');
            solve(m,n,ans,new_x,new_y,visited,path);
            // pop for backtracking
            path.pop_back();
        }
        
        // up
        new_x=src_x-1;
        new_y=src_y;
        if(isSafe(new_x,new_y,n,visited,m)){
            path.push_back('U');
            solve(m,n,ans,new_x,new_y,visited,path);
            // pop for backtracking
            path.pop_back();
        }
        
        // left
        new_x=src_x;
        new_y=src_y-1;
        if(isSafe(new_x,new_y,n,visited,m)){
            path.push_back('L');
            solve(m,n,ans,new_x,new_y,visited,path);
            // pop for backtracking
            path.pop_back();
        }
        
        // right
        new_x=src_x;
        new_y=src_y+1;
        if(isSafe(new_x,new_y,n,visited,m)){
            path.push_back('R');
            solve(m,n,ans,new_x,new_y,visited,path);
            // pop for backtracking
            path.pop_back();
        }
        
        
        
        // demarking the visited block
        // for next use
        visited[src_x][src_y]=false;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        vector<string>ans;
        if(m[0][0]==0){
            return ans;
        }
        int src_x=0;
        int src_y=0;
        // initialize 2D array visited in the right way
        //         vector<vector<int>> visited: This declares a 2D vector named visited. Each element of this vector is a vector of integers (vector<int>).

        // (n, vector<int>(n, 0)): This part initializes the outer vector (visited) with n elements. Each of these elements is itself a vector of integers initialized with n elements, each initialized to 0.

        // vector<int>(n, 0): This creates a vector of integers with n elements, each initialized to 0.
        // (n, ... ): This repeats the creation of the inner vector n times to initialize the outer vector with n elements.
        // So effectively, this line initializes a 2D vector visited with dimensions n x n and sets all elements to 0, indicating that no cell has been visited initially.
        vector<vector<int>> visited(n, vector<int>(n, 0));
        
        
        string path="";
        solve(m,n,ans,src_x,src_y,visited,path);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
    Solution sol1;
    vector<vector<int>> m={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    int n=4;;
    vector<string>ans;
    ans=sol1.findPath(m,n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;

}