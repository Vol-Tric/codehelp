// topological sort using DFS
#include<bits/stdc++.h>
using namespace std;

class Graph{

    public:
    // adjency list using list
    unordered_map<int , list<int>> adj_list;

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

    void topoSort(unordered_map<int , bool>&visited , stack<int>&s , int node ){
        visited[node] = true;

        for(auto neighbour : adj_list[node]){
            if(!visited[neighbour]){
                topoSort(visited, s, neighbour);
            }
        }
        s.push(node);
    }

    vector<int> topologicalSort(int vertex)  {
        unordered_map<int , bool>visited;
        stack<int>s;
        for(int i=0 ; i<vertex ; i++){
            if(!visited[i]){
                topoSort(visited , s , i);
            }
        }
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }

   
};

int main(){
    // number of nodes
    int vertex = 6;

    // number of edges
    int edge = 7;

    Graph g;
    g.addEdge_list(1,2,1);
    g.addEdge_list(1,3,1);
    g.addEdge_list(3,4,1);
    g.addEdge_list(2,4,1);
    g.addEdge_list(4,5,1);
    g.addEdge_list(5,6,1);
    g.addEdge_list(4,6,1);

    g.printEdge_list();

    vector<int>ans = g.topologicalSort(vertex);
    cout<<"Topological sort: "<<endl;
    for(auto i : ans){
        cout<<i<<" ";
    }
    



    return 0;
}