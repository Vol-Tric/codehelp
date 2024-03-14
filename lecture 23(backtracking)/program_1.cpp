// rat in a maze problem
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<bool>>& visited, vector<vector<int>>& arr, int n) {
    cout << "Checking cell: (" << row << ", " << col << ")" << endl;
    if ((row >= 0 && col <= n - 1) && (row <= n - 1 && col >= 0) && (visited[row][col] != 1) && (arr[row][col] == 1)) {
        return true;
    }
    return false;
}

void solve(int row , int col , vector<vector<int>>& arr , int n , vector<string>& ans , vector<vector<bool>>& visited , string path){
    // base case
    if(row == n-1 && col == n-1){
        cout << "Path found: " << path << endl;
        ans.push_back(path);
        return;
    }

    // 4 movement
    // D , L , R , U
    visited[row][col] = 1;

    // down
    if(isSafe(row+1 , col , visited , arr , n)){      
        solve(row+1 , col , arr , n , ans , visited , path + 'D');
    }

    // left
    if(isSafe(row , col-1 , visited , arr , n)){
        solve(row , col-1 , arr , n , ans , visited , path + 'L');
    }

    // right
    if(isSafe(row , col+1 , visited , arr , n)){
        solve(row , col+1 , arr , n , ans , visited , path + 'R');
    }

    // up
    if(isSafe(row-1 , col , visited , arr , n)){
        solve(row-1 , col , arr , n , ans , visited , path + 'U');
    }
    visited[row][col] = 0;
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string>ans;
    vector<vector<bool>> visited(n, vector<bool>(n,0));
    string path = "";

    if(arr[0][0]==0){
        return ans;
    }

    solve(0 , 0 , arr , n, ans , visited , path);
    return ans;
}

int main() {
    int arr[4][4] = {{1, 0, 0, 0}, {1, 1, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    int n = 4;
    vector<vector<int>> maze(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            maze[i][j] = arr[i][j];
        }
    }

    vector<string> ans;
    ans = searchMaze(maze, n);
    for (auto i : ans) {
        cout << i << endl;
    }

    return 0;
}