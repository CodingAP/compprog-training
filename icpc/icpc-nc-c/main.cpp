#include <iostream>

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

    int height, width;
    cin >> height >> width;

    char *grid = new char[width * height];
    string line;
    for (int y = 0; y < height; y++) {
        getline(cin, line);
        for (int x = 0; x < width; y++) {
            grid[y * width + x] = line[x];
        }
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; y++) {
            // count neighbors
        }
    }

    delete [] grid;

    return 0;
}