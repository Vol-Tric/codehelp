// hand of straight
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0){
            return false;
        }
        map<int , int>mp;
        for(auto i : hand){
            mp[i]++;
        }

        while(mp.size()){
            int p = mp.begin()->first;
            for(int i = 0 ; i < groupSize ; i++){
                if(mp[p+i] > 0){
                    mp[p+i]--;
                    if(mp[p+i] == 0){
                        mp.erase(p+i);
                    }
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }

    
};

int main(){
    vector<int>hand = {1,2,3,6,2,3,4,7,8};
    int groupSize = 3;

    Solution obj;
    bool ans = obj.isNStraightHand(hand , groupSize);

    if(ans){
        cout<<"True"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
}