#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int total, done, currently;
    cin >> total >> done >> currently;

    int totalSum = 0;
    vector<int> sizes(total);
    for (int i = 0; i < total; i++) {
        int size;
        cin >> size;
        sizes[i] = size;
        totalSum += size;
    }

    sort(sizes.begin(), sizes.end());

    int undownloaded = 0;
    for (int i = 0; i < (total - (done + currently)); i++) {
        undownloaded += sizes[i]; 
    }

    cout << ((double) (totalSum - undownloaded) / totalSum) * 100 << endl;

    return 0;
}