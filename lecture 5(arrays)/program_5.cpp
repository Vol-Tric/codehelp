// check if array is sorted or rotated
#include<iostream>
#include<vector>
using namespace std;
bool check(vector<int>& nums) {
    int count=0;
    int n=nums.size();
    for(int i=1;i<=n;i++){
        if(nums[i-1]>nums[i]){
            count++;
        }
        
    }
    if(nums[n-1]>nums[0]){
        count++;
    }
    return count<=1;
}

int main(){
    vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(1);
    v.push_back(2);
    bool ans=check(v);
    cout<<ans<<endl;
    return 0;
}