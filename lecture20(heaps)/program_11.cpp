// smallest range in k list
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node (int data){
        this->data=data;
        this->next=NULL;
    }       
};

class compare{
    public:
    bool operator()(Node* a , Node* b){
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    
}