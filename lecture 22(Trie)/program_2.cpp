// Longest Common Prefix
#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;  
    }
};

class Trie{
    private:
    
        TrieNode* root;

        void insertUtil(TrieNode* root , string word){
            // base case
            if(word.length() == 0){
                root->isTerminal = true;
                return ;
            }

            int index = word[0] - 'a';

            TrieNode* child;

            if(root->children[index] != NULL){
                // present
                child = root->children[index];
            }
            else{
                // absent
                child = new TrieNode(word[0]);
                root->childCount++;
                root->children[index] = child;
            }

            // recursive call
            insertUtil(child , word.substr(1));
        }

        

        void lcp(string str , string &ans){
            for(int i=0;i<str.length();i++){
                char ch = str[i];

                if(root->childCount == 1){
                    ans.push_back(ch);
                    // aage badho
                    int index = ch - 'a';
                    root = root->children[index];
                }
                else{
                    break;
                }
                if(root->isTerminal){
                    break;
                }
            }
        }

    public:
        Trie(){
            root = new TrieNode('/0');
        }

        void insertWord(string word){
            insertUtil(root , word);
        }

        // approach 2, using Trie
        string longestCommonPrefix_Trie(vector<string>str){
            string ans = "";
            for(auto i:str){
                lcp(i , ans);
            }
            return ans;

            
        }
};

// approach 1, brute force
string longestCommonPrefix(vector<string> &arr, int n){
   string ans = "";
    
   // for traversing all charachter of 1st string
   for(int i=0;i<arr[0].length() ; i++){
      char ch = arr[0][i];

      bool match = true;

      // for comparing character with rest of strings
      for(int j=0;j<n;j++){

         // not match
         if(arr[j].size() < i || ch != arr[j][i]){
            match = false;
            break;
         }
         
      }
      if(match == false){
         break;
      }
      else{
         ans.push_back(ch);
      }
   }
   return ans;
}

int main(){
    vector<string> str;
    str.push_back("applejuice");
    str.push_back("applepie");
    str.push_back("apple");

    int n=3;

    string ans = longestCommonPrefix(str , n);
    cout<<"ans: "<<ans<<endl;


    Trie* t = new Trie();
    string ans1 = t->longestCommonPrefix_Trie(str);
    cout<<"ans using trie: "<<ans1<<endl;




    return 0;
}