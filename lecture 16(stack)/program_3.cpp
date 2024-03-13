// reverse a string using stack

#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<char> stk;
    string str;
    cout<<"enter the string: ";
    cin>>str;

    for(int i=0;i<str.length();i++){
        stk.push(str[i]);
    }
    cout<<endl<<"the reversed string is:"<<endl;

    for(int i=0;i<str.length();i++){
        cout<<stk.top();
        stk.pop();
    }

    return 0;
}
