// bellman ford algorithm
// to find shortest path
#include<bits/stdc++.h>
using namespace std;

class Graph{
    map<int , list<pair<int , int>>> adj_list;
    public:

    void addEdge(int u , int v , int weight ){
        adj_list[u].push_back(make_pair(v , weight));
        adj_list[v].push_back(make_pair(u , weight));
    }

    void printEdge(){
        for(auto i: adj_list){
            cout<<i.first<<"  ->";
            for(auto j : i.second){
                cout<<"[vertex: "<<j.first<<", weight: "<<j.second<<"]";
            }
            cout<<endl;
        }
    }

    
    vector<int> bellmanFord(int vertex, int source) {
        vector<int> dist(vertex, INT_MAX); // Initialize distances with infinity
        dist[source] = 0; // Distance to source vertex is 0

        // Relax all edges |V| - 1 times
        for (int i = 0; i < vertex - 1; i++) {
            for (auto& node : adj_list) {
                int u = node.first; // source vertex
                for (auto& edge : node.second) {
                    int v = edge.first; // destination vertex
                    int weight = edge.second; // weight of the edge
                    // Relaxation step
                    if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                    }
                }
            }
        }

        // Check for negative weight cycles
        for (auto& node : adj_list) {
            int u = node.first;
            for (auto& edge : node.second) {
                int v = edge.first;
                int weight = edge.second;
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    // Negative weight cycle found
                    // This indicates that there's no shortest path
                    // as the graph contains a negative weight cycle
                    cout << "Negative weight cycle found!" << endl;
                    return {}; // Return an empty vector
                }
            }
        }

        return dist;
    }
};

int main(){
    int vertex = 5;
    int edge = 7;

    Graph g;

    g.addEdge(2,1,3);
    g.addEdge(1,4,1);
    g.addEdge(2,0,1);
    g.addEdge(1,0,7);
    g.addEdge(1,3,5);
    g.addEdge(4,3,7);
    g.addEdge(0,3,2);
    
    g.printEdge();
    cout<<endl;

    int source = 0;
    int dest = 4;
    vector<int>ans = g.bellmanFord(vertex , source);
    cout<<"destination array in respect of source "<<source<<" is "<<endl;
    for(auto i : ans){
        cout<<i<<" ";
    }
    cout<<endl<<"the cost of travelling from source "<<source<<" to destination "<<dest<<" is: "<<ans[dest]<<endl;
    



    return 0;
}
