// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://codeforces.com/group/zzg7xgdKBe/contest/505887/problem/B
// USACO.Guide Informatics Tournament, Standard: B. Two Way Homework
//
// This is not correct!
//
// Author: Alex Prosser
// Date: 3/5/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <bits/stdc++.h>

#define ll unsigned long long
using namespace std;

map<pair<int, int>, ll> memo;

ll findMinimumSum(int n, vector<ll> &a, vector<ll> &b, int index, ll multiplier) {
    if (index == n) return 0;
    if (memo.count({index, multiplier})) return memo[{index, multiplier}];

    // choose a, multiplier *= 2
    ll chooseA = a[index] * multiplier + findMinimumSum(n, a, b, index + 1, multiplier * 2);

    // choose b, no multiplier increase
    ll chooseB = b[index] * multiplier + findMinimumSum(n, a, b, index + 1, multiplier);

    ll newSum = min(chooseA, chooseB);
    memo[{index, multiplier}] = newSum;

    return newSum;
}

int main() {
    // take input
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    // find the minimum of the array with s
    cout << findMinimumSum(n, a, b, 0, 1) << endl;
    return 0;
}