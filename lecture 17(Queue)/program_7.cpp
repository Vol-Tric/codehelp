// !st negative integer in every window of size K
#include<bits/stdc++.h>
using namespace std;

vector<int> printFirstNegativeInteger( int A[], int N, int K) {
                 
    deque<int>d;
    vector< int>ans;
    
    // process 1st window
    for(int i=0;i<K;i++){
        if(A[i]<0){
            d.push_back(i);
        }
    }
    
    // store ans of 1st window
    if(d.size()>0){
        ans.push_back(A[d.front()]);
    }
    else{
        ans.push_back(0);
    }
    
    // for rest of windows
    for( int i=K;i<N;i++){
        // removal
        if(!d.empty() && i-d.front() >= K){
            d.pop_front();
        }
        
        // adding
        if(A[i]<0){
            d.push_back(i);
        }
        
        // storing ans
        if(d.size()>0){
            ans.push_back(A[d.front()]);
        }
        else{
            ans.push_back(0);
        }
    }
    return ans;
}

int main(){
    int A[]={-8,2,3,-6,10};
    int N=sizeof(A)/sizeof(A[0]);
    int K=2;
    vector<int>ans=printFirstNegativeInteger(A,N,K);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}