#include <bits/stdc++.h>

using namespace std;

int main() {
    int g, p;
    cin >> g >> p;
    string guards;
    cin >> guards;

    queue<pair<string, int>> queue;
    unordered_set<string> visited;

    queue.push({guards, 0});
    visited.insert(guards + to_string(0));

    while (!queue.empty()) {
        pair<string, int> current = queue.front(); queue.pop();
        string currentGuards = current.first;
        int playersPassed = current.second;

        if (playersPassed == p) {
            cout << 1 << endl;
            return 0;
        }

        for (int i = 0; i < g - 1; ++i) {
            if (currentGuards[i] != 'R' && currentGuards[i + 1] != 'L') {
                string newGuards = currentGuards;
                newGuards[i] = 'R';
                newGuards[i + 1] = 'L';
                string newState = newGuards + to_string(playersPassed + 1);

                if (visited.find(newState) == visited.end()) {
                    queue.push({newGuards, playersPassed + 1});
                    visited.insert(newState);
                }
            }
        }
    }

    cout << 0 << endl;
    return 0;
}