// sort array in increasing frequency
#include<bits/stdc++.h>
using namespace std;

class Solution {
    static bool cmp(pair<int , int>a , pair<int , int>b){
        if(a.second < b.second){
            return true;
        }
        else if(a.second == b.second){
            return a.first > b.first;
        }
        else{
            return false;
        }
    }
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int , int>mp;
        for(auto i : nums){
            mp[i]++;
        }

        vector<pair<int , int>>vp;

        for(auto i : mp){
            vp.push_back(make_pair(i.first , i.second));
        }

        sort(vp.begin() , vp.end() , cmp);

        vector<int>ans;
        for(auto i : vp){
            for(int j=0 ; j<i.second ; j++){
                ans.push_back(i.first);
            }   
        }
        return ans;
    }
};


int main(){
    vector<int>nums = {1,1,2,3,2,2};
    Solution obj;
    vector<int>ans = obj.frequencySort(nums);

    cout<<"answer is "<<endl;
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}