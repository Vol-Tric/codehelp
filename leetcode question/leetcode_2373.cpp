// largest local value in a matrix
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>ans(n-2 , vector<int>(n-2));

        for(int i = 1 ; i<n-1 ; i++){
            for(int j = 1 ; j<n-1;j++){

                int temp = 0;
                for(int k = i-1;k <= i+1 ; k++){
                    for(int l = j-1 ; l <= j+1 ; l++){
                        temp = max(temp , grid[k][l]);
                    }
                }
                ans[i-1][j-1] = temp;
            }
        }
        return ans;
    }
};

int main(){
    int arr[4][4] = {{9,9,8,1},{5,6,2,6},{8,2,6,4},{6,2,2,2}};
    int n = 4;
    vector<vector<int>>grid;
    for(int i = 0 ; i<n ; i++){
        vector<int>temp;
        for(int j = 0 ; j<n ; j++){
            cout<<arr[i][j]<<" ";
            temp.push_back(arr[i][j]);
        }
        cout<<endl;
        grid.push_back(temp);
    }

    
    Solution obj;

    vector<vector<int>>ans = obj.largestLocal(grid);
    cout<<"ans"<<endl<<endl;
    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }


    return 0;
}