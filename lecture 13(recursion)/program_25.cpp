// Tower of Hanoi is a mathematical puzzle where we have three rods (A, B, and C) and N disks. Initially, all the disks are stacked in decreasing value of diameter i.e., the smallest disk is placed on the top and they are on rod A. The objective of the puzzle is to move the entire stack to another rod (here considered C), obeying the following simple rules: 

// Only one disk can be moved at a time.
// Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
// No disk may be placed on top of a smaller disk.
// Examples:

// Input: 2
// Output: Disk 1 moved from A to B
// Disk 2 moved from A to C
// Disk 1 moved from B to C

// Input: 3
// Output: Disk 1 moved from A to C
// Disk 2 moved from A to B
// Disk 1 moved from C to B
// Disk 3 moved from A to C
// Disk 1 moved from B to A
// Disk 2 moved from B to C
// Disk 1 moved from A to C

#include<bits/stdc++.h>
using namespace std;

    void towerOfHanoi(int n,char from_rod, char to_rod, char aux_rod){
        // base case
        if(n==0){
            return ;
        }

        // shift 'n-1' disk from A to B using C
        towerOfHanoi(n-1,from_rod,aux_rod,to_rod);
        // shift last disk to C
        cout<<"move disk "<<n<<" from "<<from_rod<<" to "<<to_rod<<endl;
        // shift 'n-1' disk from B to C using A
        towerOfHanoi(n-1,aux_rod,to_rod,from_rod);

    }
int main() 
{ 
    int N = 3; 
  
    // A, B and C are names of rods 
    // shift disk from A to C using B
    // towerOfHanoi(int n,char from_rod, char to_rod, char aux_rod)
    towerOfHanoi(N, 'A', 'C', 'B'); 
    return 0; 
} 