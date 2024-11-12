#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

// Function to generate all subset sums of a given array, excluding the empty subset
vector<int> generate_subset_sums(const vector<int>& arr) {
    int n = arr.size();
    vector<int> subset_sums;

    // Generate all possible subset sums, excluding the empty subset
    for (int mask = 1; mask < (1 << n); ++mask) {  // Start from 1 to skip the empty subset
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {  // If the ith element is in the subset
                sum += arr[i];
            }
        }
        subset_sums.push_back(sum);
    }
    return subset_sums;
}

int find_duplicate_locker(int N, const vector<int>& buttons) {
    // Divide the buttons into two halves
    int mid = N / 2;
    vector<int> left_half(buttons.begin(), buttons.begin() + mid);
    vector<int> right_half(buttons.begin() + mid, buttons.end());

    // Generate all subset sums for each half, excluding the empty subset
    vector<int> left_sums = generate_subset_sums(left_half);
    vector<int> right_sums = generate_subset_sums(right_half);

    // Store subset sums from the left half in a hash map and check for duplicates
    unordered_map<int, int> sum_map;  // Maps sum values to the count of their occurrences

    // Insert left sums into the map
    for (int sum : left_sums) {
        if (++sum_map[sum] > 1) {
            return sum;  // Found a duplicate within the left half
        }
    }

    // Check right sums against sums in the map
    for (int sum : right_sums) {
        if (sum_map[sum] > 0) {  // Found a duplicate sum between the two halves
            return sum;
        }
        sum_map[sum]++;
    }

    // As per the problem, we should always be able to find a duplicate, so no need for a fallback return
    return -1;  // Shouldn't reach here by problem constraints
}

int main() {
    int N;
    cin >> N;
    vector<int> buttons(N);
    for (int i = 0; i < N; ++i) {
        cin >> buttons[i];
    }

    // Find and print the result
    cout << find_duplicate_locker(N, buttons) << endl;
    return 0;
}
