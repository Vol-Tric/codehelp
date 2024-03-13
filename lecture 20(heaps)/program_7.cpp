//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // min heap
        priority_queue<long long int, vector<long long int>, greater<long long int>> minheap;
        for(int i=0;i<n;i++){
            minheap.push(arr[i]);
        }
    
        long long int cost = 0;
        while(minheap.size()!=1){
            long long int ans = minheap.top();
            cout<<minheap.top()<<" added to ans "<<endl;
            minheap.pop();
            ans += minheap.top();
            cout<<minheap.top()<<" added to ans "<<endl;
            minheap.pop();
            minheap.push(ans);
            cost += ans;
           
            cout<<"ans is "<<ans<<endl;
            cout<<"cost is "<<cost<<endl;
            
        }
        return cost;
    }
};


int main(){
    Solution obj;
    long long int min[4]={3,2,4,1};
    long long int ans = obj.minCost(min,4);
    cout<<ans<<endl;
}