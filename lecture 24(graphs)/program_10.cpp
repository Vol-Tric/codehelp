// shortest path in a DAG

#include<bits/stdc++.h>
using namespace std;

class Graph{
    // to make weighted graph
    map<int ,list< pair<int , int >>> adj_list;
    public:

    void addEdge(int u , int v , int weight ){
        pair<int , int> p = make_pair(v , weight);
        
        adj_list[u].push_back(p);
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

    // void topoSort(unordered_map<int , bool>&visited , stack<int>&s , int node){
    //     visited[node] = true;
        
    //     for(auto neighbour : adj_list[node]){
    //         if(!visited[neighbour.first]){
    //             topoSort(visited , s , neighbour.first);
    //         }
    //     }
    //     s.push(node);
    // }

    // stack<int> topologicalSort(int vertex){
    //     unordered_map<int , bool>visited;
    //     stack<int>s;

    //     for(int i=0;i<vertex;i++){
    //         if(!visited[i]){
    //             topoSort(visited , s , i);
    //         }
    //     }
    //     return s;
    // }

    // int shortestPath(int vertex , int src , int goal){
    //     stack<int> stk = topologicalSort(vertex);

    //     vector<int> dist(vertex);
    //     for(int i=0 ; i<vertex ; i++){
    //         // 100 is max value here acting as INT_MAX
    //         dist[i] = 100;
    //     }
        
    //     // dist[src] = 0;
    //     dist[src] = 0;

    //     while(!stk.empty()){
    //         int topNode = stk.top();
    //         stk.pop();

    //         for(auto temp : adj_list[topNode]){
    //             if((dist[topNode] + temp.second) < dist[temp.first]){
    //                 dist[temp.first] = dist[topNode] + temp.second;
    //             }
    //         }
    //     }

    //     for(auto i : dist){
    //         cout<<i<<" ";
    //     }
    //     cout<<endl;

    //     return dist[goal];
    // }

    void topo(int node , map<int , bool>&visited , vector<int>&ans){
        visited[node] = true;
        ans.push_back(node);

        for(auto neigh : adj_list[node]){
            if(!visited[neigh.first]){
                topo(neigh.first , visited , ans);
            }
        }
    }

    vector<int>topoLogicalSort(int vertex){
        map<int , bool>visited;
        vector<int>ans;
        for(int i=0 ; i<vertex ; i++){
            if(!visited[i]){
                topo(i , visited , ans);
            }
        }
        return ans;
    }

    int shortestPath(int vertex , int start , int goal){
        vector<int>topo = topoLogicalSort(vertex);

        vector<int>dist(vertex + 1, 100); // INT_MAX will not work as nothing can be added to INT_MAX

        dist[start] = 0;
        for(auto i : topo){
            for(auto neigh : adj_list[i]){
                if((dist[i] + neigh.second) < dist[neigh.first]){
                    dist[neigh.first] = dist[i] + neigh.second;
                }
            }
        }

        return dist[goal];
    }
};

int main(){
    int vertex = 6;
    int edges = 9;

    Graph g;

    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    g.printEdge();

    int src = 1;
    int goal = 4;
    int ans = g.shortestPath(vertex , src , goal);
    cout<<"shortest path from "<<src<<" to "<<goal<<" is: "<<ans<<endl;



    return 0;
}