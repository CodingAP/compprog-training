// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://usaco.org/index.php?page=viewproblem2&cpid=939
// USACO 2019 US Open Bronze Contest, Problem 1: Bucket Brigade
//
// Author: Alex Prosser
// Date: 2/26/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <bits/stdc++.h>

using namespace std;

// node structure to hold information about each search
struct Node {
    int x;
    int y;
    int steps;
};

// all neighbors to search
vector<pair<int, int>> directions = {
    { 1,  0},
    { 0,  1},
    {-1,  0},
    { 0, -1}
};

int main() {
    // take input and create grid
    // find the start and end points
    const int SIZE = 10;
    vector<vector<char>> grid(SIZE);
    char input;
    pair<int, int> start, end;
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            cin >> input;
            grid[y].push_back(input);

            if (input == 'B')
                start = {x, y};
            else if (input == 'L')
                end = {x, y};
        }
    }

    // bfs to find shortest path
    queue<Node> q;
    set<pair<int, int>> visited;

    q.push({start.first, start.second, 0});
    while (!q.empty()) {
        // get current node
        Node current = q.front(); q.pop();
        visited.insert({current.x, current.y});

        // if node is complete, return how many steps (first return should be shortest)
        if (current.x == end.first && current.y == end.second) {
            cout << current.steps - 1 << endl;
            return 0;
        }

        // try all valid directions (within bounds and not a rock)
        // push all valid directions back in queue
        for (int i = 0; i < directions.size(); i++) {
            int newX = current.x + directions[i].first;
            int newY = current.y + directions[i].second;
            if (visited.find({newX, newY}) == visited.end() &&
                newX >= 0 && newX < SIZE &&
                newY >= 0 && newY < SIZE &&
                grid[newY][newX] != 'R') {
                q.push({current.x + directions[i].first, current.y + directions[i].second, current.steps + 1});
            }
        }
    }

    // return -1 if no path is found
    // using bfs here is a bit overkill because there is only one rock, but it's nice to write bfs so idc
    cout << "-1" << endl;
    return 0;
}