// sudoku solver

#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row , int col , vector<vector<int>>& board , int val){
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

bool solve(vector<vector<int>>& board){
    int n = 9;

    for(int row=0 ; row<n ; row++){
        for(int col=0 ; col<n ; col++){

            // empty cell
            if(board[row][col] == 0){
                for(int val=1 ; val<=9 ; val++){
                    if(isSafe(row , col , board , val)){
                        board[row][col] = val;

                        // recursive call
                        bool nextSolution = solve(board);
                        if(nextSolution){
                            return true;
                        }
                        else{
                            // backtrack
                            board[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>>& sudoku)
{
	solve(sudoku);
    
}


int main(){
    int arr[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0} , {5, 2, 0, 0, 0, 0, 0, 0, 0} , {0, 8, 7, 0, 0, 0, 0, 3, 1} , {0, 0, 3, 0, 1, 0, 0, 8, 0} , {9, 0, 0, 8, 6, 3, 0, 0, 5} , {0, 5, 0, 0, 9, 0, 6, 0, 0} , {1, 3, 0, 0, 0, 0, 2, 5, 0} , {0, 0, 0, 0, 0, 0, 0, 7, 4} , {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    int n=9;

    vector<vector<int>>sudoku(n , vector<int>(n,0));

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            sudoku[i][j] = arr[i][j];
        }
    }

    solveSudoku(sudoku);

    for(auto i:sudoku){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}