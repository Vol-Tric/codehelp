// 2 sum updated
#include<bits/stdc++.h>
using namespace std;

class Solution{
    bool isPrime(int n){
        int root = sqrt(n) + 1;

        for(int i=2 ; i<root ; i++){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
    public:
    vector<vector<int>>specialPairs(int n){
        vector<vector<int>>ans;

        for(int i=2 ; i < n/2 + 1  ; i++){
            if(isPrime(i) && isPrime(n-i)){
                ans.push_back({i , n-i});
            }
        }
        return ans;
    }
};


int main(){
    int n = 100;
    Solution obj;
    vector<vector<int>>ans = obj.specialPairs(n);

    for(auto i : ans){
        cout<<"["<<i[0]<<" , "<<i[1]<<"]"<<endl;
    }
    return 0;
}