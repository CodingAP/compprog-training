// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://codeforces.com/group/zzg7xgdKBe/contest/505887/problem/A
// USACO.Guide Informatics Tournament, Standard: A. TriNum Array
//
// Author: Alex Prosser
// Date: 3/5/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <bits/stdc++.h>

using namespace std;

int main() {
    // take input
    int count;
    cin >> count;

    // construct a segment tree with set
    vector<int> numbers(count);
    for (int i = 0; i < count; i++) {
        cin >> numbers[i];
    }

    // use a sliding window to keep track on which subarray has 3 numbers in it
    int left = 0, right = 0, maximum = -1;
    map<int, int> frequency;
    while (right < numbers.size()) {
        frequency[numbers[right]]++;

        // if current subarray has more than 3 elements, move the left until it doesn't
        while (frequency.size() > 3) {
            frequency[numbers[left]]--;
            if (frequency[numbers[left]] == 0) frequency.erase(numbers[left]);
            left++;
        }

        // find the largest size of the subarray
        maximum = max(maximum, right - left + 1);
        right++;
    }

    cout << maximum << endl;
    return 0;
}