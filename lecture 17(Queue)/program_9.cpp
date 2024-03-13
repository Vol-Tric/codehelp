// First non-repeating character in a stream
// Input: A = "aabc"
// Output: "a#bb"
// Explanation: For every ith character we will
// consider the string from index 0 till index i first non
// repeating character is as follow-
// "a" - first non-repeating character is 'a'
// "aa" - no non-repeating character so '#'
// "aab" - first non-repeating character is 'b'
// "aabc" - there are two non repeating characters 'b' and 'c', 
// first non-repeating character is 'b' because 'b' comes before
// 'c' in the stream.

#include<bits/stdc++.h>
using namespace std;
class Solution {
	public:
    string FirstNonRepeating(string A){
        unordered_map<char,int>count;
        queue<char> q;
        string ans="";
        
        for(int i=0;i<A.length();i++){
            char ch=A[i];
            
            //  count++
            count[ch]++;
            
            //push in queue
            q.push(ch);
            
            while(!q.empty()){
                if(count[q.front()]>1){
                    //repeating character
                    q.pop();
                }
                else {
                    ans.push_back(q.front());
                    break;
                }
            }
            if(q.empty()){
                ans.push_back('#');
            }
        }
        return ans;
        
    }

};

int main(){
    string A="aabc";
    Solution s1;
    string ans=s1.FirstNonRepeating(A);
    cout<<ans<<endl;
    return 0;
}