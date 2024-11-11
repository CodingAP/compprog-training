// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://usaco.org/index.php?page=viewproblem2&cpid=855
// USACO 2018 December Bronze Contest, Problem 1: Mixing Milk
//
// Author: Alex Prosser
// Date: 2/27/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <bits/stdc++.h>

using namespace std;

int main() {
    // take input
    vector<pair<int, int>> buckets(3);
    int capacity, amount;
    for (int i = 0; i < buckets.size(); i++) {
        cin >> capacity >> amount;
        buckets[i] = {capacity, amount};
    }

    // simulate 100 circular pours between the buckets 
    int current = 0;
    for (int i = 0; i < 100; i++) {
        int next = (current + 1) % 3;
        if (buckets[current].second + buckets[next].second > buckets[next].first) {
            buckets[current].second = (buckets[current].second + buckets[next].second) - buckets[next].first;
            buckets[next].second = buckets[next].first;
        } else {
            buckets[next].second = buckets[current].second + buckets[next].second;
            buckets[current].second = 0;
        }
        current = next;
    }

    // print out final amounts
    for (auto bucket : buckets) cout << bucket.second << endl;

    return 0;
}