// solve sudoku char

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
            if(board[row][col] == '.'){
                for(int val=1 ; val<=9 ; val++){
                    char ch = val +'0';
                    if(isSafe(row , col , board , ch)){
                        board[row][col] = ch;

                        // recursive call
                        bool nextSolution = solve(board);
                        if(nextSolution){
                            return true;
                        }
                        else{
                            // backtrack
                            board[row][col] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku_char(vector<vector<char>>& board) {
    solve(board);
}

int main(){
    int arr[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0} , {5, 2, 0, 0, 0, 0, 0, 0, 0} , {0, 8, 7, 0, 0, 0, 0, 3, 1} , {0, 0, 3, 0, 1, 0, 0, 8, 0} , {9, 0, 0, 8, 6, 3, 0, 0, 5} , {0, 5, 0, 0, 9, 0, 6, 0, 0} , {1, 3, 0, 0, 0, 0, 2, 5, 0} , {0, 0, 0, 0, 0, 0, 0, 7, 4} , {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    int n=9;

    vector<vector<char>>sudoku(n , vector<char>(n,'.'));

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            sudoku[i][j] = arr[i][j] + '0';
        }
    }

    solveSudoku_char(sudoku);

    for(auto i:sudoku){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}
