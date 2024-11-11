#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<bool> nums(n, false);

    for (int i = 0; i < n - 1; i++) {
        int index;
        cin >> index;
        nums[index - 1] = true;
    }

    for (int i = 0; i < n; i++) {
        if (!nums[i]) {
            cout << i + 1 << endl;
            break;
        }
    }

    return 0;
}