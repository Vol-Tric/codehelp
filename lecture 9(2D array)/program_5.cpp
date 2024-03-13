// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.

// Input: matrix = 
//  1,4,7,11,15
//  2,5,8,12,19
//  3,6,9,16,22
//  10,13,14,17,24
//  18,21,23,26,30
// target = 5
// Output: true

#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row=matrix.size();
    int col=matrix[0].size();

    int i=0;
    int j=col-1;

    while(i<row && j>=0){
        if(matrix[i][j]==target){
            return true;
        }
        else if(matrix[i][j]>target){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> vect
    {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };

    int target=5;

    bool ans=searchMatrix(vect,target);

    if(ans==true){
        cout<<"target present";
    }
    else{
        cout<<"target not present";
    }
    return 0;
}
