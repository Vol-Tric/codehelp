// word search (leetcode 79)
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool dfs(vector<vector<char>>& board , string word , int row , int col , int index){
        if(index == word.size()){
            return true;
        }

        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index]){
            return false;
        }

        char temp = board[row][col];
        board[row][col] = '*'; // mark the cell as visited

        // explore all four directions
        vector<pair<int , int>>offsets = {{0,1} , {1,0} , {0,-1} , {-1,0}};
        for(auto offset : offsets){
            int newRow = row + offset.first;
            int newCol = col + offset.second;
            if(dfs(board , word , newRow , newCol , index+1)){
                return true;
            }
        }

        board[row][col] = temp; //restore original value
        return false;

    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < m ; col++){
                if(dfs(board , word , row , col , 0)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    vector<vector<char>> board =  {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    string word = "SEE";

    Solution obj;
    bool ans = obj.exist(board , word);
    (ans) ? cout<<"true" : cout<<"false";
    cout<<endl;
    return 0;
}