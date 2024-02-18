// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://icpcarchive.github.io/Europe%20Subcontests/UK%20and%20Ireland%20Programming%20Contest%20(UKIPC)/2019%20UK%20and%20Ireland%20Programming%20Contest/problems.pdf
// United Kingdom and Ireland Programming Contest 2019, Problem F
//
// Author: Alex Prosser
// Date: 2/17/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // take input
    int bucketCount, maxWeight;
    cin >> bucketCount >> maxWeight;

    vector<int> buckets(bucketCount);
    for (int i = 0; i < bucketCount; i++) {
        cin >> buckets[i];
    }

    // edge case: if only one bucket is given, just return 1 (it is guaranteed to be less than maxWeight)
    if (bucketCount == 1) {
        cout << "1" << endl;
        return 0;
    }

    sort(buckets.begin(), buckets.end());

    // use two "pointers" (indexes) to move on each side of the vector
    // if the pointer's value together are less than maxWeight, take both and add 1
    // else, only take the right side and add 1
    int left = 0, right = bucketCount - 1; 
    int volunteers = 0;
    while (left <= right) {
        // edge case: if pointers are on the same item, add 1 without checking
        if (left == right) {
            volunteers++;
            break;
        } else if (buckets[left] + buckets[right] <= maxWeight) left++;
        right--;
        volunteers++;
    }

    cout << volunteers << endl;
    return 0;
}