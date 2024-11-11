#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    long long result = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        if (i > 0 && arr[i] < arr[i - 1]) {
            result += arr[i - 1] - arr[i];
            arr[i] = arr[i - 1];
        }
    }

    cout << result << endl;

    return 0;
}