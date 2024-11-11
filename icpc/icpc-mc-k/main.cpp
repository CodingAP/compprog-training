#include <iostream>
#include <map>
#include <set>

using namespace std;

int checkCycle(map<int, map<int, int>> graph, int searching, int current, set<int> &visited) {
    if (visited.count(current) != 0 && searching == current) return graph;

    visited.insert(current);

    int weight = -1;
    for (auto bridges : graph[current]) {
        weight += checkCycle(graph, searching, bridges.first, visited);
    }

    return weight;
}

int main(int argc, char *argv[]) {
    // **** REMOVE BEFORE SUBMISSION ****
    if (argc == 1) {
        // no cmdline input, run from input
    } else if (argc == 2) {
        // reads from input file and outputs to output file
        freopen(argv[1], "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    int nodes, edges;
    cin >> nodes >> edges;

    map<int, map<int, int>> graph;
    for (int i = 0; i < nodes; i++) {
        map<int, int> bridges;
        graph[i] = bridges;
    }

    for (int i = 0; i < edges; i++) {
        int source, dest, weight;
        cin >> source >> dest >> weight;
        graph[source][dest] = weight;
    }

    map<int, int> cycles;
    for (int i = 0; i < nodes; i++) {
        set<int> visited;
        cycles[i] = checkCycle(graph, i, i, visited);
    }

    return 0;
}