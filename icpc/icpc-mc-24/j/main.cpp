#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if (k == 1) {
        cout << (n + 1) * (n + 2) / 2 << endl;
        return 0;
    }

    vector<long long> lastRow = { 1 };
    int count = 0;

    for (int i = 1; i <= n; i++) {
        vector<long long> row(i + 1, 1);

        for (int j = 1; j < i; j++) {
            row[j] = (lastRow[j] + lastRow[j - 1]) % k;
        }

        for (int j = 0; j <= i; j++) {
            if (row[j] % k == 0) count++;
        }
        
        lastRow = row;
    }

    cout << count << endl;

    return 0;
}