// minimum cost of ropes (using min heap)
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long  , vector<long long> , greater<long long>>pq;

        for(auto i=0 ; i < n ; i++){
            pq.push(arr[i]);
        }

        long long count = 0;
        while(pq.size() > 1){
            long long top1 = pq.top();
            pq.pop();
            long long top2 = pq.top();
            pq.pop();

            long long temp = top1 + top2;
            count += temp;
            pq.push(temp);
        }

        return count;
    }
};

int main(){
    long long arr[] = {4, 2, 7, 6, 9};
    long long n = 5;
    Solution obj;
    long long ans = obj.minCost(arr , n);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}