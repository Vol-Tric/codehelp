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
    



    return 0;
}