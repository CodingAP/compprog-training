#include <bits/stdc++.h>

using namespace std;

vector<int> nodeLinks;
vector<int> nodeLinkSize;

int find(int x) {
    while (x != nodeLinks[x]) x = nodeLinks[x];
    return x;
}

bool unite(int a, int b, int neededSize) {
    a = find(a);
    b = find(b);

    if (a == b) return false;
    if (nodeLinkSize[a] < nodeLinkSize[b]) swap(a, b);
    nodeLinkSize[a] += nodeLinkSize[b];
    nodeLinks[b] = a;

    return (nodeLinkSize[a] == neededSize);  
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    if (nodes == 1) {
        cout << "0" << endl;
        return 0;
    }

    nodeLinks.reserve(nodes + 1);
    nodeLinkSize.reserve(nodes + 1);

    for (int i = 1; i <= nodes; i++) nodeLinks[i] = i;
    for (int i = 1; i <= nodes; i++) nodeLinkSize[i] = 1;

    for (int i = 0; i < edges; i++) {
        int a, b;
        cin >> a >> b;

        if (unite(a, b, nodes)) {
            cout << (i + 1) << endl;
            return 0;
        }
    }

    cout << "-1" << endl;
    return 0;
}