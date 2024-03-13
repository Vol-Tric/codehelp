// interleaf queue
// example
// input q={11,12,13,14,15,16,17,18}
// output q={11,15,12,16,13,17,14,18}

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    queue<int> interleafUsingQueue(queue<int>q){
        int n=q.size();

        // step 1, put 1st half of q into another queue q1
        queue<int>q1;
        for(int i=0;i<n/2;i++){
            q1.push(q.front());
            q.pop();
        }

        // step 2, interleaf both queues into q
        while(!q1.empty()){
            q.push(q1.front());
            q1.pop();
            q.push(q.front());
            q.pop();
        }
        return q;
    }

    queue<int> interleafUsingStack(queue<int>q){
        int n=q.size();

        // step 1, put 1st half of queue int a stack
        stack<int>s;
        for(int i=0;i<n/2;i++){
            s.push(q.front());
            q.pop();
        }

        //step 2, insert s back into q
        while(!s.empty()){
            q.push(s.top());
            s.pop();  
        }

        // step 3, insert 1st half of q at the back of q
        for(int i=0;i<n/2;i++){
            q.push(q.front());
            q.pop();
        }

        // step 4, again insert 1st half of q into s
        for(int i=0;i<n/2;i++){
            s.push(q.front());
            q.pop();
        }

        // step 5, interleaf
        while(!s.empty()){
            q.push(s.top());
            s.pop();  
            q.push(q.front());
            q.pop();
        }
        return q;
    }
};

int main(){
    queue<int>q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);

    Solution obj;

    queue<int>ans1=obj.interleafUsingQueue(q);
    while(!ans1.empty()){
        cout<<ans1.front()<<" ";
        ans1.pop();
    }

    cout<<endl;
    queue<int>ans2=obj.interleafUsingStack(q);
    while(!ans2.empty()){
        cout<<ans2.front()<<" ";
        ans2.pop();
    }
    return 0;

}