// bridge in a graph
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

    void dfs(vector<vector<int>>&ans , vector<int>&disc , vector<int>&low , vector<bool>&visited , int &timer , vector<int>&parent , int node){

        visited[node] = true;
        disc[node] = low[node] = timer++;

        for(auto neighbour : adj[node]){
            if(neighbour == parent[node]){
                continue;
            }

            else if(!visited[neighbour]){
                parent[neighbour] = node;

                dfs(ans , disc , low , visited , timer , parent , neighbour);

                low[node] = min(low[node] , low[neighbour]);

                if(low[neighbour] > disc[node]){
                    // vector<int>temp;
                    // temp.push_back(node);
                    // temp.push_back(neighbour);
                    // ans.push_back(temp);

                    ans.push_back({node , neighbour});
                }
            }

            else{
                // back edge
                low[node] = min(low[node] , disc[neighbour]);
            }
        }
    }

    vector<vector<int>> bridgeInGraph(int vertex){
        vector<vector<int>>ans;
        
        vector<int>disc(vertex , -1);
        vector<int>low(vertex , -1);
        vector<int>parent(vertex , -1);
        vector<bool>visited(vertex , false);
        int timer = 0;

        for(int i = 0; i<vertex ; i++){
            if(!visited[i]){
                dfs(ans , disc , low , visited , timer , parent , i);
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
    g.createEdge(0,2);
    g.createEdge(0,3);
    g.createEdge(1,2);
    g.createEdge(3,4);

    g.printEdge();

    cout<<endl;

    vector<vector<int>>ans = g.bridgeInGraph(vertex);
    cout<<"brigde edges"<<endl;
    for(auto i : ans){
        cout<<"edge : "<<i[0]<<" -> "<<i[1]<<endl;

    }

    return 0;
}