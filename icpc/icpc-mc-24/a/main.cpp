#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int min = 100001, max = -1;
    for (int i = 0; i < n; i++) {
        int price;
        cin >> price;

        if (price < min) min = price;
        if (price > max) max = price;
    }

    int reimburse = max / 2;
    int youPay = min - reimburse;

    if (youPay < 0) youPay = 0;

    cout << youPay << endl;
    return 0;
}