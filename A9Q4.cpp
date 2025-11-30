#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void dijkstra(int V, vector<vector<pair<int,int>>> &adj, int src) 
{
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;

    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &p : adj[u]) {
            int v = p.first;
            int w = p.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "\nShortest distances from source " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " -> Distance = " << dist[i] << "\n";
    }
}

int main() 
{

    int V = 6;

    vector<vector<pair<int,int>>> adj(V);

    vector<tuple<int,int,int>> edges = {
        {0, 1, 4},
        {0, 2, 1},
        {2, 1, 2},
        {1, 3, 1},
        {2, 3, 5},
        {3, 4, 3},
        {4, 5, 2}
    };

    for (auto &[u, v, w] : edges) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int src = 0;

    cout << "=== DIJKSTRA'S ALGORITHM (HARDCODED GRAPH) ===\n";
    cout << "Running from source: " << src << "\n";

    dijkstra(V, adj, src);

    return 0;
}
