// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://usaco.org/index.php?page=viewproblem2&cpid=1059
// USACO 2020 December Bronze Contest, Problem 1: Do You Know Your ABCs?
//
// Author: Alex Prosser
// Date: 2/27/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <bits/stdc++.h>

using namespace std;

int main() {
    // take input
    vector<int> numbers(7);
    for (int i = 0; i < numbers.size(); i++) {
        cin >> numbers[i];
    }

    // sort the numbers
    // a and b are guaranteed to be the smallest numbers, and the largest number is a + b + c, so remove a + b
    sort(numbers.begin(), numbers.end());
    int a = numbers[0], b = numbers[1];
    int c = numbers[numbers.size() - 1] - a - b;
    cout << a << " " << b << " " << c << endl;
    return 0;
}