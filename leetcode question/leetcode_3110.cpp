// score of a string

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreOfString(string s) {
        int ans = 0;
        for(int i=0 ; i<s.length() -1 ; i++){
            int temp = abs(int(s[i]) - int(s[i+1]));
            ans += temp;
        }
        return ans;
    }
};

int main(){
    string s = "hello";
    // ans should be 13
    Solution obj;
    int ans = obj.scoreOfString(s);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}