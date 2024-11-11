#include <bits/stdc++.h>

using namespace std;

int main() {
    string dna;
    cin >> dna;

    char current = dna.front();
    int length = 1, max = 1;
    for (size_t i = 1; i < dna.length(); i++) {
        if (dna.at(i) != current) {
            current = dna.at(i);
            length = 1;
        } else {
            length++;
        }

        if (length > max) {
            max = length;
        }
    }

    cout << max << endl;

    return 0;
}