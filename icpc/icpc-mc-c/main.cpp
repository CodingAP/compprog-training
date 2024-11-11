#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <tuple>
#include <map>

using namespace std;

const int NAIL = 0;
const int SCREW = 1;
const int BOLT = 2;
const int NUM_TOOLS = 3;

map<tuple<int, int, string>, int> memo;

int achieveTasks(vector<int> tasks, int index, int currentTool, bitset<NUM_TOOLS> tools) {
    // terminating conditions
    if (index == tasks.size()) return 0;

    // memoization
    tuple<int, int, string> key = make_tuple(index, currentTool, tools.to_string());
    if (memo.count(key) != 0) return memo[key];

    // if only 1 tool remains
    if (tools.count() == 1) {
        int lastTool = 0;
        for (int i = index; i < tasks.size(); i++) {
            if (tasks[i] == currentTool) lastTool++;
        }
        return lastTool;
    }

    // don't drop tool
    int completed = achieveTasks(tasks, index + 1, currentTool, tools);

    // drop current tool and try all possible
    bitset<NUM_TOOLS> removedTools = tools;
    removedTools[currentTool] = false;

    for (int i = 0; i < NUM_TOOLS; i++) {
        if (removedTools[i]) {
            int tasksCompleted = achieveTasks(tasks, index + 1, i, removedTools);
            if (tasksCompleted > completed) completed = tasksCompleted;
        }
    }

    // add to the completion if it matches
    if (currentTool == tasks[index]) completed++;

    memo[key] = completed;

    // if tool matches task, add one to completed tasks
    return completed;
}

int main(int argc, char *argv[]) {
    // **** REMOVE BEFORE SUBMISSION ****
    if (argc == 1) {
        // no cmdline input, run from input
    } else if (argc == 2) {
        // reads from input file and outputs to output file
        freopen(argv[1], "r", stdin);
        // freopen("output.txt", "w", stdout);
    }

    // get task count
    int n;
    cin >> n;

    // get all tasks
    vector<int> tasks;
    int task;
    for (int i = 0; i < n; i++) {
        cin >> task;
        tasks.push_back(task);
    }

    cout << max({
        achieveTasks(tasks, 0, NAIL, bitset<NUM_TOOLS>{"111"}),
        achieveTasks(tasks, 0, SCREW, bitset<NUM_TOOLS>{"111"}),
        achieveTasks(tasks, 0, BOLT, bitset<NUM_TOOLS>{"111"})
    }) << endl;

    return 0;
}