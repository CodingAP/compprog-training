#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long double input;
    cin >> input;

    cout << ceil(log2(input)) + 1 << endl;
    return 0;
}
