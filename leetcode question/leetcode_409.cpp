// longest palindrome
#include<bits/stdc++.h>
using namespace std;

class Solution {   
public:
    int longestPalindrome(string s) {
        map<char , int>mp;
        for(auto i : s){
            mp[i]++;   
        }

        for (auto i : mp){
            cout<<i.first<<"  "<<i.second<<endl; 
        }
        int counter = 0;
        bool flag = false;
        for(auto i : mp){
            if(i.second%2 == 0){
                counter += i.second;
                
            }
            else if(i.second%2 != 0){
                counter += (i.second-1);
                flag = true;
                // if(i.second > oddValue){
                //     counter -= oddValue;
                //     counter += 1;
                //     oddValue = i.second;
                // }
                // if((i.second - 1) > 0 && i.second%2 == 0){
                //     counter += (i.second-1);
                // }

                
            }
        }
        return (flag) ? counter + 1 : counter;
    }

};

int main(){
    string s = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";

    // string s = "abccccdd";
    // ans should be 983
    Solution obj;
    int ans = obj.longestPalindrome(s);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}