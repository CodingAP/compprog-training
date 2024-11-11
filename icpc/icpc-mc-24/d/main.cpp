#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << fixed << setprecision(6) << 1.0 << endl;
        return 0;
    }

    vector<vector<int>> tree(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> degrees(n + 1, 0);
    for (int node = 1; node <= n; ++node) {
        degrees[node] = tree[node].size();
    }

    double totalCentrality = 0.0;
    for (int i = 1; i <= n; i++) {
        double cascadeCentrality = 1.0;
        vector<bool> visited(n + 1, false);

        queue<pair<int, int>> q;
        q.push({i, 1});
        visited[i] = true;

        while (!q.empty()) {
            int current = q.front().first;
            int productOfDegrees = q.front().second;
            q.pop();

            for (int neighbor : tree[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    int newProduct = productOfDegrees * degrees[neighbor];
                    cascadeCentrality += 1.0 / newProduct;
                    q.push({neighbor, newProduct});
                }
            }
        }

        totalCentrality += cascadeCentrality;
    }

    cout << fixed << setprecision(6) << (totalCentrality / n) << endl;

    return 0;
}