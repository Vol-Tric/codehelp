#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool palindrome(int num){
        int temp = num;
        int ans = 0;
        while(temp > 0){
            ans *= 10;
            ans += temp%10;
            temp = temp/10;
        }
        return ans == num;
    }
public:
    string nearestPalindromic(string n) {
        int num = stoi(n);
        int smallerPalindrome = 0;
        int distSmaller = 0;
        int largerPalindrome = 0;
        int distLarger = 0;
        // for smaller palindrome
        for(int i = num - 1 ; i >= 0 ; i--){
            if(palindrome(i)){
                smallerPalindrome = i;
                // cout<<"smallerPalindrome = "<<i<<endl;
                break;
            }
        }
        distSmaller = num - smallerPalindrome;
        // cout<<"smaller Dist = "<<distSmaller<<endl;

        // for larger dist
        for(int i = num + 1 ; i <= num + distSmaller ; i++){
            if(palindrome(i)){
                largerPalindrome = i;
                // cout<<"largerPalindrome = "<<largerPalindrome<<endl;
                break;
            }
        }
        if(largerPalindrome == 0){
            distLarger = distSmaller + 1; //as no palindrome above num in the range so to make the answer smaller dist
        }
        else{distLarger = largerPalindrome - num;}
        // cout<<"distLarger = "<<distLarger<<endl;

        if(distSmaller <= distLarger){
            return to_string(smallerPalindrome);
        }
        else{
            return to_string(largerPalindrome);
        }
    }
};


int main(){
    string n = "123";
    Solution obj;
    string ans = obj.nearestPalindromic(n);
    cout<<"answer is : "<<ans<<endl;
    return 0;
}