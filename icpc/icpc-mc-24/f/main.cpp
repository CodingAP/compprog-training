#include <bits/stdc++.h>

using namespace std;

string allPossible = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~' ";

string replaceCharacters(string source, char delimiter, char replacement) {
    string result;
    for (size_t i = 0; i < source.length(); i++) {
        if (source[i] == delimiter) result += replacement;
        else result += source[i];
    }
    return result;
}

int countCharacters(string str) {
    vector<string> emoticons = {
        ":)",
        ":-)",
        ":-(",
        ";-)",
        "xD",
        "^_^",
        "-_-",
        "^o^",
        "^^;",
        "(..)"
    };

    int count = 0;
    for (size_t i = 0; i < str.length(); i++) {
        int skip = -1;
        // cout << "index: " << i << endl;
        for (size_t j = 0; j < emoticons.size(); j++) {
            bool hasEmoji = true;
            for (size_t k = 0; k < emoticons[j].length(); k++) {
                if (emoticons[j][k] != str[i + k]) hasEmoji = false;
            }
            if (hasEmoji) skip = emoticons[j].length();

            // cout << "\t emoji " << emoticons[j] << ": " << hasEmoji << endl;
        }
        if (skip != -1) i += skip - 1;
        count++;
    }

    return count;
}

int main() {
    string line;
    getline(cin, line);

    int min = 101, max = -1;
    for (int i = 0; i < allPossible.length(); i++) {
        for (int j = 0; j < allPossible.length(); j++) {
            string transformed = replaceCharacters(line, allPossible[i], allPossible[j]);
            int length = countCharacters(transformed);

            if (length < min) min = length;
            if (length > max) max = length;
        }
    }

    cout << min << " " << max << endl;
    
    return 0;
}