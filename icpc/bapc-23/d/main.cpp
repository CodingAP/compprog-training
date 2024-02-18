#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int wordCount, letterCount;
    cin >> wordCount >> letterCount;

    vector<string> words(wordCount);
    for (int i = 0; i < wordCount; i++) {
        cin >> words[i]; 
    }

    for (int i = 0; i < letterCount; i++) {
        map<char, int> frequency;
        for (int j = 0; j < wordCount; j++) {
            frequency[words[j][i]]++;
        }

        pair<char, int> max = make_pair('X', -1);
        for (auto pair : frequency) {
            if (pair.second > max.second || (pair.second == max.second && pair.first < max.first)) {
                max = pair;
            }
        }
        cout << max.first;
    }

    cout << endl;

    return 0;
}