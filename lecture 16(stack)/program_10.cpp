// bracket revarsal
// {}{}”, “{{}}”, “{{}{}}” are valid strings while “}{}”, “{}}{{}”, “{{}}}{“ are not valid strings.
// Ninja wants to make ‘STR’ valid by performing some operations on it. In one operation, he can convert ‘{’ into ‘}’ or vice versa, and the cost of one such operation is 1.

// Your task is to help Ninja determine the minimum cost to make ‘STR’ valid.

// sample input
// {{{}
// {{}{}}

// sample output
// 1
// 0
#include<bits/stdc++.h>
using namespace std;
int findMinimumCost(string str) {
  	
    //odd condition
    if(str.length()%2 == 1) {
        return -1;
    }
    
    stack<char> s;
    for(int i=0; i<str.length(); i++) {
        char ch = str[i];
        
        if(ch == '{') 
            s.push(ch);
		else
        {
            //ch is closed brace
            if(!s.empty() && s.top() == '{') {
                s.pop();
            }
            else
            {
                s.push(ch);
            }
        }
    }
    
        //stack contains invalid expression
        int a = 0, b = 0;
        while(!s.empty()) {
            if(s.top() == '{') {
                b++;
            }
            else
            {
                a++;
            }
            s.pop();
        }
        
		int ans = (a+1)/2 + (b+1)/2;
        return ans;
    
    
}
int main(){
    stack<char> stk;
    string str="{{{{";
    // string str="{}}{}}";
    

    cout<<endl;
    int ans=findMinimumCost(str);
    cout<<ans<<endl;

    return 0;
}