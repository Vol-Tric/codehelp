// find common character
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// T.C = O(26*N*N) 
    // vector<string> commonChars(vector<string>& words) {
    //     vector<string>ans;

    //     for(char ch = 'a' ; ch <= 'z' ; ch++){
    //         int mini = INT_MAX;

    //         for(auto word : words){
    //             int count = 0;
    //             for(auto c : word){
    //                 if(c == ch){
    //                     count++;
    //                 }
    //             }
    //             mini = min(mini , count);
    //         }

    //         for(int i=0 ; i<mini ; i++){
    //             ans.push_back(string(1 , ch));
    //         }
    //     }
    //     return ans;
    // }


    // T.C = O(N*N) , S.C = O(26*2) = O(1) constant
    vector<string> commonChars(vector<string>& words){
        vector<string>ans;
        vector<int>count(26 , INT_MAX);

        for(auto w : words){
            vector<int>counts(26 , 0);
            for(auto c : w){
                counts[c - 'a']++;
            }

            for(int i = 0 ; i<26 ; i++){
                count[i] = min(count[i] , counts[i]);
            }
        }

        for(int i = 0 ; i<26 ; i++){
            for(int j = 0 ; j<count[i] ; j++){
                ans.push_back(string(1 , i + 'a'));
            }
        }
        return ans;
    }
};

int main(){
    vector<string>words = {"bella","label","roller"};
    // ans should be "e,l,l"

    Solution obj;
    vector<string>ans = obj.commonChars(words);
    cout<<endl<<"answer is : "<<endl;
    for(auto i : ans){
        cout<<i<<"  ";
    }
    return 0;
}