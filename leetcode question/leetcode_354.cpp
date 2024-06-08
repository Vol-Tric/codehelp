// russian doll
#include<bits/stdc++.h>
using namespace std;

class Solution {
    
    static bool compare(pair<int , int>&a , pair<int , int>&b){
        if(a.first == b.first){
            return a.second > b.second;
        }
        else{
            return a.first < b.first;
        }
    }

    static bool comp(vector<int>&a , vector<int>&b){
        if(a[0] == b[0]){
            return a[1] > b[1];

        }
        else{
            return a[0] < b[0];
        }
    }
    
    public:

    // // using a vector of pair , increasing space complexity
    // int maxEnvelopes(vector<vector<int>>& envelopes) {
    //     vector<pair<int , int>>arr;

    //     for(auto i : envelopes){
    //         arr.push_back(make_pair(i[0] , i[1]));
    //     }
    //     sort(arr.begin() , arr.end() , compare);

    //     for(auto i : arr){
    //         cout<<i.first<<"  "<<i.second<<endl;
    //     }
    //     vector<int>ans;
    //     ans.push_back(arr[0].second);

    //     for(int i=1 ; i<arr.size() ; i++){
    //         if(arr[i].second > ans.back()){
    //             ans.push_back(arr[i].second);
    //         }
    //         else{
    //             // find index of just larger element in ans
    //             int index = lower_bound(ans.begin() , ans.end() , arr[i].second) - ans.begin();
    //             ans[index] = arr[i].second;
    //         }
    //     }

    //     return ans.size();
    // }

    // using constant space complexity
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin() , env.end() , comp);

        // for(auto i : env){
        //     cout<<i[0]<<"  "<<i[1]<<endl;
        // }

        vector<int>ans;
        ans.push_back(env[0][1]);

        for(int i=1 ; i<env.size() ; i++){
            if(env[i][1] > ans.back()){
                ans.push_back(env[i][1]);
            }
            else{
                // find index of just larger element in ans
                int index = lower_bound(ans.begin() , ans.end() , env[i][1]) - ans.begin();
                ans[index] = env[i][1];
            }
        }

        return ans.size();
    }

};

int main(){
    vector<vector<int>>envelopes = {{5,4} , {6,4} , {6,7} , {2,3}};
    Solution obj;
    int ans = obj.maxEnvelopes(envelopes);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}