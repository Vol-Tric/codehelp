// insersection of 2 arrays (2)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;

        map<int , int>mp1;
        map<int , int>mp2;

        for(auto i : nums1){
            mp1[i]++;
        }

        for(auto i : nums2){
            mp2[i]++;
        }

        // cout<<"first map"<<endl;
        // for(auto i : mp1){
        //     cout<<i.first<<"  "<<i.second<<endl;
        // }
        // cout<<"second map"<<endl;
        // for(auto i : mp2){
        //     cout<<i.first<<"  "<<i.second<<endl;
        // }

        for(auto i : mp1){
            if(mp2.find(i.first) != mp2.end()){
                int temp = min(mp1[i.first] , mp2[i.first]);
                for(int k = 0 ; k < temp ; k++){
                    ans.push_back(i.first);
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<int>nums1 = {1,2,2,1};
    vector<int>nums2 = {2,2};
    // Output: [2,2]
    Solution obj;
    vector<int>ans = obj.intersect(nums1 , nums2);
    cout<<endl<<"answer is "<<endl;
    for(auto i : ans){
        cout<<i<<"  ";
    }
    return 0;
}