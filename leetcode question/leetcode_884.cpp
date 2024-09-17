// uncommon words from different streams
#include<bits/stdc++.h>
using namespace std;

class Solution{
    inline static vector<string> divideString(string s){
        stringstream ss(s);

        vector<string>ans;
        while(!ss.eof()){
            string temp;
            ss>>temp;
            ans.push_back(temp);
        }
        ss.clear();
        return ans;
    }
    public:
    static vector<string> uncommonFromSentences(string& s1, string& s2){
        auto str1 = divideString(s1);
        auto str2 = divideString(s2);

        map<string , int>mp;
        for(auto s : str1){
            mp[s]++;
        }
        for(auto s : str2){
            mp[s]++;
        }

        vector<string>ans;
        for(auto i : mp){
            if(i.second == 1){
                ans.push_back(i.first);
            }
        }
        return ans;

    }
};

int main(){
    string s1 = "this apple is sweet";
    string s2 = "this apple is sour";

    Solution obj;
    vector<string>ans = obj.uncommonFromSentences(s1 , s2);
    for(auto i : ans){
        cout<<i<<"  ";
    }
    cout<<endl;
    return 0;
}
