// Program to Find Union, Intersection and ring-sum of 2 graphs
#include<bits/stdc++.h>

using namespace std;

// Function to perform matrix addition
vector<vector<int>> matrixAddition(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    return result;
}

// Function to perform matrix multiplication
vector<vector<int>> matrixMultiplication(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

// Function to find the union of two graphs
vector<vector<int>> findUnion(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    return matrixAddition(A, B);
}

// Function to find the intersection of two graphs
vector<vector<int>> findIntersection(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] * B[i][j];
        }
    }

    return result;
}

// Function to find the ring-sum of two graphs
vector<vector<int>> findRingSum(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    return matrixMultiplication(A, B);
}

// Function to display a matrix
void displayMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example adjacency matrices for two graphs
    vector<vector<int>> graphA = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };

    vector<vector<int>> graphB = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };

    cout << "Graph A:" << endl;
    displayMatrix(graphA);
    cout << endl;

    cout << "Graph B:" << endl;
    displayMatrix(graphB);
    cout << endl;

    cout << "Union of Graph A and Graph B:" << endl;
    displayMatrix(findUnion(graphA, graphB));
    cout << endl;

    cout << "Intersection of Graph A and Graph B:" << endl;
    displayMatrix(findIntersection(graphA, graphB));
    cout << endl;

    cout << "Ring-Sum of Graph A and Graph B:" << endl;
    displayMatrix(findRingSum(graphA, graphB));
    cout << endl;

    return 0;
}
