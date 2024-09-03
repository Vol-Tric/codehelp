// sum of digits of string after convert
#include<bits/stdc++.h>
using namespace std;
class Solution {

public:
    int getLucky(string s, int k) {
        string number = "";

        for(char ch : s){
            number += to_string(ch - 'a' + 1);
        }

        while(k > 0){
            int temp = 0;
            for(char x : number){
                temp += x - '0';
            }
            number = to_string(temp);
            k--;
        }

        return stoi(number);
    }

    // int getLucky(string s, int k) {
    //     map<char , int>charMap;
    //     for(char ch = 'a'; ch <= 'z'; ++ch) {
    //         charMap[ch] = ch - 'a' + 1;
    //     }

    //     string number = "";

    //     for(char ch : s){
    //         number += to_string(charMap[ch]);
    //     }

    //     while(k > 0){
    //         int temp = 0;
    //         for(char x : number){
    //             temp += x - '0';
    //         }
    //         number = to_string(temp);
    //         k--;
    //     }

    //     return stoi(number);
    // }
};

int main(){
    string s = "leetcode";
    int k = 2;
    Solution obj;
    int ans = obj.getLucky(s , k);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}