#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        map<int , int>mp;
        for(int i =0;i<score.size();i++){
            mp[score[i]] = i;
        }

        vector<string>ans(score.size());

        int temp = score.size();

        for(auto it : mp){
            ans[it.second] = to_string(temp--);
        }
        

        for(int i = 0;i<ans.size();i++){
            if(ans[i] == "1"){
                ans[i] = "Gold Medal";
            }

            else if(ans[i] == "2"){
                ans[i] = "Silver Medal";
            }

            else if(ans[i] == "3"){
                ans[i] = "Bronze Medal";
            }
        }

        return ans;

    }
};

int main(){
    int arr[5] = {10 ,3, 8, 9, 4};

    vector<int>score;
    for(auto i : arr){
        score.push_back(i);
    }

    Solution obj;
    vector<string>ans = obj.findRelativeRanks(score);

    for(auto i : ans){
        cout<<i<<" , ";
    }
    cout<<endl;

    return 0;
}