// articulation point
// tarjan's algorithm

#include<bits/stdc++.h>
using namespace std;

class Graph{
    // undirected , unweighted graph
    map<int , list<int>>adj;
    public:

    void createEdge(int u , int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void printEdge(){
        for(auto i : adj){
            cout<<i.first<<" -> ";
            for(auto j : i.second){
                cout<<j<<" , ";
            }
            cout<<endl;
        }
    }

    void dfs(vector<int>&disc , vector<int>&low , vector<int>&parent , vector<bool>&visited , vector<int>&ans , int &timer , int node){
        visited[node] = true;
        disc[node] = low[node] = timer++;

        // used later for the source node
        int child = 0;

        for(auto neighbour : adj[node]){
            if(neighbour == parent[node]){
                continue;
            }

            else if(!visited[neighbour]){
                child++;
                parent[neighbour] = node;

                dfs(disc , low , parent , visited , ans , timer , neighbour);

                low[node] = min(low[node] , low[neighbour]);

                if(low[neighbour] >= disc[node] && parent[node] != -1){
                    // it is an articulation point
                    ans.push_back(node);
                }

            }

            else{
                // back edge
                low[node] = min(low[node] , disc[neighbour]);
            }
        }

        // for the source node
        if(child > 1 && parent[node] == -1){
            ans.push_back(node);
        }

    }

    vector<int> articulationPoint(int vertex){
        vector<int>disc(vertex , -1);
        vector<int>low(vertex , -1);
        vector<int>parent(vertex , -1);
        vector<bool>visited(vertex , false);
        int timer = 0;

        vector<int>ans;

        for(int i=0 ; i<vertex ; i++){
            if(!visited[i]){
                dfs(disc , low , parent , visited , ans , timer , i);
            }
        }

        return ans;
    }
};

int main(){
    int vertex = 5;
    int edge = 5;

    Graph g;

    g.createEdge(0,1);
    g.createEdge(0,4);
    g.createEdge(0,3);
    g.createEdge(1,2);
    g.createEdge(3,4);

    

    g.printEdge();

    cout<<endl;

    vector<int>ans = g.articulationPoint(vertex);
    cout<<"articulation points"<<endl;
    for(auto i : ans){
        cout<<"node "<<i<<" is an articulation point"<<endl;
    }

    return 0;
}