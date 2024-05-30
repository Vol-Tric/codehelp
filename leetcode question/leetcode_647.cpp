// palindrome substrings
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool checkPalindrome(string s){
        if(s.length() == 0){
            return false;
        }
        int start = 0;
        int end = s.length()-1;
        while(start <= end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
            
        }
        return true;
    }
    void printSubstrings(string s , vector<string>&str){
    
        // First loop for starting index
        for (int i = 0; i < s.length(); i++) {
            string subStr;
            // Second loop is generating sub-string
            for (int j = i; j < s.length(); j++) {
                subStr += s[j];
                str.push_back(subStr);
            }
        }
    }
public:
    int countSubstrings(string s) {
        if(s.length() == 1){
            return 1;
        }
        int count = 0;
        vector<string>str;
        printSubstrings(s , str);
        for(auto i : str){
            if(checkPalindrome(i)){
                count++;
            }
        }
        return count;

    }
};

int main(){
    string s = "aaa";
    // ans should be 6
    Solution obj;
    int ans = obj.countSubstrings(s);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}