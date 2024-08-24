// minimum cost to convert string
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solveRecursive(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost , int index){
        // base case
        if(index < 0)
    }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
    }
};

int main(){
    string source = "abcd";
    string target = "acbe";
    vector<char>original = {'a','b','c','c','e','d'};
    vector<char>changed = {'b','c','b','e','b','e'};
    vector<int>cost = {2,5,5,1,2,20};

    Solution obj;
    long long ans = obj.minimumCost(source , target , original , changed , cost);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}