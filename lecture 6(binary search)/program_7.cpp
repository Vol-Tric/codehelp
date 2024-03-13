// aggressive cows
// You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.
// You are also given an integer 'k'which denotes the number of aggressive cows.
// You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.
// Example:
// For 'n' = 3, 'k' = 2 and 'arr' = {1, 2, 3}
// Answer is 2.
// Explanation: The maximum possible minimum
// distance will be 2 when 2 COWS are placed
// at positions {1, 3}. Here distance between
// COWS is 2.
# include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool ispossible(vector<int> &stalls, int k,int mid){
    int cowCount=1;
    int lastPosition=stalls[0];
    for(int i=0;i<stalls.size();i++){
        if(stalls[i]-lastPosition>=mid){
            cowCount++;
            if(cowCount==k){
                return true;
            }
            lastPosition=stalls[i];
        }
    }
    return false;

}

int aggressiveCows(vector<int> &stalls, int k)
{
    
    sort(stalls.begin(),stalls.end());
    int start=0;
    int maxi=-1;
    for(int i=0;i<stalls.size();i++){
        maxi=max(maxi,stalls[i]);
    }
    int end=maxi;
    int mid=start+(end-start)/2;
    int ans=-1;
    while(start<=end){
        if(ispossible(stalls,k,mid)){
            ans=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return ans;
}

int main(){
    vector<int>v;
    v.push_back(0);
    v.push_back(3);
    v.push_back(4);
    v.push_back(7);
    v.push_back(10);
    v.push_back(9);

    // k=number of cows
    int k=2;

    int ans=aggressiveCows(v,k);
    cout<<ans<<endl;
    return 0;
}