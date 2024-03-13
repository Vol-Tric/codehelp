// phone directory
#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
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
            root->children[index] = child;
        }

        // recursive call
        insertUtil(child , word.substr(1));
    }

    

    public:
    Trie(){
        root = new TrieNode('/0');
    }

    void insertWord(string word){
        insertUtil(root , word);
    }

    void printSuggestion(TrieNode* curr , vector<string> &temp , string prefix){
        if(curr->isTerminal){
            temp.push_back(prefix);
            
        }

        for(char ch = 'a'; ch <= 'z' ; ch++){
            TrieNode* next = curr->children[ch-'a'];

            if(next != NULL){
                prefix.push_back(ch);
                printSuggestion(next , temp , prefix);
                prefix.pop_back();
            }

        }
    }

    vector<vector<string>> getSuggestion(string str){
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for(int i=0 ; i<str.length() ; i++){
            char lastCh = str[i];
            prefix.push_back(lastCh);

            // check for lastCh
            TrieNode* curr = prev->children[lastCh - 'a'];

            // if not found
            if(curr == NULL){
                break;
            }

            // if found
            vector<string>temp;
            printSuggestion(curr , temp , prefix);

            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }

    
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //creation of trie
    Trie* t = new Trie();

    // insert all contact into trie
    for(auto i:contactList){
        t->insertWord(i);
    }

    // return ans
    return t->getSuggestion(queryStr);
}