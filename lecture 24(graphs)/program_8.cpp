// cycle detection in Directed Graph using BFS
// using kahn's algorithm
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

    

    bool cycleDetection(int vertex){
        // indegree of every node
        unordered_map<int , int>inDegree;
        for(auto i : adj_list){
            for(auto j : i.second){
                inDegree[j]++;
            }   
        }

        // queue
        queue<int>q;
        for(int i=1 ; i<=vertex ; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        // do bfs
        int count = 0;
        vector<int>ans;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            // store ans
            ans.push_back(frontNode);
            count++;

            // check neighbour
            for(auto neighbour : adj_list[frontNode]){
                inDegree[neighbour]-- ;
                if(inDegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
        
        // false for cycle present , true for cycle not present;
        return (count == vertex) ? false : true;
    }

   
};

int main(){
    // number of nodes
    int vertex = 8;

    // number of edges
    int edge = 9;

    Graph g;
    g.addEdge_list(1,2,1);
    g.addEdge_list(2,3,1);
    g.addEdge_list(3,7,1);
    g.addEdge_list(3,8,1);
    g.addEdge_list(8,7,1);
    g.addEdge_list(2,4,1);
    g.addEdge_list(4,5,1);
    g.addEdge_list(5,6,1);
    g.addEdge_list(6,4,1);

    g.printEdge_list();

    bool ans = g.cycleDetection(vertex);
    cout<<endl;
    (ans) ? cout<<"cycle present " : cout<<"cycle not present ";
    



    return 0;
}