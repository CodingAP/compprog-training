#include <iostream>

using namespace std;

int main() {
    int count;
    cin >> count;

    string a, b, c;
    int length;
    for (int i = 0; i < count; i++) {
        cin >> length >> a >> b >> c;

        bool allowed = false;
        for (int j = 0; j < length; j++) {
            if (a[j] != c[j] && b[j] != c[j]) allowed = true;
        }

        cout << ((allowed) ? "YES" : "NO") << endl;
    }

    return 0;
}