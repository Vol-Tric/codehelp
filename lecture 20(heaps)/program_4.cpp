// heap using priority queue
// by default it is max heap
#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int> p;
    p.push(54);
    p.push(53);
    p.push(55);
    p.push(52);
    p.push(50);

    cout<<"element at top "<<p.top()<<endl;

    p.pop();
    cout<<"element at top "<<p.top()<<endl;

    cout<<"size "<<p.size()<<endl;

    while(!p.empty()){
        cout<<p.top()<<" ";
        p.pop();
    }cout<<endl;

    // for minheap
    cout<<"minheap"<<endl;
    priority_queue<int, vector<int>, greater<int>> minheap;
    minheap.push(54);
    minheap.push(53);
    minheap.push(55);
    minheap.push(52);
    minheap.push(50);

    cout<<"element at top "<<minheap.top()<<endl;

    minheap.pop();
    cout<<"element at top "<<minheap.top()<<endl;

    cout<<"size "<<minheap.size()<<endl;

    while(!minheap.empty()){
        cout<<minheap.top()<<" ";
        minheap.pop();
    }cout<<endl;


    return 0;




}