// create queue using stl
#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    cout<<"size: "<<q.size()<<endl;
    cout<<"front: "<<q.front()<<endl;
    
    while(!q.empty()){
        cout<<"size: "<<q.size()<<endl;
        cout<<"front: "<<q.front()<<endl;
        cout<<endl;
        q.pop();
    }
    return 0;
    
}