// spiral matrix
// Given an m x n matrix, return all elements of the matrix in spiral order.
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// 1 2 3
// 4 5 6
// 7 8 9

// Output: [1,2,3,6,9,8,7,4,5]

#include<iostream>
#include<vector>

using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int>ans;
    int row=matrix.size();
    int col=matrix[0].size();

    int count=0;
    int total=row*col;

    //index initialization
    int startingRow=0;
    int startingCol=0;
    int endingRow=row-1;
    int endingCol=col-1;

    while(count<total){

        // print starting row
        for(int index=startingCol;count<total && index<=endingCol;index++){
            ans.push_back(matrix[startingRow][index]);
            count++;
        }
        startingRow++;

        // print ending column
        for(int index=startingRow;count<total && index<=endingRow;index++){
            ans.push_back(matrix[index][endingCol]);
            count++;
        }
        endingCol--;

        // print ending Row
        for(int index=endingCol;count<total && index>=startingCol;index--){
            ans.push_back(matrix[endingRow][index]);
            count++;
        }
        endingRow--;

        // print starting column
        for(int index=endingRow;count<total && index>=startingRow;index--){
            ans.push_back(matrix[index][startingCol]);
            count++;
        }
        startingCol++;
    }
    return ans;
}
int main(){
    vector<vector<int>> vect
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int>final=spiralOrder(vect);
    for(int i=0;i<final.size();i++){
        cout<<final[i]<<" ";
    }
    return 0;
}