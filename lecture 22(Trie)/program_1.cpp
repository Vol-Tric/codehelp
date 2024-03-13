// introduction to trie
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

            int index = word[0] - 'A';

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

        bool searchUtil(TrieNode* root , string word){
            // base case
            if(word.length() == 0){
                return root->isTerminal;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            if(root->children[index] != NULL){
                // present
                child = root->children[index];
            }
            else{
                // absent
                return false;
            }

            // recursive call
            return searchUtil(child , word.substr(1));
        }

        void deleteUtil(TrieNode* root , string word){
            // base case
            if(word.length() == 0){
                root->isTerminal = false;
                return ;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            if(root->children[index] != NULL){
                // present
                child = root->children[index];
            }
            else{
                return;
            }

            // recursive call
            deleteUtil(child , word.substr(1));
        }

    public:
        Trie(){
            root = new TrieNode('/0');
        }

        void insertWord(string word){
            insertUtil(root , word);
        }

        bool search(string word){
            return searchUtil(root , word);
        }

        void deleteWord(string word){
            deleteUtil(root , word);
        }
};

int main(){
    Trie* t = new Trie();

    t->insertWord("ABCD");
    t->insertWord("DO");
    t->insertWord("CAT");
    t->insertWord("TIME");
    t->insertWord("CAR");
    

    bool ans = t->search("ABCD");
    cout<<ans<<endl;

    t->deleteWord("CAT");

    bool ans1 = t->search("CAT");
    cout<<ans1<<endl;




    return 0;
}