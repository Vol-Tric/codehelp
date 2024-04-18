// cycle detection in undirected graph
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

    bool isCyclicBFS(unordered_map<int , list<int>> adj_list , unordered_map<int , bool>&visited , int node){
        queue<int>q;
        unordered_map<int , int>parent;

        // for source node
        parent[node] = -1;
        visited[node] = true;

        q.push(node);

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            for(auto neighbour : adj_list[frontNode]){
                if(visited[neighbour] == true && neighbour != parent[frontNode]){
                    // cycle exists
                    return true;
                }

                else if(!visited[neighbour]){
                    visited[neighbour] = true;
                    q.push(neighbour);
                    parent[neighbour] = frontNode;
                }
            }
        }
        return false;
    }

    bool isCyclicDFS(unordered_map<int , list<int>>adj , unordered_map<int , bool>&visited , int node , int parent){
        visited[node] = true;

        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
                bool cycleDetected = isCyclicDFS(adj, visited, neighbour, node);
                if(cycleDetected){
                    return true;
                }
            }
            else if(neighbour != parent){
                return true;
            }
        }
        return false;
    }

    void cycleDetection(int vertex){
        unordered_map<int , bool>visited;
        for(int i=1 ; i<=vertex ; i++){
            if(!visited[i]){
                // bool ans = isCyclicBFS(adj_list , visited , i);
                bool ans = isCyclicDFS(adj_list , visited , i , -1);
                if(ans == true){
                    cout<<"cycle exists";
                    return ;
                }
            }
        }
        cout<<"cycle doesn't exists";
    }
    

   
};


int main(){
    int vertex = 5;

    // number of edges
    int edges = 6;

    Graph g;
    g.addEdge_list(1,2,0);
    g.addEdge_list(2,3,0);
    g.addEdge_list(3,4,0);
    g.addEdge_list(4,5,0);
    g.addEdge_list(5,1,0);
    g.addEdge_list(2,4,0);

    g.printEdge_list();
    g.cycleDetection(vertex);

    return 0;
}