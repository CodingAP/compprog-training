// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://icpcarchive.github.io/North%20America%20Contests/North%20Central%20Regional%20Contest/2019%20North%20Central%20Regional%20Contest/problems.pdf
// ICPC North Central 2019 Regionals, Problem B
//
// USAGE: ./program.exe [input_file]
//     - input_file <optional>: if present, runs program off file rather than cmdline
//
// Author: Alex Prosser
// Date: 10/21/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool checkSwapFree(string word1, string word2) {
    int swapped = 0;
    for (int i = 0; i < word1.length(); i++) {
        if (word1[i] != word2[i]) swapped++;
    }

    return swapped > 2;
}

int main(int argc, char *argv[]) {
    // **** REMOVE BEFORE SUBMISSION ****
    if (argc == 1) {
        // no cmdline input, run from input
    } else if (argc == 2) {
        freopen(argv[1], "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    int max = -1;
    for (int i = 0; i < n; i++) {
        vector<string> swapFree;
        swapFree.push_back(words[i]);
        for (int j = 0; j < n; j++) {
            bool isSwapFree = true;
            for (int k = 0; k < swapFree.size(); k++) {
                if (!checkSwapFree(swapFree[k], words[j])) isSwapFree = false;
            }
            
            if (isSwapFree) swapFree.push_back(words[j]);
        }
        if ((int) swapFree.size() > max) max = (int) swapFree.size();
    }

    cout << max << endl;

    return 0;
}