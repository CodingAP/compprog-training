#include <iostream>

using namespace std;

int main() {
    int corners, edges, centers;
    cin >> corners >> edges >> centers;

    if (corners != 4) {
        cout << "impossible" << endl;
        return 0;
    }

    if (edges <= centers) {
        cout << "impossible" << endl;
        return 0;
    }

    
    return 0;
}