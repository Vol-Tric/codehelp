#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int minExercise(int e , int n , vector<int>exercise){
        priority_queue<int>pq;
        for(auto i : exercise){
            pq.push(i);
            pq.push(i);
        }

        int count = 0;
        while(!pq.empty()){
            if(pq.top() <= e){
                e -= pq.top();
                cout<<"heap top : "<<pq.top()<<endl;
                cout<<"energy : "<<e<<endl;
                pq.pop();
                count++;
            }
            if(e == 0){
                break;
            }
            else if(pq.top() > e && e > 0){
                pq.pop();
            }
        }

        return (e > 0) ? -1 : count;
    }
};

int main(){
    int e = 2;
    int n = 3;
    vector<int>exercise = {1,5,2};
    Solution obj;
    int ans = obj.minExercise(e , n , exercise);

    cout<<"answer is : "<<ans<<endl;
    return 0;
}