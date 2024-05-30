// n queens problem

#include<bits/stdc++.h>
using namespace std;

void addSolution(vector<vector<int>>& board , vector<vector<int>>& ans ,int n){
    vector<int>temp;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
    
}

// it is to check whether a queen is attacking or not
bool isSafe(int row , int col , vector<vector<int>>& board , int n){
    int x = row;
    int y = col;

    // check for same row
    while(y >= 0){
        if(board[x][y] == 1){
            return false;
        }
        y--;
    }

    x = row;
    y = col;

    // check for diagonal
    while(x >= 0 && y >= 0){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y--;
    }
    x = row;
    y = col;
    while(y >= 0 && x <= n-1){
        if(board[x][y] == 1){
            return false;
        }
        y--;
        x++;
    }

    return true;
    
}

void solve(int col , vector<vector<int>>& ans , vector<vector<int>>& board , int n){
    // base case
    if(col == n){
        addSolution(board , ans , n);
        return;
    }

    // solve 1 case and recursion will take care of rest
    for(int row = 0; row<n ;row++){
        if(isSafe(row , col , board , n)){

            // if placing queen is safe
            board[row][col] = 1;
            solve(col+1 , ans , board , n);

            // backtrack
            board[row][col] = 0;
        }
    }


}

vector<vector<int>> nQueens(int n)
{
	vector<vector<int>>board(n,vector<int>(n,0));
    vector<vector<int>>ans;

    solve(0 , ans , board , n);
    return ans;
	
}

// vector<vector<string>> solveNQueens(int n) {
//     vector<vector<string>>ans(2, vector<string>(n*n,"."));   

//     vector<vector<int>>ans1 = nQueens(n);
//     for(auto i:ans1){
//         for(auto j: i){
//             if(j == 1){
//                 // ans[i][j] = "Q"
//             }
//         }
//     }

//     for(int i=0;i<ans1.size();i++){
//         for(int j=0;j<ans1[i].size();j++){
//             if(ans1[i][j] == 1){
//                 ans[i][j] = "Q";
//             }
//         }
//     }

//     return ans;
// }

int main(){
    int n = 6;
    // for int
    vector<vector<int>>ans = nQueens(n);

    for(auto i:ans){
        int count = 1;
        for(auto j:i){
            cout<<j<<" ";
            if(count%n == 0){
                if(count != 0){
                    cout<<endl;
                }
                
            }
            count++;
        }
        cout<<endl;
    }
    cout<<endl<<endl;


    // // for string
    // vector<vector<string>>ans1 = solveNQueens(n);
    // for(auto i:ans1){
    //     for(auto j:i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}