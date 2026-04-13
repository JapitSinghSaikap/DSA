#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; // {distance, node}

vector<int> dijkstra(int n, vector<vector<pii>>& graph, int start) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        // TODO: implement your logic here
    }
    
    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<pii>> graph(n); 
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u}); // remove for directed graph
    }
    
    vector<int> result = dijkstra(n, graph, 0);
    
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}