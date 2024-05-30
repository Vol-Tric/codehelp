// group anagrams

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string , vector<string>>mp;

        for(auto i : strs){
            string word = i;
            sort(word.begin() , word.end());
            mp[word].push_back(i);
        }

        vector<vector<string>>ans;
        for(auto i : mp){
            ans.push_back(i.second);
        }

        return ans;
    }
};

int main(){
    vector<string>s = {"eat","tea","tan","ate","nat","bat"};
    int numRows = 3;

    

    Solution obj;
    vector<vector<string>> ans = obj.groupAnagrams(s);
    for(auto i : ans){
        for(auto j : i){
            cout<<j<<"   ";
        }
        cout<<endl;
    }


    return 0;
}