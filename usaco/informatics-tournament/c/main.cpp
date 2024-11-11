// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://codeforces.com/group/zzg7xgdKBe/contest/505887/problem/C
// USACO.Guide Informatics Tournament, Standard: C. Balanced Difference
//
// Author: Alex Prosser
// Date: 3/5/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());
    
    return 0;
}