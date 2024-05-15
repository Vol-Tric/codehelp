// ford fulkerson for network flow
#include<bits/stdc++.h>

using namespace std;

#define V 6 // Number of vertices in the graph

// Function to perform Depth First Search (DFS) to find an augmenting path
bool dfs(vector<vector<int>>& rGraph, int s, int t, vector<int>& parent) {
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (visited[v] == false && rGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[t]; // Return true if there's a path from source to sink in the residual graph
}

// Ford-Fulkerson algorithm to find maximum flow
int fordFulkerson(vector<vector<int>>& graph, int s, int t) {
    int u, v;

    // Create a residual graph and initialize it with the original capacities
    vector<vector<int>> rGraph = graph;

    vector<int> parent(V, -1); // Array to store the augmented path

    int max_flow = 0; // Initialize max flow

    // Augment the flow while there's a path from source to sink
    while (dfs(rGraph, s, t, parent)) {
        int path_flow = INT_MAX;
        // Find the minimum residual capacity of the edges along the path filled by DFS
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        // Update the residual capacities of the edges and reverse edges along the path
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        // Add path flow to overall flow
        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    // Sample flow network represented as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    int source = 0; // Source node
    int sink = 5;   // Sink node

    cout << "The maximum possible flow is " << fordFulkerson(graph, source, sink) << endl;

    return 0;
}