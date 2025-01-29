// check subsequence in a string after changes
#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
    bool canMakeSubsequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        if(n > m){
            return false;
        }

        int index2 = 0;
        for(int index1 = 0 ; index1 < m && index2 < n ; index1++){
            if(str1[index1] == str2[index2] ||
            str1[index1] + 1 == str2[index2] || 
            str1[index1] - 25 == str2[index2]){
                index2++;
            }
        }
        return n == index2;
    }
};

int main(){
    string str1 = "abcdefabce";
    string str2 = "defab";

    Solution obj;
    bool ans = obj.canMakeSubsequence(str1 , str2);

    (ans) ? cout<<"yes" : cout<<"no";
    cout<<endl;
    return 0;
}