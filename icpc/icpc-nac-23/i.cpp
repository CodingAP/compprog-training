#include <bits/stdc++.h>

using namespace std;

int getFactorCount(int n) {
    int count = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            count++;
            if (i * i != n) count++;
        }
    }
    return count;
}

double logBase(long long num, int base) {
    return log(num) / log(base);
}

int main() {
    long long x;
    cin >> x;

    if (x == 1) {
        cout << "1" << endl;
        return 0;
    }

    int n = 1;
    while (true) {
        double value = logBase(x, n++);
        if (abs(value - (int) value) < 0.000001) {
            int result = n - 1;
            if (getFactorCount(result) == (int) value) {
                cout << result << endl;
                return 0;
            }
        }
        
        if (n == 100) break;
    }

    cout << "-1" << endl;
    return 0;
}