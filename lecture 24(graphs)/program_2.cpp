// BFS traversal of graph
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

    void bfs(unordered_map<int , list<int>> adj_list , unordered_map<int , bool>&visited , vector<int>&ans , int node){
        queue<int>q;

        q.push(node);
        visited[node] = 1;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);
            for(auto i:adj_list[frontNode]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }

    }

    vector<int>BFSTraversal(int vertex){
        vector<int>ans;
        unordered_map<int , bool>visited;
        

        // traverse all nodes
        for(int i=1;i<vertex;i++){
            if(!visited[i]){
                bfs(adj_list , visited , ans , i);
            }    
        }
        return ans;
    }
    

   
};

int main(){
    // number of nodes
    int m = 5;

    // number of edges
    int n = 6;

    Graph g;
    g.addEdge_list(1,2,0);
    g.addEdge_list(2,3,0);
    g.addEdge_list(3,4,0);
    g.addEdge_list(4,5,0);
    g.addEdge_list(5,1,0);
    g.addEdge_list(2,4,0);

    g.printEdge_list();
    cout<<endl;  
    vector<int>ans = g.BFSTraversal(m);
    cout<<"BFS Traversal"<<endl;
    for(auto i : ans){
        cout<<i<<" ";
    }
    
    


    return 0;
}