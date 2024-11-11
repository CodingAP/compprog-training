#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int testCases;
    cin >> testCases;

    for (int i = 0; i < testCases; i++) {
        int arrayCount;
        cin >> arrayCount;
        vector<pair<int, int>> arrays;

        for (int j = 0; j < arrayCount; j++) {
            int num1, num2;
            cin >> num1 >> num2;
            arrays.push_back({ num1, num2 });
        }

        sort(arrays.begin(), arrays.end(), [](pair<int, int> a, pair<int, int> b) {
            return (a.first + a.second) < (b.first + b.second);
        });

        for (int j = 0; j < arrayCount; j++) {
            cout << arrays[j].first << " " << arrays[j].second;
            if (j != arrayCount - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}