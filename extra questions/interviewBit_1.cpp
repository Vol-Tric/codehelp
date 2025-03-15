#include<bits/stdc++.h>
using namespace std;

class Solution{
    bool check(vector<int>&A , vector<int>&B , int index){
    
        int n = A.size();
        int count = 0;
        int valueA = 0 , valueB = 0;
        for(int i = index ; i < n ; i++){
            valueA += A[i];
            // valueB += B[i];
            
            if(B[i] > valueA){
                return false;
            }
            
            valueA -= B[i];
            count++;
        }
        
        if(count < n - 1){
            int i = 0;
            while(count == n){
                valueA += A[i];
                // valueB += B[i];
                
                if(B[i] > valueA){
                    return false;
                }
                
                valueA -= B[i];
                count++;
                i++;
            }
        }
        
        if(valueA >= 0){
            return true;
        }
        else{
            return false;
        }
        
        
    }
    public:
    // int canCompleteCircuit(vector<int> &A,vector<int> &B){
    //     int ans = -1;
    //     for(int i = 0 ; i<A.size() ; i++){
    //         if(check(A , B , i)){
    //             ans = i;
    //             break;
    //         }
    //     }
    //     return ans;
    // }

    int canCompleteCircuit(vector<int> &A,vector<int> &B){
        int n = A.size();
        int tank = 0;
        int ans = 0;
        int totalGas = 0;
        int totalDist = 0;
        for(int i=0 ; i<n ; i++){
            totalGas += A[i];
            totalDist += B[i];

            tank = tank + (A[i] - B[i]);
            if(tank < 0){
                ans = i + 1;
                tank = 0;
            }
        }

        if(totalDist > totalGas){
            return -1;
        }
        else{
            return ans;
        }
    }
};

int main(){
    vector<int>A = {2, 3, 4};
    vector<int>B = {3, 4, 3};

    Solution obj;
    int ans = obj.canCompleteCircuit(A , B);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}