// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://usaco.org/index.php?page=viewproblem2&cpid=987
// USACO 2020 January Bronze Contest, Problem 1: Word Processor
//
// Author: Alex Prosser
// Date: 2/26/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <bits/stdc++.h>

using namespace std;

int main() {
    // take input
    int wordCount, maxLength;
    cin >> wordCount >> maxLength;

    vector<string> words(wordCount);
    for (int i = 0; i < wordCount; i++) {
        cin >> words[i];
    }

    // print all words with the limited buffer
    string current = "";
    int size = 0, index = 0;
    while (index != wordCount) {
        if (size + words[index].length() > maxLength) {
            current.pop_back();
            cout << current << endl;
            current = "";
            size = 0;
        }

        current += words[index] + " ";
        size += words[index].length();
        index++;
    }

    // make sure to print last line
    cout << current << endl;

    return 0;
}