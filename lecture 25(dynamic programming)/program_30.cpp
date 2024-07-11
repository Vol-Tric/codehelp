// buy and sell stock (part 1)
// leetode 121
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // // using tabulation
    // int maxProfit(vector<int>& prices){
    //     int n = prices.size();
    //     if(n == 1){
    //         return 0;
    //     }
    //     vector<int>minArr(n);

    //     minArr[0] = -1;
    //     int mini = prices[0];
    //     for(int i=1 ; i<n ; i++){
    //         if(prices[i] < mini){
    //             minArr[i] = prices[i];
    //             mini = prices[i];
    //         }
    //         else{
    //             minArr[i] = mini;
    //         }
    //     }

    //     int maxProfit = INT_MIN;
    //     for(int i=1 ; i<n; i++){
    //         int temp = prices[i] - minArr[i];
    //         maxProfit = max(maxProfit , temp);
    //     }
    //     return maxProfit;
    // }


    // using space optimized
    int maxProfit(vector<int>& prices){
        int n = prices.size();

        if(n == 1){
            return 0;
        }

        int mini = prices[0];
        int maxProfit = 0;

        for(int i=1 ; i<n ; i++){
            int profit = prices[i] - mini;
            maxProfit = max(maxProfit , profit);
            mini = min(mini , prices[i]);
        }

        return maxProfit;
    }
};

int main(){
    vector<int>prices = {7,1,5,3,6,4};
    Solution obj;
    int ans = obj.maxProfit(prices);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}