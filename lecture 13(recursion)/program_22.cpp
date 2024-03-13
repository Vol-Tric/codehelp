// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
// string mapping[10]={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]


#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    void solve(string digits, string output, int index, vector<string>& ans,string mapping[]){
        // base case
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }
        // finding the number(-'0' is done to convert to ASCII), digits[index] return character but we want integer
        int number=digits[index]-'0';
        string value=mapping[number];

        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            solve(digits,output,index+1,ans,mapping);
            // pop is done for backtracking
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        string output;
        int index=0;
        string mapping[10]={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,output,index,ans,mapping);
        return  ans;

        
    }
};

int main(){
    Solution sol1;
    string nums="23";
    vector<string> ans;
    ans=sol1.letterCombinations(nums);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;

}