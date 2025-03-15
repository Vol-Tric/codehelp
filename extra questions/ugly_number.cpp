#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // int ugly(int n){
    //     int count = 0;
    //     int ans = 0;
    //     int i=1;
    //     while(true){
    //         if(count == n){
    //             break;
    //         }
    //         if(i % 2 == 0 ||
    //         i % 3 == 0 ||
    //         i % 5 == 0){
    //             ans = i;
    //             count++;
    //         }
    //         i++;

    //     }
    //     return ans;   
    // }

    // int uglyNumber(int n){
    //     priority_queue<long , vector<long> , greater<long>>minHeap;
    //     unordered_set<long>seen;

    //     minHeap.push(1);
    //     seen.insert(1);

    //     vector<int>products = {2,3,5};
    //     long ugly = 1;
    //     for(int i=1 ; i<=n ; i++){
    //         ugly = minHeap.top();
    //         minHeap.pop();

    //         for(auto pro : products){
    //             long newUgly = ugly * pro;
    //             if(!seen.count(newUgly)){
    //                 minHeap.push(newUgly);
    //                 seen.insert(newUgly);
    //             }
    //         }
    //     }

    //     return ugly;
    // }

    int uglyNumber(int n){
        vector<int>ugly(n + 1);

        ugly[0] = 1;
        int index2 = 0 , index3 = 0 , index5 = 0;

        for(int i=1 ; i<=n ; i++){
            int temp = min({ugly[index2] * 2 , ugly[index3] * 3 , ugly[index5] * 5});

            ugly[i] = temp;

            if(ugly[i] == ugly[index2] * 2) {index2++;}
            if(ugly[i] == ugly[index3] * 3) {index3++;}
            if(ugly[i] == ugly[index5] * 5) {index5++;}
        }

        return ugly[n-1];
    }

};

int main(){
    int n = 120;
    Solution obj;
    int ans = obj.uglyNumber(n);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}