// IPO
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solveRecursive(int k, int w, vector<int>& profits, vector<int>& capital , int index){
        if(k == 0 || index >= capital.size()){
            return w;
        }
        int take = INT_MIN;
        if(capital[index] <= w){
            take = profits[index] + solveRecursive(k-- , w + profits[index] , profits , capital , index++);
        }
        int notTake = solveRecursive(k , w , profits , capital , index++);

        return max(take , notTake);

    }
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        return solveRecursive(k , w , profits , capital , 0);
    }
};

int main(){
    int k = 2;
    int w = 0;
    vector<int>profits = {1,2,3};
    vector<int>capital = {0,1,1};

    Solution obj;
    int ans = obj.findMaximizedCapital(k , w , profits , capital);
    cout<<"answer is : "<<ans<<endl;

    return 0;
}