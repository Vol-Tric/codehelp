// // count sort
// step 1 : create a map with frequency of each element (create a vector)
// step 2 : create a prefix sum vector based on that map (vector<int>sum)
// step 3 : traverse the original array backwards , get the a[i] element , go to sum[a[i]] , and decrement it by 1 (sum[a[i]] - 1) , now put a[i] in that position in the answer array which is sorted


#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> countSort(vector<int>nums){
        int n = nums.size();
        int maxEle = *max_element(nums.begin() , nums.end());

        vector<int>count(maxEle + 1 , 0);

        for(auto i : nums){
            count[i]++;
        }

        vector<int>ans(n , 0);

        int index = 0;
        for(int i=0 ; i<=maxEle ; i++){
            while(count[i] > 0){
                ans[index++] = i; 
                count[i]--;
            }
        }
        return ans;
    }
};

int main(){
    vector<int>nums = {1,3,2,3,4,1,6,4,3};
    Solution obj;
    vector<int>ans = obj.countSort(nums);

    cout<<"sorted array is : "<<endl;
    for(auto i : ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}