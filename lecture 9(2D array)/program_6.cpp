// rotate image
// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

// Input: matrix =
//  [1,2,3]
//  [4,5,6]
//  [7,8,9]
// Output: 
// [7,4,1]
// [8,5,2]
// [9,6,3]

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

void vector_print(vector<vector<int>>& matrix){
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix.size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;   
    }    
}

void rotate(vector<vector<int>>& matrix) {
    int row=matrix.size();

    // transposing the matrix
    for(int i=0;i<row;i++){
        for(int j=0;j<i;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    // reversing the rows
    for(int i=0;i<row;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
}

int main(){
    vector<vector<int>> vect
    {
        {1,2,3},
        {4,5,6},
        {7,8,9},
        
    };

    rotate(vect);
    vector_print(vect);
    return 0;

}