#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Helper function to check if the given maximum time T is feasible
bool canAchieveTime(const vector<int>& signalDelays, int N, long long D, long long L, long long T) {
    long long maxAllowedDepthDelay = T - L;
    int currentDepth = 0;
    int nodesAtDepth = 1;  // Start with the root node at depth 0

    // Traverse sorted delays from highest to lowest
    for (int i = N - 1; i >= 0; --i) {
        long long requiredTime = signalDelays[i] + currentDepth * D;
        if (requiredTime > maxAllowedDepthDelay) {
            return false; // Not feasible if delay exceeds allowed maximum
        }
        
        // Move to the next depth level if current level is fully used
        nodesAtDepth--;
        if (nodesAtDepth == 0) {
            currentDepth++;
            nodesAtDepth = 1 << currentDepth;  // Each level doubles in capacity in a balanced tree
        }
    }
    return true;
}

int main() {
    int N;
    long long D, L;
    cin >> N >> D >> L;

    vector<int> signalDelays(N);
    for (int i = 0; i < N; ++i) {
        cin >> signalDelays[i];
    }

    // Sort delays to process in descending order for the tree depth calculation
    sort(signalDelays.begin(), signalDelays.end());

    // Binary search for the minimum feasible T
    long long left = *max_element(signalDelays.begin(), signalDelays.end()) + L;
    long long right = left + (long long)ceil(log2(N)) * D;

    while (left < right) {
        long long mid = left + (right - left) / 2;
        if (canAchieveTime(signalDelays, N, D, L, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    // Output the smallest feasible T
    cout << left << endl;
    return 0;
}
