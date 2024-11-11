#include <bits/stdc++.h>

using namespace std;

int main() {
    int testCases;
    cin >> testCases;

    for (int i = 0; i < testCases; i++) {
        int num;
        cin >> num;

        string result = "";
        if (num % 2 == 1) result += "O";

        int sqrtNum = sqrt(num);
        if (sqrtNum * sqrtNum == num) result += "S";

        if (result == "") result = "EMPTY";

        cout << result << endl;
    }

    return 0;
}