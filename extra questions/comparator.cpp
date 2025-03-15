#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<char , int>mp;

    string s = "qwertyuioadfghjkllkjhgfdsapoiuytrewqqazxdrfvgyhnjikm";

    for(auto i : s){
        mp[i]++;
    }

    for(auto i : mp){
        cout<<i.first<<" -> "<<i.second<<endl;
    }

    return 0;

}