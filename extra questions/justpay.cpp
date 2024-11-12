#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minMovesToConsolidate(vector<int>& positions, int n) {
    // Sort the positions
    sort(positions.begin(), positions.end());
    
    int minMoves = n;  // Initialize to maximum possible moves
    
    // For each position as potential start
    for (int i = 0; i < n; i++) {
        int start = positions[i];  // Try this as starting position
        int maxEnd = start + n - 1;  // End position if we start here
        int moves = 0;
        
        // Count how many positions in current array
        // are outside our target range [start, maxEnd]
        for (int j = 0; j < n; j++) {
            if (positions[j] < start || positions[j] > maxEnd) {
                moves++;
            }
        }
        
        minMoves = min(minMoves, moves);
    }
    
    return minMoves;
}

int main() {
    vector<int> positions = {3,8,10,15,18,20};
    
    // Calculate and print result
    cout << minMovesToConsolidate(positions, positions.size()) << endl;
    
    return 0;
}