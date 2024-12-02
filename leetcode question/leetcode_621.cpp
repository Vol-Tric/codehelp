// task scheduler

// time complexity : O(n * log n)
// here log n will be 26 as the heap has to go through at max 26 elements (A - Z)
// therefore the complexity is O(n) , linear
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int leastInterval(vector<char>& tasks , int n){
        vector<int>count(26);
        for(auto i : tasks){
            count[i - 'A']++;
        }

        priority_queue<int>maxHeap;
        for(auto i : count){
            if(i > 0){
                maxHeap.push(i);
            }
            
        }


        int time = 0;
        queue<pair<int , int>>hold;
        while(!maxHeap.empty() || !hold.empty()){
            time++;

            if(maxHeap.empty()){
                time = hold.front().second;
            }
            else{
                int temp = maxHeap.top() - 1;
                maxHeap.pop();
                if(temp > 0){
                    hold.push({temp , time + n});
                }
            }

            if(!hold.empty() && hold.front().second == time){
                maxHeap.push(hold.front().first);
                hold.pop();
            }
        }
        return time;
    }
};


int main(){
    vector<char>tasks = {'A' , 'A' , 'A' , 'B' , 'B' , 'B'};
    int n = 2;

    Solution obj;
    int ans = obj.leastInterval(tasks , n);

    cout<<"answer is : "<<ans<<endl;
    return 0;
}