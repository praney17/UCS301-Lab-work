#include <iostream>
using namespace std;


struct Edge {
    int u, v, w;
};


class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx != ry) {
            if (rank[rx] < rank[ry])
                parent[rx] = ry;
            else if (rank[ry] < rank[rx])
                parent[ry] = rx;
            else {
                parent[ry] = rx;
                rank[rx]++;
            }
        }
    }
};


void kruskalMST(int V, vector<Edge> edges) {
    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b) { return a.w < b.w; });

    DSU dsu(V);

    int mst_weight = 0;
    vector<Edge> mst;

    for (auto &e : edges) {
        if (dsu.find(e.u) != dsu.find(e.v)) {
            dsu.unite(e.u, e.v);
            mst.push_back(e);
            mst_weight += e.w;
        }
    }

    cout << "\n---- Kruskal's MST ----\n";
    for (auto &e : mst)
        cout << e.u << " - " << e.v << " : " << e.w << "\n";

    cout << "Total MST Weight = " << mst_weight << "\n";
}


void primMST(int V, vector<vector<pair<int,int>>> &adj) {
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);
    vector<int> parent(V, -1);

    priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;

    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (auto &p : adj[u]) {
            int v = p.first;
            int w = p.second;

            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    cout << "\n---- Prim's MST ----\n";
    int total = 0;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " : " << key[i] << "\n";
        total += key[i];
    }
    cout << "Total MST Weight = " << total << "\n";
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E);
    vector<vector<pair<int,int>>> adj(V);

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

        // for Prim
        adj[edges[i].u].push_back({edges[i].v, edges[i].w});
        adj[edges[i].v].push_back({edges[i].u, edges[i].w});
    }

    while (true) {
        cout << "\n===== MENU =====\n";
        cout << "1. Kruskal's MST\n";
        cout << "2. Prim's MST\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";

        int ch;
        cin >> ch;

        switch (ch) {
            case 1:
                kruskalMST(V, edges);
                break;

            case 2:
                primMST(V, adj);
                break;

            case 3:
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
