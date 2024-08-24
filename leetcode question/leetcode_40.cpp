// combination sum 2
#include<bits/stdc++.h>
using namespace std;

class Solution {
    void solveRecursive(vector<int>&candidates , int target , vector<vector<int>>&ans , vector<int>&temp , int index){
        if(target == 0){
            ans.push_back(temp);
            return ;
        }

        for(int i = index ; i<candidates.size() ; i++){
            if(i > index && candidates[i] == candidates[i-1]){
                continue;
            }
            if(candidates[i] > target){
                break;
            }
            temp.push_back(candidates[i]);
            solveRecursive(candidates , target - candidates[i] , ans , temp , i+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin() , candidates.end());
        solveRecursive(candidates , target , ans , temp , 0);
        return ans;
    }
};

int main(){
    vector<int>candidates = {10,1,2,7,6,1,5};
    int target = 8;

    Solution obj;
    vector<vector<int>>ans = obj.combinationSum2(candidates , target);
    cout<<"answer is "<<endl;
    for(auto i : ans){
        cout<<"[";
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<"]"<<endl;
    }

    return 0;
}