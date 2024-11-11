#include <iostream>
#include <queue>
#include <map>

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
    int *original = new int[n], *shuffled = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> original[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> shuffled[i];
    }

    map<int, int> originalCount, shuffledCount;

    for (int i = 0; i < n; i++) {
        cout << shuffled[i] << " ";

        originalCount[original[i]]++;
        shuffledCount[shuffled[i]]++;

        if (originalCount.size() == shuffledCount.size()) {
            bool same = true;
            for (auto og : originalCount) {
                if (shuffledCount[og.first] != og.second) same = false;
            }

            if (same && i != n - 1) {
                cout << "# ";
                originalCount.clear();
                shuffledCount.clear();
            }
        }
    }

    delete [] original;
    delete [] shuffled;
    
    return 0;
}