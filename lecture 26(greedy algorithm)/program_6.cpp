// job sequencing
#include<bits/stdc++.h>
using namespace std;

// struct Job { 
//     int id;	 // Job Id 
//     int dead; // Deadline of job 
//     int profit; // Profit if job is over before or on deadline 
// };

// // using the struct
// class Solution {
//     static bool cmp(Job a , Job b){
//         return a.profit > b.profit;
//     }
//     public:
//     //Function to find the maximum profit and the number of jobs done.
//     vector<int> JobScheduling(Job arr[], int n) { 
//         // your code here
//         sort(arr , arr+n , cmp);

//         int maxDeadline = INT_MIN;
//         for(int i=0 ; i<n ; i++){
//             maxDeadline = max(maxDeadline , arr[i].dead);
//         }

//         vector<int>schedule(maxDeadline + 1 , -1);

//         int count = 0;
//         int maxProfit = 0;
//         for(int i=0 ; i<n ; i++){
//             int currProfit = arr[i].profit;
//             int currJobID = arr[i].id;
//             int currDeadline = arr[i].dead;

//             for(int k = currDeadline ; k > 0 ; k--){
//                 if(schedule[k] == -1){
//                     schedule[k] = currJobID;
//                     maxProfit += currProfit;
//                     count++;
//                     break;
//                 }
//             }
//         }
//         return {count , maxProfit};
//     } 
// };


// using vector<vector<int>>
class Solution {
    static bool cmp(vector<int> a , vector<int> b){
        return a[2] > b[2];
    }
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(vector<vector<int>>arr, int n) { 
        // arr[i][0] = id;	 
        // arr[i][1] = dead; 
        // arr[i][2] = profit;

        sort(arr.begin() , arr.end() , cmp);

        int maxDeadline = INT_MIN;
        for(int i=0 ; i<n ; i++){
            maxDeadline = max(maxDeadline , arr[i][1]);
        }

        vector<int>schedule(maxDeadline + 1 , -1);

        int count = 0;
        int maxProfit = 0;
        for(int i=0 ; i<n ; i++){
            int currProfit = arr[i][2];
            int currJobID = arr[i][0];
            int currDeadline = arr[i][1];

            for(int k = currDeadline ; k > 0 ; k--){
                if(schedule[k] == -1){
                    schedule[k] = currJobID;
                    maxProfit += currProfit;
                    count++;
                    break;
                }
            }
        }
        return {count , maxProfit};
    } 
};

// // using the struct
// int main(){
//     int n = 4;
//     Job arr[n];
//     arr[0].id = 1 , arr[0].dead = 4 , arr[0].profit = 20;
//     arr[1].id = 2 , arr[1].dead = 1 , arr[1].profit = 10;
//     arr[2].id = 3 , arr[2].dead = 1 , arr[2].profit = 40;
//     arr[3].id = 4 , arr[3].dead = 1 , arr[3].profit = 30;

//     Solution obj;
//     vector<int>ans = obj.JobScheduling(arr , n);
//     cout<<"answer is "<<endl;
//     for(auto i : ans){
//         cout<<i<<endl;
//     }
//     return 0;
// }


// using vector<vector<int>>
int main(){
    int n = 4;
    vector<vector<int>>arr = {{1,4,20} , {2,1,10} , {3,1,40} , {4,1,30}};

    Solution obj;
    vector<int>ans = obj.JobScheduling(arr , n);
    cout<<"answer is "<<endl;
    for(auto i : ans){
        cout<<i<<endl;
    }
    return 0;
}