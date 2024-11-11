#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int minNum = -1, maxNum = -1;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        if (minNum == -1 && maxNum == -1) {
            minNum = a;
            maxNum = b;
        } else {
            if (maxNum >= a && b >= minNum) {
                minNum = max(a, minNum);
                maxNum = min(b, maxNum);
            } else {
                cout << "bad news" << endl;
                return 0;
            }
        }
    }

    cout << (maxNum - minNum + 1) << " " << minNum << endl;

    return 0;
}