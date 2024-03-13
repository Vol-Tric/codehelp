// sieve of eratosthenes
// uses:
// used in question where Given an integer n, return the number of prime numbers that are strictly less than n.

// Example 1:
// Input: n = 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

// Working:

// Let us take an example when n = 50. So we need to print all prime numbers smaller than or equal to 50. 
// Step 1: We create a list of all numbers from 2 to 50.
// Step 2:According to the algorithm we will mark all the numbers which are divisible by 2 and are greater than or equal to the square of it.   
// Step 3:Now we move to our next unmarked number 3 and mark all the numbers which are multiples of 3 and are greater than or equal to the square of it.  
// Step 4:We move to our next unmarked number 5 and mark all multiples of 5 and are greater than or equal to the square of it.  
// repeat the steps till no prime number is avaliable

#include<iostream>
#include<vector>
using namespace std;

int countPrimes(int n) {
    int count=0;
    vector<bool>prime(n+1,true);

    prime[0]=prime[1]=false;


    for(int i=2;i<n;i++){

        if(prime[i]){
            count++;
        }
        for(int j=2*i;j<n;j=j+i){
            prime[j]=0;
        }
    }
    return count;
}

int main(){
    int input=50;
    int answer=countPrimes(input);
    cout<<answer;
    return 0;
}