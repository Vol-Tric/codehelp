// design a special stack sich that getmin() works in O(1) TC and O(1) SC
#include<bits/stdc++.h>
using namespace std;

class SpecialStack {
    stack<int>s;
    int mini;
    public:
        
    void push(int data) {
        // insert 1st element;
        if(s.empty()){
            s.push(data);
            mini=data;
        }
        else{
            if(data<mini){
                int val=2*data-mini;
                s.push(val);
                mini=min(mini,data);
            }
            else{
                s.push(data);
            }
        }
    }

    void pop() {
        // underflow condition
        if(s.empty()){
            cout<<"enderflow condition"<<endl;
        }

        else{
            int curr=s.top();
            if(curr>=mini){
                cout<<"elements popped is: "<<s.top()<<endl;
                s.pop();
            }
            else{
                int val=2*mini-curr;
                cout<<"elements popped is: "<<val<<endl;
                mini=curr;
                s.pop();
            }
        }
    }
    int getmin(){
        if(s.empty()){
            return -1;
        }
        else;
        return mini;
    }
};

int main(){
    SpecialStack s1;
    s1.push(5);
    s1.push(3);
    s1.push(8);
    s1.push(2);
    s1.push(4);

    cout<<"popping.."<<endl;
    for(int i=0;i<5;i++){
        s1.pop();
        cout<<s1.getmin()<<endl;
    }

    return 0;
}