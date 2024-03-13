// circular tour
// Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
// 1. The amount of petrol that every petrol pump has.
// 2. Distance from that petrol pump to the next petrol pump.
// Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
// Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.\

// Example 1:
// Input:
// N = 4
// Petrol = 4 6 7 4
// Distance = 6 5 3 5
// Output: 1
// Explanation: There are 4 petrol pumps with
// amount of petrol and distance to next
// petrol pump value pairs as {4, 6}, {6, 5},
// {7, 3} and {4, 5}. The first point from
// where truck can make a circular tour is
// 2nd petrol pump. Output in this case is 1
// (index of 2nd petrol pump).

#include<bits/stdc++.h>
using namespace std;

struct petrolPump{
    int petrol;
    int distance;
};

class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
        // deficit, to store the balance till the point from where the balance goes -ve
        int deficit=0;
        int balance=0;
        int start=0;
       
       
        for(int i=0;i<n;i++){
            balance += p[i].petrol - p[i].distance;
            
            if(balance<0){
                deficit += balance;
                start = i+1;
                balance = 0;
            }
        }
        
        // we only run a single loop and verify the balance with deficit for the remaining elements 
        // i.e. starting from start=3, balance till then was -1, so deficit is 2. At the end of the loop if balance + deficit >= 0 , => the circle can be completed, therefore no need to go again
        // balance = 3, deficit = -1, =>balance + deficit = 2 which is >=0
        // therefore, circle can be completed;
        if(deficit+balance >= 0){
            return start;
        }
        
        else{
            return -1;
        }
        
        
    }
};

int main(){
    int n=6;
    // initializing struct
    petrolPump p[n];
    
    // creating entries for struct
    p[0].petrol=6;
    p[0].distance=5;
    p[1].petrol=7;
    p[1].distance=6;
    p[2].petrol=4;
    p[2].distance=7;
    p[3].petrol=10;
    p[3].distance=8;
    p[4].petrol=6;
    p[4].distance=6;
    p[5].petrol=5;
    p[5].distance=4;

    Solution s1;

    int ans=s1.tour(p,n);
    cout<<"ans: "<<ans<<endl;
    return 0;


}

