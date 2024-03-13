// smallest range in k sorted list
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    int row;
    int col;

    Node (int data, int row, int col){
        this->data=data;
        this->row=row;
        this->col=col;
    }       
};

class compare{
    public:
    bool operator()(Node* a , Node* b){
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    int maxi = INT_MIN;
    int mini = INT_MAX;

    priority_queue<Node* , vector<Node*> , compare> minheap;

    for(int i=0 ; i<k ;i++){
        int element = a[i][0];
        mini = min(mini,element);
        maxi = max(maxi,element);
        minheap.push(new Node(element, i, 0));
    }

    int start = mini;
    int end = maxi;
    
    while(!minheap.empty()){
        Node* temp = minheap.top();
        minheap.pop();

        mini = temp->data;

        if(maxi - mini < end - start){
            start = mini;
            end = maxi;
        }

        if(temp->col + 1 < n){
            maxi = max(maxi , a[temp->row][temp->col + 1]);
            minheap.push(new Node(a[temp->row][temp->col + 1] , temp->row , temp->col));
        }
        else{
            break;
        }


    }

    return (end - start + 1);

}