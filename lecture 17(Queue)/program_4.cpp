// doubly ended queue using stl
#include<iostream>
#include<queue>
using namespace std;

int main(){
    deque<int>d;

    d.push_front(10);
    d.push_front(20);
    d.push_back(30);
    d.push_back(40);
    cout<<d.back()<<endl;
    cout<<d.front()<<endl;
    return 0;
    
}