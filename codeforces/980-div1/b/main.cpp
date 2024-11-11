#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int testCases;
    cin >> testCases;

    for (int i = 0; i < testCases; i++) {
        int length;
        cin >> length;
        
        vector<int> scores, parameters;
        for (int i = 0; i < length; i++) {
            int score;
            cin >> score;
            scores.push_back(score);
        }
    
        for (int i = 0; i < length; i++) {
            int parameter;
            cin >> parameter;
            parameters.push_back(parameter);
        }

        
    }

    return 0;
}