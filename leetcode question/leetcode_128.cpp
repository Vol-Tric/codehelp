// longest consecutive sequence
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>st;
        for(auto i : nums){
            st.insert(i);
        }
        int longest = 0;
        for(auto num : st){
            if(st.find(num-1) == st.end()){
                int curr = 1;
                while(st.find(num+1) != st.end()){
                    curr += 1;
                    num += 1;
                }
                longest = max(curr , longest);
            }
        }
        return longest;
    }
};

int main(){
    vector<int>nums = {0,3,7,2,5,8,4,6,0,1};
    // ans is 9

    Solution obj;
    int ans = obj.longestConsecutive(nums);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}