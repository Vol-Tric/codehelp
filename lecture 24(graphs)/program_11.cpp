// dijkstra's algorithm
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

    
    // vector<int> dijkstra(int vertex , int source ){
    //     vector<int>dist(vertex);
    //     set<pair<int , int>>st;

    //     // setting dist to 10000 , here 10000 act as INT_MAX
    //     for(int i=0 ; i< vertex ; i++){
    //         dist[i] = INT_MAX;
    //     }

    //     dist[source] = 0;
    //     st.insert(make_pair(dist[source] , source));

    //     while(!st.empty()){
    //         auto top = *st.begin();
            
            

    //         int nodeDist = top.first;
    //         int node = top.second;
    //         st.erase(st.begin());

    //         for(auto neighbour : adj_list[node]){
    //             if(dist[neighbour.first] > neighbour.second + nodeDist){
                
    //                 auto record = st.find(make_pair(dist[neighbour.first] , neighbour.first));
    //                 // if record is found
    //                 if(record != st.end()){
    //                     st.erase(record);
    //                 }
    //                 // update dist
    //                 dist[neighbour.first] = neighbour.second + nodeDist;

    //                 st.insert(make_pair(dist[neighbour.first] , neighbour.first));

    //             }
    //         }
    //     }
    //     return dist;
    // }


    vector<int>dijkstra(int vertex , int source){
        vector<int>dist(vertex , 1000);
        set<pair<int , int>>st;

        dist[source] = 0;

        st.insert({dist[source] , source});

        while(!st.empty()){
            auto top = *st.begin();

            int topDist = top.first;
            int topNode = top.second;

            st.erase({topDist , topNode});

            for(auto neigh : adj_list[topNode]){
                if((topDist + neigh.second) < dist[neigh.first]){ //update
                    // check if a node already exists
                    if(st.count({dist[neigh.first] , neigh.first})){
                        st.erase({dist[neigh.first] , neigh.first});
                    }

                    dist[neigh.first] = topDist + neigh.second;

                    st.insert({dist[neigh.first] , neigh.first});
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
    vector<int>ans = g.dijkstra(vertex , source);
    cout<<"destination array in respect of source "<<source<<" is "<<endl;
    for(auto i : ans){
        cout<<i<<" ";
    }
    cout<<endl<<"the cost of travelling from source "<<source<<" to destination "<<dest<<" is: "<<ans[dest]<<endl;
    



    return 0;
}