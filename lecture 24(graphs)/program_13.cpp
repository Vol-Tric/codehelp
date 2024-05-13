// kruskal's algoritm
// to find minimum cost spanning tree using the concept of disjoint sets
#include<bits/stdc++.h>
using namespace std;

class Graph{
    vector<vector<int>> adj;
    public:
    void createEdge(int u , int v , int weight){
        vector<int>temp;
        temp.push_back(u);
        temp.push_back(v);
        temp.push_back(weight);

        adj.push_back(temp);
    }

    void printGraph(){
        for(auto i : adj){
            cout<<i[0]<<" -> "<<i[1]<<" , weight: "<<i[2];
            cout<<endl;
        }
        
    }

    // to initialize parent and rank vectors
    void makeSet(vector<int>&parent , vector<int>&rank , int vertex){
        for(int i=0 ; i<vertex ; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }

    // to find parent of a node
    int findParent(vector<int>&parent , int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findParent(parent , parent[node]);
    }

    void unionSet(int u , int v , vector<int>&parent , vector<int>&rank){
        u = findParent(parent , u);
        v = findParent(parent , v);

        if(rank[u] < rank[v]){
            parent[u] = v;
        }

        else if(rank[u] > rank[v]){
            parent[v] = u;
        }
        else{
            // both parent have same rank
            parent[u] = v;
            rank[v]++;
        }
    }

    // to sort adj according to weights
    bool cmp(vector<int>&a , vector<int>&b){
        return (a[2] < b[2]);
    }

    // main function4
    int minimumSpanningTree(int vertex){
        // for disjoint sets
        vector<int>parent(vertex);
        vector<int>rank(vertex);
        makeSet(parent , rank , vertex);

        // to sort adj according to weights , but of no use for my setup
        // sort(adj.begin() , adj.end() , cmp);

        int minWeight = 0;

        for(int i=0 ; i<adj.size() ; i++){
            int u = findParent(parent , adj[i][0]);
            int v = findParent(parent , adj[i][1]);
            int wt = adj[i][2];

            if(u != v){
                unionSet(u , v, parent , rank);
                minWeight += wt;
            }
        }
        return minWeight;
    }

};

int main(){
    int vertex = 6;
    int edge = 9;

    Graph g; 

    g.createEdge(0,1,2);
    g.createEdge(0,3,1);
    g.createEdge(0,4,4);
    g.createEdge(1,2,3);
    g.createEdge(1,3,3);
    g.createEdge(1,5,7);
    g.createEdge(2,3,5);
    g.createEdge(2,5,8);
    g.createEdge(3,4,9);

    
    g.printGraph();

    cout<<endl;

    int ans = g.minimumSpanningTree(vertex);
    cout<<"cost of minimum spanning tree is "<<ans;
    
    

    return 0;
}