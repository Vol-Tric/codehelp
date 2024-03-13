// merge k sorted LL
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

class Solution {
public:
    Node* mergeKLists(vector<Node*>& lists) {
        priority_queue<Node* , vector<Node*> , compare> minheap;

        int k = lists.size();
        if(k == 0){
            return NULL;
        }

        // step 1, enter 1st element
        for(int i=0;i<k;i++){
            if(lists[i] != NULL){
                minheap.push(lists[i]);
            }
        }

        Node* head = NULL;
        Node* tail = NULL;

        // step 2
        while(minheap.size() > 0){
            Node* top = minheap.top();
            minheap.pop();

            if(head == NULL){
                head = top;
                tail = top;
                if(tail->next != NULL){
                    minheap.push(tail->next);
                }
            }
            else{
                tail->next = top;
                tail = top;
                if(tail->next != NULL){
                    minheap.push(tail->next);
                }
            }
        }
        
        return head;
    }
};