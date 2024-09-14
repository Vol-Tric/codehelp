// rotten oranges , BFS
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n , vector<bool>(m , false));
        queue<pair<pair<int , int> , int>>q; //queue for BFS {{row , column} , time}
        int freshCount = 0;
        // to add initially rotten oranges to the queue
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == 2){
                    q.push({{i , j} , 0});
                    visited[i][j] = true;
                }
                else if(grid[i][j] == 1){
                    freshCount++;
                }
            }
        }

        // bfs
        int time = 0;
        vector<int>drow = {-1 , 0 , 1 , 0};
        vector<int>dcol = {0 , 1 , 0 , -1};
        int rottenCount = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            time = max(time , t);
            q.pop();

            for(int i=0 ; i<4 ; i++){
                int neighRow = row + drow[i];
                int neighCol = col + dcol[i];
                
                // if the negihbouring row and col are valid , it is never visited before and the orange is fresh
                if(neighRow >= 0 && neighRow < n && neighCol >= 0 && neighCol < m 
                && !visited[neighRow][neighCol] && grid[neighRow][neighCol] == 1){
                    q.push({{neighRow , neighCol} , t + 1});
                    visited[neighRow][neighCol] = true;
                    rottenCount++;

                }
            }
        }

        // // check if any orange is left fresh
        // for(int i=0 ; i<n ; i++){
        //     for(int j=0 ; j<m ; j++){
        //         if(visited[i][j] && grid[i][j] == 1){
        //             return -1;
        //         }
        //     }
        // }

        // return time;

        return (freshCount != rottenCount) ? -1 : time;

        
    }
};

int main(){
    vector<vector<int>>grid = {{2,1,1} , {1,1,0} , {0,1,1}};
    Solution obj;
    int ans = obj.orangesRotting(grid);
    cout<<"the answer is : "<<ans<<endl;
    return 0;
}