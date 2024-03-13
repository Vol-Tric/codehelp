// reverse first K elements of queue
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    queue<int> rev(queue<int> q, int k)
    {
        stack<int>stk;
        for(int i=0;i<k;i++){
            stk.push(q.front());
            q.pop();
        }
        
        while(!stk.empty()){
            q.push(stk.top());
            stk.pop();
        }
        return q;
    }
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        int n=q.size();
        q=rev(q,k);
        
        // to bring first (n-k) elements at back
        for(int i=0;i<n-k;i++){
            q.push(q.front());
            q.pop();
        }
        return q;
    }
    
};

int main(){
    Solution s1;
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);

    int k=5;
    queue<int>ans=s1.modifyQueue(q,k);

    while(!ans.empty()){
        cout<<ans.front()<<" ";
        ans.pop();
    }
    return 0;
}