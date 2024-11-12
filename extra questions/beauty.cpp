#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> countingBeauties(vector<int>& spendings , int k , int x , int n){
        vector<int>ans;
        
        for(int i=0 ; i<n-k+1 ; i++){
            vector<int>pq;
            for(int j = i ; j<k ; j++){
                if(spendings[j] < 0){
                    pq.push_back(spendings[j]);
                    cout<<spendings[j]<<endl;
                }
            }
            sort(pq.begin() , pq.end());

            if(pq[x-1] < 0){
                ans.push_back(pq[x-1]);
            }
            else{
                ans.push_back(0);
            }
        }

        return ans;
    }
};

int main(){
    vector<int>spendings = {-3 , 1 , 2 , -3 , 0 , -3};
    int n = spendings.size();
    int k = 2;
    int x = 1;

    Solution obj;
    vector<int>ans = obj.countingBeauties(spendings , k , x , n);

    for(auto i : ans){
        cout<<i<<" ";
    }

    return 0;
}