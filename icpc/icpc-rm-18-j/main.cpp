#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

void dijkstra(vector<vector<tuple<int, int, char>>>& graph, int source) {
    int n = graph.size();            // Number of vertices
    vector<int> dist(n, 1000000);    // Initialize distances with a large number
    vector<bool> visited(n, false);  // Initialize visited array

    // Priority queue to store vertices based on their distances
    priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>> pq;

    // Enqueue the source vertex
    pq.push(make_tuple(0, source));
    dist[source] = 0;

    while (!pq.empty()) {
        int u_dist, u;
        tie(u_dist, u) = pq.top();
        pq.pop();

        // If the vertex has been visited, skip it
        if (visited[u])
            continue;

        visited[u] = true;

        // Iterate through all adjacent vertices of u
        for (const tuple<int, int>& edge : graph[u]) {
            int v, weight;
            tie(v, weight) = edge;

            // Relaxation step
            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push(make_tuple(dist[v], v));
            }
        }
    }

    // Print the distances from source to all vertices
    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF)
            cout << "Vertex " << i << ": INF\n";
        else
            cout << "Vertex " << i << ": " << dist[i] << endl;
    }
}

int main() {
    int nodes, edges;

    cin >> nodes >> edges;

    vector<vector<tuple<int, int, char>>> graph(nodes);

    for (int i = 0; i < edges; i++) {
        int start, end, d;
        char color;
        cin >> start >> end >> d >> color;

        graph[start].push_back(make_tuple(end, d, color));
        graph[end].push_back(make_tuple(start, d, color));
    }

    // run bfs
    priority_queue<p

    return 0;
}