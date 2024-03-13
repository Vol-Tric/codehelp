// celebrity problem
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>s;
        // step 1, insert all elements into the stack
        for(int i=0;i<n;i++){
            s.push(i);
        }
        
        // step 2, pop 2 elements and check them
        while(s.size()!=1){
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            
            if(M[a][b]==1){
                s.push(b);
            }
            else if(M[b][a]==1){
                s.push(a);
            }
        }
        
        // step 3, check potential candidate
        int potential_candidate=s.top();
        bool rowCheck=false;
        bool colCheck=false;
        
        int zeroCount=0;
        int oneCount=0;
        for(int i=0;i<n;i++){
            if(M[potential_candidate][i]==0){
                zeroCount++;
            }
            if(M[i][potential_candidate]==1){
                oneCount++;
            }
            
        }
        
        if(zeroCount==n){
            rowCheck=true;
        }
        if(oneCount==n-1){
            colCheck=true;
        }
        
        if(rowCheck && colCheck){
            return potential_candidate;
        }
        else{
            return -1;
        }
    }
};

int main(){
    int n;
    cin>>n;
    
    vector<vector<int>> M(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>M[i][j];
        }
    }

    Solution s1;
    cout<<"celebrity is: "<<s1.celebrity(M,n);
    return 0;
}