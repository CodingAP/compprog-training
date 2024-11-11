#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    // **** REMOVE BEFORE SUBMISSION ****
    if (argc == 1) {
        // no cmdline input, run from input
    } else if (argc == 2) {
        freopen(argv[1], "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    return 0;
}