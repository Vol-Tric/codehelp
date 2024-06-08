// replace words
#include<bits/stdc++.h>
using namespace std;


class Solution {
    vector<string>splitWord(string str){
        int n = str.length();
        string word = "";
        vector<string>ans;
    
        for (int i = 0; i < n; i++) {  
            if (str[i] == ' ' or i == (n - 1)) {    
                ans.push_back(word);
                word = "";
            }
            else {
                word += str[i];
            }
        }
        return ans;
    }
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        map<char , string>mp;
        for(auto i : dictionary){
            mp[i[0]] = i;
        }
        string ans = "";
        vector<string>temp;
        temp = splitWord(sentence);

        for(auto i : temp){
            if(mp.find(i[0]) != mp.end() && i.length() >= mp[i[0]].length()){

                ans.append(mp[i[0]]);
                ans.append(" ");
        
            }
            else{
                ans.append(i);
                ans.append(" ");
            }
        }
        ans.pop_back();
        return ans;
    }
};

int main(){
    vector<string>dictionary = {"cat","bat","rat"};
    string sentence = "the cattle was rattled by the battery";

    Solution obj;
    string ans = obj.replaceWords(dictionary , sentence);
    cout<<endl;
    cout<<ans;
    cout<<endl;
    return 0;
}