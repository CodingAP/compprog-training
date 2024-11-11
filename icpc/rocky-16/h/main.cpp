// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://icpcarchive.github.io/North%20America%20Contests/Rocky%20Mountain%20Regional%20Contest/2016%20Rocky%20Mountain%20Regional%20Contest/problems.pdf
// Rocky Mountain Regional Programming Contest 2016, Problem H
//
// Author: Alex Prosser
// Date: 2/19/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <iostream>
#include <cmath>

using namespace std;

bool compress(string &list) {
    string newList = "";
    for (int i = 0; i < list.size(); i++) {
        if (list[i] == list[i + 1] && list[i] != '8') {
            newList += (list[i] == '2') ? '4' : (list[i] == '4') ? '8' : ' ';
            i++;
        } else {
            newList += list[i];
        }
    }
    if (list == newList) return false;
    list = newList;
    return true;
}

bool isNice(string list) {
    int count = 0;
    for (int i = 0; i < list.size(); i++) {
        if (list[i] != '8') {
            return false;
        }
        count++;
    }

    return (count & (count - 1) == 0);
} 

int main() {
    int count;
    cin >> count;

    for (int i = 0; i < count; i++) {
        string list;
        cin >> list;

        string mutatedList = list;
        while (compress(mutatedList)) {}
        cout << list << ", " << mutatedList << ", " << isNice(mutatedList) << endl;
    }
}