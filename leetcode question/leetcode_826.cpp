// most profit assigning work
#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker){

        vector<pair<int , int>>nums(difficulty.size());
        for(int i=0 ; i<difficulty.size() ; i++){
            nums[i] = make_pair(difficulty[i] , profit[i]);
        }

        sort(nums.begin() , nums.end());
        sort(worker.begin() , worker.end());
        int tempProfit = 0;
        int maxProfit = 0;
        int j = 0;
        int n = worker.size();
        for(int i=0 ; i<n ; i++){
            while(j<n && nums[j].first <= worker[i]){
                tempProfit = max(tempProfit , nums[j].second);
                j++;
            }
            if(j>0 && nums[j-1].first <= worker[i]){
                maxProfit += tempProfit;
            }
        }
        return maxProfit;
    }
};

int main(){
    vector<int> difficulty = {2, 4, 6, 8, 10};
    vector<int> profit = {10, 20, 30, 40, 50};
    vector<int> worker = {4, 5, 7, 6};

    solution obj;
    int ans = obj.maxProfitAssignment(difficulty , profit , worker);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}