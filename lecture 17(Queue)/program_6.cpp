// queue revarsal
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        stack<int>stk;
        while(!q.empty()){
            stk.push(q.front());
            q.pop();
        }
        queue<int>ans;
        while(!stk.empty()){
            ans.push(stk.top());
            stk.pop();
        }
        return ans;
    }
};

int main(){
    Solution s1;
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    queue<int>ans=s1.rev(q);

    while(!ans.empty()){
        cout<<ans.front()<<endl;
        ans.pop();
    }
    return 0;
}