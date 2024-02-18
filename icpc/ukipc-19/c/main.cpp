// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://icpcarchive.github.io/Europe%20Subcontests/UK%20and%20Ireland%20Programming%20Contest%20(UKIPC)/2019%20UK%20and%20Ireland%20Programming%20Contest/problems.pdf
// United Kingdom and Ireland Programming Contest 2019, Problem C
//
// Author: Alex Prosser
// Date: 2/17/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
#include <map>
#include <queue>

using namespace std;

int main() {
    // take input
    int cardCount, handSize;
    cin >> cardCount >> handSize;

    // count the frequency of the cards
    map<int, int> frequency;
    for (int i = 0; i < cardCount; i++) {
        int card;
        cin >> card;
        frequency[card]++;
    }

    // create a priority queue that sorts by max frequency 
    struct {
        bool operator()(const pair<int, int> a, const pair<int, int> b) const { return a.second < b.second; }
    } compare;
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> queue(frequency.begin(), frequency.end(), compare);

    // distribute enough hands for the cards
    vector<vector<int>> hands(cardCount / handSize);
    for (int i = 0; i < hands.size(); i++) {
        vector<pair<int, int>> hand;
        // try to take one card from each number 
        for (int j = 0; j < handSize; j++) {
            // if there isn't another number to take, that means that there is a forced pair, which is impossible
            if (queue.empty()) {
                cout << "impossible" << endl;
                return 0;
            }

            // take the number
            hand.push_back(queue.top());
            queue.pop();
        }

        // remove one card from the number and return to queue if there are still some left 
        for (int j = 0; j < handSize; j++) {
            hands[i].push_back(hand[j].first);
            if (hand[j].second != 1) queue.push(make_pair(hand[j].first, hand[j].second - 1));
        }
    }

    // print out hands if possible
    for (int i = 0; i < hands.size(); i++) {
        for (int j = 0; j < hands[i].size(); j++) {
            cout << hands[i][j] << ((j == hands[i].size() - 1) ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}