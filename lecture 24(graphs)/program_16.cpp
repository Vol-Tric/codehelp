// Kasaraju's algorithm
// to find strongly connected component in a directed graph

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

    void topoSort(vector<bool>&visited , stack<int>&s , int node ){
        visited[node] = true;

        for(auto neighbour : adj_list[node]){
            if(!visited[neighbour]){
                topoSort(visited, s, neighbour);
            }
        }
        s.push(node);
    }

    void dfs(map<int , list<int>>&transpose , vector<bool>&visited , int node){
        visited[node] = true;

        for(auto neighbour : transpose[node]){
            if(!visited[neighbour]){
                dfs(transpose, visited, neighbour);
            }
        }
    }

    int kajaraju(int vertex){
        stack<int>stk;
        vector<bool>visited(vertex , false);

        // step 1 , topological sort
        for(int i=0;i<vertex;i++){
            if(!visited[i]){
                topoSort(visited , stk , i);
            }
        }

        // step 2 , transpose the graph
        map<int , list<int>>transpose;
        for(int i=0;i<vertex;i++){
            visited[i] = false;

            for(auto nbr : adj_list[i]){
                transpose[nbr].push_back(i);
            }
        }

        int count = 0;

        // step 3 , dfs on updated graph
        while(!stk.empty()){
            int top = stk.top();
            stk.pop();

            if(!visited[top]){
                count++;
                dfs(transpose , visited , top);
            }
        }
        return count;
    }

   
};

int main(){
    // number of nodes
    int vertex = 5;

    // number of edges
    int edge = 5;

    Graph g;
    g.addEdge_list(1,0,1);
    g.addEdge_list(0,2,1);
    g.addEdge_list(2,1,1);
    g.addEdge_list(2,3,1);
    g.addEdge_list(3,4,1);
    

    g.printEdge_list();

    int ans = g.kajaraju(vertex);
    cout<<"nubmer of SCC are "<<ans<<endl;
    
    return 0;
}