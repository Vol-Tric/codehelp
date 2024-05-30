// number of steps to reduce a number in binary representation to one
#include<bits/stdc++.h>
using namespace std;

class Solution {
    // long long int toDecimal(string s){
    //     int n = s.length();
    //     long long int ans = 0;
    //     for(int i=0 ; i<n ; i++){
    //         if(s[i] == '0'){
    //             ans += 0;
    //         }
    //         else if(s[i] == '1'){
    //             ans += pow(2 , n-i-1);
    //         }
    //     }
    //     cout<<"decimal number is : "<<ans<<endl;
    //     return ans;
    // }
public:
    // int numSteps(string s) {
    //     long long int num = toDecimal(s);
    //     int count = 0;
    //     while(num > 1){
    //         if(num%2 == 0){
    //             num = num/2;
    //         }
    //         else if(num%2 != 0){
    //             num = num+1;
    //         }
    //         count++;
    //         cout<<num<<endl;
    //     }
    //     return count;
    // }

    // int numSteps(string s) {
    //     int ans=0;
    //     reverse(s.begin(),s.end());
    //     while(s.size()!=1){
    //         ans++;
    //         int i=0;
    //         if(s[i]=='1'){
    //             while(s[i]!='0' && i<s.size()){
    //                 s[i]='0';
    //                 i++;
    //             }
    //             if(i==s.size()){
    //                 s+='1';
    //             }
    //             else{
    //                 s[i]='1';
    //             }
    //         }
    //         else{
    //             string temp=s.substr(1,s.length()-1);
    //             s=temp;
    //         }

    //     }
      
    //     return ans;
    // }

    int numSteps(string s){
        int ans = 0;
        while(s != "1"){
            
            if(s.back() == '0'){
                s.pop_back();
            }
            else{
                int i = s.length() - 1;
                while(i >= 0 && s[i] == '1'){
                    s[i] = '0';
                    i--;
                }
                if(i < 0){
                    s = '1' + s;
                }
                else{
                    s[i] = '1';
                }
            }
            ans++;
        }
        return ans;
    }
    
};

int main(){
    string s = "1111011110000011100000110001011011110010111001010111110001";
    // ans should be 6
    Solution obj;
    int ans = obj.numSteps(s);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}