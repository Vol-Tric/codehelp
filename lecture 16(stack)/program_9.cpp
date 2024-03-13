// check for reduntant brackets
// A pair of brackets is said to be redundant when a subexpression is surrounded by needless/ useless brackets.

// For Example :
// ((a+b)) has a pair of redundant brackets. The pair of brackets on the first and last index is needless. 
// While (a + (b*c)) does not have any pair of redundant brackets. 
#include <bits/stdc++.h> 
using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char> st;

    for(int i=0;i<s.length();i++){
        char ch=s[i];

        if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            st.push(ch);
        }

        else{
            if(ch==')'){
                bool isReduntant=true;
                while(st.top()!='('){
                    char top=st.top();
                    if(top=='(' || top=='+' || top=='-' || top=='*' || top=='/'){
                        isReduntant=false;
                    }
                    st.pop();
                }
                if(isReduntant==true){
                    return true;
                }
                st.pop();
            }

        }
    }
    return false;
}

int main(){
    stack<char> stk;
    // string str="(a*b+(c/d))";
    string str="((a/b))";
    

    cout<<endl;
    bool ans=findRedundantBrackets(str);
    cout<<ans<<endl;

    return 0;
}