// k-th smallest prime fraction
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<double>check(arr.size());
        for(int i = 0 ; i < arr.size() ; i++){
            check[i] = double(arr[i]);
        }
        map<double  , pair<double , double>> mp;

        for(int i = 0 ; i < check.size() ; i++){
            for(int j = i + 1 ; j<check.size() ; j++){
                
                double temp = check[i]/check[j];
                mp[temp] = make_pair(check[i],check[j]);
            }
        }

        vector<int>ans;
        for(auto it : mp){
            if(k == 1){
                ans.push_back(it.second.first);
                ans.push_back(it.second.second);
                break;
            }
            k--;
        }
        return ans;
    }
};

int main(){

    int arr[4] = {1,2,3,5};
    vector<int>array;
    for(auto i : arr){
        array.push_back(i);
    }

    int k = 3;

    Solution obj;
    vector<int> ans = obj.kthSmallestPrimeFraction(array , k);

    for(auto i : ans){
        cout<<i<<" ";
    }
    cout<<endl;


    return 0;
}