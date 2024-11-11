#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    // **** REMOVE BEFORE SUBMISSION ****
    if (argc == 1) {
        // no cmdline input, run from input
    } else if (argc == 2) {
        // reads from input file and outputs to output file
        freopen(argv[1], "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    int n;
    cin >> n;
    vector<int> regions(n);
    for (int i = 0; i < n; i++) {
        cin >> regions[i];
    }

    sort(regions.begin(), regions.end());
    int max = 0;

    for (int i = 0; i < n; i++) {
        max += regions[i] / ((i < n / 2 + 1) ? 2 : 1);
    }

    cout << max << endl;

    return 0;
}