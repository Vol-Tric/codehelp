// valid sudoku
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row , int col , vector<vector<char>>& board , char val){
    int n = 9;

    for(int i=0 ; i<n ; i++){
        // row check
        if(board[row][i] == val){
            
            return false;
        }

        // col check
        if(board[i][col] == val){
            
            return false;
        }

        // 3x3 grid check
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val){
            
            return false;
        }
        
    }
    return true;
}

bool solve(vector<vector<char>>& board){
    int n = 9;

    for(int row=0 ; row<n ; row++){
        for(int col=0 ; col<n ; col++){

            // empty cell
            if(board[row][col] != '.'){
                char ch = board[row][col];
                if(!isSafe(row , col , board , ch)){
                    return false;
                }

            }
        }
    }
    return true;
}

bool isValidSudoku(vector<vector<char>>& board) {
        
}