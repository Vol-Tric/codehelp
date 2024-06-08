// maximum height by stacking cuboid
// leetcode 1691
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool check(vector<int>&prevBox , vector<int>&currBox){
        if(currBox[0] <= prevBox[0] && currBox[1] <= prevBox[1] && currBox[2] <= prevBox[2]){
            return true;
        }
        return false;
    }

    int solveSpaceOptimized(int n , vector<vector<int>>&arr){
        vector<int>currRow(n+1 , 0);
        vector<int>nextRow(n+1 , 0);

        

        for(int curr = n-1 ; curr >= 0 ; curr--){
            for(int prev = curr-1 ; prev >= -1 ; prev--){

                // include
                int include = 0;
                if(prev == -1 || check(arr[curr] , arr[prev])){
                    include = arr[curr][2] + nextRow[curr + 1]; // prev+1 bcz prev can be -1 , same for curr + 1
                }

                // exclude
                int exclude = 0 + nextRow[prev+1]; // prev+1 bcz prev can be -1

                currRow[prev + 1] = max(include , exclude);
                
            }
            
            nextRow = currRow;
        }
        
        return nextRow[0];
    
    }

public:
    int maxHeight(vector<vector<int>>& cuboids) {
        
        // step 1 , sort each cuboid
        for(auto &i : cuboids){
            sort(i.begin() , i.end());
        }
        // cuboid[n][2] is height , cuboid[n][0] is width
        

        // step 2 , sort the whole 2D vector
        sort(cuboids.begin() , cuboids.end());

        
        // step 3 , use LIS logic
        return solveSpaceOptimized(cuboids.size() , cuboids);


    }
};

int main(){
    vector<vector<int>>cuboids = {{50,45,20},{95,37,53},{45,23,12}};
    // output should be 190
    Solution obj;
    int ans = obj.maxHeight(cuboids);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}