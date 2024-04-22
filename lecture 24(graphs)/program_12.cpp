// prim's algorithm
// to find minimum cost spanning tree
#include<bits/stdc++.h>
using namespace std;

class Graph{
    map<int , list<pair<int , int>>>adj_list;

    public:
    void createEdge(int u , int v , int weight){
        adj_list[u].push_back(make_pair(v , weight));
        adj_list[v].push_back(make_pair(u , weight));
    }

    void printEdge(){
        for(auto i : adj_list){
            cout<<i.first<<"-> ";
            for(auto j : i.second){
                cout<<"[vertex: "<<j.first<<", weight: "<<j.second<<"]";
            }
            cout<<endl;
        }
    }

    void printEdge_2(map<int , list<pair<int , int>>>adj){
        for(auto i : adj){
            cout<<i.first<<"-> ";
            for(auto j : i.second){
                cout<<"[vertex: "<<j.first<<", weight: "<<j.second<<"]";
            }
            cout<<endl;
        }
    }
    
    // key using array , TC = O(V*V);
    map<int , list<pair<int , int>>> prims(int vertex){

        vector<int>parent(vertex , -1);
        vector<bool>mst(vertex , false);
        vector<int>key(vertex , INT_MAX);

        // key of source = 0
        key[0] = 0;
        

        for(int i = 0 ; i<vertex ; i++){
            int u;
            int mini = INT_MAX;

            // to find minimum of key array
            for(int v = 0 ; v<vertex ; v++){
                if(mst[v] == false && key[v] < mini){
                    u = v;
                    mini = key[v];
                }
            }

            // mst of minimum  = true
            mst[u] = true;

            // neighbour of minimum node
            for(auto neighbour : adj_list[u]){
                int node = neighbour.first;
                int weight = neighbour.second;

                if(mst[node] == false && key[node] > weight){
                    key[node] = weight;
                    parent[node] = u;
                }
            }
        }

        // prepare an answer graph
        map<int , list<pair<int , int>>> ans;

        for(int i = 1 ; i<vertex ; i++){
            ans[i].push_back(make_pair(parent[i] , key[i]));
        }
        
        return ans;
    }

    

    int minimumCost(map<int , list<pair<int , int>>> prims){
        int cost = 0;
        for(auto i : prims){
            for(auto j : i.second){
                cost += j.second;
            }
        }
        return cost;
    }


};

int main(){
    int vertex = 5;
    int edge = 6;

    Graph g; 

    g.createEdge(0,1,2);
    g.createEdge(0,3,6);
    g.createEdge(1,3,8);
    g.createEdge(1,4,5);
    g.createEdge(1,2,3);
    g.createEdge(4,2,7);

    
    g.printEdge();

    cout<<endl<<endl;
    map<int , list<pair<int , int>>> ans = g.prims(vertex);
    g.printEdge_2(ans);
    int cost = g.minimumCost(ans);
    cout<<endl<<"minimum cost: "<<cost<<endl;

    return 0;
}