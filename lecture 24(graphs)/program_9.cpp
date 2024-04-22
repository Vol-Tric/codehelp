// shortest path in undirected graph using BFS
#include<bits/stdc++.h>
using namespace std;

class Graph{

    public:
    // adjency list using list
    map<int , list<int>> adj_list;

    void addEdge_list(int u , int v , bool direction){
        // direction is to check for directed or undierected graph

        // create an adge
        adj_list[u].push_back(v);

        // check direction
        if(direction == 0){
            // if undirected , create an edge from both the sides
            adj_list[v].push_back(u);
        }
    }

    void printEdge_list(){
        for(auto i: adj_list){
            cout<<i.first<<"  ->";
            for(auto j : i.second){
                cout<<j<<"->";
            }
            cout<<endl;
        }
    }

    

    void path(unordered_map<int , bool>&visited , unordered_map<int , int>&parent , int node){

        visited[node] = true;
        parent[node] = -1;

        queue<int>q;
        q.push(node);

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            for(auto neighbour : adj_list[frontNode]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = frontNode;
                }
            }
        }
    }

    vector<int> shortestPath(int n , int m, int s , int t){
 
        vector<int>ans;
        unordered_map<int , bool> visited;
        unordered_map<int , int> parent;

        for(int i=1 ;i<=n ;i++){
            if(!visited[i]){
                path(visited , parent , i);
            }
        }
        
        stack<int>stk;
        stk.push(t);

        int temp = parent[t];
        while(temp != parent[s]){
            stk.push(temp);
            temp = parent[temp];
        }

        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }

        return ans;
    }
    
};

int main(){
    int vertex = 8;

    // number of edges
    int edges = 9;

    Graph g;
    g.addEdge_list(1,2,0);
    g.addEdge_list(2,5,0);
    g.addEdge_list(5,8,0);
    g.addEdge_list(1,3,0);
    g.addEdge_list(3,8,0);
    g.addEdge_list(1,4,0);
    g.addEdge_list(4,6,0);
    g.addEdge_list(6,7,0);
    g.addEdge_list(7,8,0);

    g.printEdge_list();
    vector<int>ans = g.shortestPath(edges , vertex , 1 , 8);


    // g.addEdge_list(1,2,0);
    // g.addEdge_list(1,3,0);
    // g.addEdge_list(3,2,0);
    // g.addEdge_list(4,3,0);
    // edges = 4 ; vertex = 4 ;
    // g.printEdge_list();
    // vector<int>ans = g.shortestPath(edges , vertex , 1 , 4);



    cout<<"shortest path is"<<endl;
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}