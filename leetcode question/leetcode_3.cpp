// longest substring without repeating character
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // int lengthOfLongestSubstring(string s) {
    //     set<char>st;
    //     int left = 0;
    //     int right = 0;
    //     int count = 0;
    //     int ans = 0;

    //     while(left <= right && right < s.length()){
    //         st.insert(s[right]);

    //         if(st.size() != (right - left + 1)){
    //             left++;
    //             right = left;
    //             count = 0;
    //             st.clear();

    //         }
    //         else{   
    //             right++;
    //             count++;
    //             ans = max(ans , count);
    //         }

    //     }
    //     return ans;
    // }


    // smarty approach
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0){
            return 0;
        }
        int ans = 1;
        set<char>st;
        int left = 0;
        int right = 1;
        st.insert(s[0]);
        while(right < s.length()){
            while(st.find(s[right]) != st.end()){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            right++;
            ans = max(ans , int(st.size()));
        }
        return ans;
    }
    // this code runs in such a way that if the new element added to the set i.e. s[right] , is already present in the set , move left forward.
};

int main(){
    string s = "abcabcbb";
    // ans is 3

    Solution obj;
    int ans = obj.lengthOfLongestSubstring(s);
    cout<<"answer is : "<<ans<<endl;
    return 0; 
}