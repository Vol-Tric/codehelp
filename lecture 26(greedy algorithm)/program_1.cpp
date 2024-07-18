// N meetings in one room
// activity selection
// Maximum length of paired chains on leetcode (leetcode 646)

#include<bits/stdc++.h>
using namespace std;

class Solution{
    static bool cmp(pair<int , int>a , pair<int , int>b){
        return a.second < b.second ;
    }
    public:
    int maxMeetings(int start[] , int end[] , int n){
        vector<pair<int , int>>v;
        for(int i=0 ; i<n ; i++){
            v.push_back(make_pair(start[i] , end[i]));
        }

        sort(v.begin() , v.end() , cmp);

        int count = 1;
        int ansEnd = v[0].second;

        for(int i=1 ; i<n ; i++){
            if(v[i].first >= ansEnd){
                count++;
                ansEnd = v[i].second;
            }
        }
        return count;
    }

};

int main(){
    int start[6] = {1,3,0,5,8,5};
    int end[6] = {2,4,6,7,9,9};
    int n = 6;

    Solution obj;
    int ans = obj.maxMeetings(start , end , n);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}