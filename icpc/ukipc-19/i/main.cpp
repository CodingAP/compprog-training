// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://icpcarchive.github.io/Europe%20Subcontests/UK%20and%20Ireland%20Programming%20Contest%20(UKIPC)/2019%20UK%20and%20Ireland%20Programming%20Contest/problems.pdf
// United Kingdom and Ireland Programming Contest 2019, Problem I
//
// My Initial Version
//
// Author: Alex Prosser
// Date: 2/17/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // take input
    int depth, sum;
    cin >> depth >> sum;

    // impossible case: if the smallest possible triangle can't be created, then it is impossible
    if (sum < pow(2, depth - 1)) {
        cout << "impossible" << endl;
        return 0;
    }

    // print sum for first line
    cout << sum << endl;
    
    // keep halving and moving the sums
    // uses the previous row to calculate new numbers
    vector<int> current, previous;
    previous.push_back(sum);
    for (int i = 1; i < depth; i++) {
        for (int j = 0; j < previous.size(); j++) {
            if (current.empty()) { // start of rows starts with half the first number of the previous row (adds another element)
                current.push_back(floor(previous[j] / 2.0));
                current.push_back(ceil(previous[j] / 2.0));
            } else { // figure out what number is needed to keep triangle consistent
                current.push_back(previous[j] - current.back());
            }
        }

        // print the row out
        for (int i = 0; i < current.size(); i++) {
            cout << current[i] << " ";
        }
        cout << endl;

        //
        previous = current;
        current.clear();
    }
    
    return 0;
}