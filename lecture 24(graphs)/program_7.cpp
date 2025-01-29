// kahn's algorithm
// topological sort using BFS
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

    

    // vector<int> topologicalSort(int vertex){
    //     // indegree of every node
    //     unordered_map<int , int>inDegree;
    //     for(auto i : adj_list){
    //         for(auto j : i.second){
    //             inDegree[j]++;
    //         }   
    //     }

    //     // queue
    //     queue<int>q;
    //     for(int i=0 ; i<vertex ; i++){
    //         if(inDegree[i] == 0){
    //             q.push(i);
    //         }
    //     }

    //     // do bfs
    //     vector<int>ans;

    //     while(!q.empty()){
    //         int frontNode = q.front();
    //         q.pop();

    //         // store ans
    //         ans.push_back(frontNode);

    //         // check neighbour
    //         for(auto neighbour : adj_list[frontNode]){
    //             inDegree[neighbour]-- ;
    //             if(inDegree[neighbour] == 0){
    //                 q.push(neighbour);
    //             }
    //         }
    //     }
    //     return ans;
    // }


    vector<int>topologicalSort(int vertex){
        map<int , int>inDegree;

        for(auto i : adj_list){
            for(auto j : i.second){
                inDegree[j]++;
            }
        }

        queue<int>q;
        vector<int>ans;

        for(int i=1 ; i<=vertex ; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);

            for(auto neigh : adj_list[front]){
                inDegree[neigh]--;
                if(inDegree[neigh] == 0){
                    q.push(neigh);
                }
            }
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