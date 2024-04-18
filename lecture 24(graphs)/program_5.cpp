// cycle detection in directed graph using DFS
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

    bool isCyclicDirected(unordered_map<int , list<int>> adj_list , unordered_map<bool , int>&visited , unordered_map<bool , int>&dfsVisited, int node){
        visited[node] = true;
        dfsVisited[node] = true;

        for(auto neighbour : adj_list[node]){
            if(!visited[neighbour]){
                bool ans = isCyclicDirected(adj_list , visited , dfsVisited , neighbour);
                if(ans){
                    return true;
                }
            }
            else if(dfsVisited[neighbour]){
                return true;
            }
        }
        dfsVisited[node] = false;
        return false;
    }
    bool cycleDetection(int vertex){
        unordered_map<bool , int>visited;
        unordered_map<bool , int>dfsVisited;

        for(int i=1 ; i<=vertex ; i++){
            if(!visited[i]){
                bool ans = isCyclicDirected(adj_list , visited , dfsVisited , i);
                if(ans){
                    return true;
                }
            }
        }
        return false;
    }

   
};

int main(){
    // number of nodes
    int vertex = 8;

    // number of edges
    int edge = 9;

    Graph g;
    g.addEdge_list(1,2,1);
    g.addEdge_list(2,3,1);
    g.addEdge_list(3,7,1);
    g.addEdge_list(3,8,1);
    g.addEdge_list(8,7,1);
    g.addEdge_list(2,4,1);
    g.addEdge_list(4,5,1);
    g.addEdge_list(5,6,1);
    g.addEdge_list(6,4,1);

    g.printEdge_list();

    bool ans = g.cycleDetection(vertex);
    cout<<endl;
    (ans) ? cout<<"cycle present " : cout<<"cycle not present ";
    



    return 0;
}