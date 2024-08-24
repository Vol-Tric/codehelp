#include<bits/stdc++.h>
using namespace std;

// class Solution {
//     static bool cmp(pair<char , int>a , pair<char , int>b){
//         return a.second < b.second;
//     }
// public:
//     int minimumPushes(string word) {
//         map<char , int>mp;
//         for(auto i : word){
//             mp[i]++;
//         }

//         vector<pair<char , int>>mp1;
//         for(auto i : mp){
//             mp1.push_back(make_pair(i.first , i.second));
//         }
//         sort(mp1.begin() , mp1.end() , cmp);

//         // for(auto i : mp1){
//         //     cout<<i.first<<"--> "<<i.second<<endl;
//         // }
//         // cout<<"size is "<<mp1.size()<<endl;


//         if(mp1.size() > 24){
//             int ans = 0;
//             int check = mp1.size() - 24;
//             for(int i=0 ; i<check ; i++){
//                 ans += 4 * mp1[i].second;
//             }
//             for(int i=check ; i<check + 8 ; i++){
//                 ans += 3 * mp1[i].second;
//             }
//             check = check + 8;
//             for(int i = check ; i < check + 8 ; i++){
//                 ans += 2 * mp1[1].second;
//             }
//             check = check + 8;
//             for(int i=check ; i<mp.size() ; i++){
//                 ans += + mp1[i].second;
//             }

//             return ans;
//         }
//         else if(mp1.size() > 16 && mp1.size() <= 24){
//             int ans = 0;
//             int check = mp1.size() - 16;
//             for(int i=0 ; i<check; i++){
//                 ans += 3 * mp1[i].second;
//             }
//             check = check;
//             for(int i = check ; i < check + 8 ; i++){
//                 ans += 2 * mp1[1].second;
//             }
//             check = check + 8;
//             for(int i=check ; i<mp.size() ; i++){
//                 ans += mp1[i].second;
//             }

//             return ans;
//         }

//         else if(mp1.size() > 8 && mp1.size() <= 16){
//             int ans = 0;
//             int check = mp1.size() - 8;
//             for(int i = 0 ; i < check ; i++){
//                 ans += 2 * mp1[1].second;
//             }
//             for(int i=check ; i<mp.size() ; i++){
//                 ans += mp1[i].second;
//             }

//             return ans;
//         }

//         else{
//             int ans = 0;
//             for(int i=0 ; i<mp1.size() ; i++){
//                 ans += mp1[i].second;
//             }
//             return ans;
//         }
//     }
// };

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cnt(26);
        for (char& c : word) {
            ++cnt[c - 'a'];
        }
        sort(cnt.rbegin(), cnt.rend());
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans += (i / 8 + 1) * cnt[i];
        }
        return ans;
    }
};

int main(){
    string word = "abzaqsqcyrbzsrvamylmyxdjl";
    Solution obj;
    int ans = obj.minimumPushes(word);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}