#include <iostream>
#include <string>
#include <sstream>
#include <tuple>
#include <vector>

using namespace std;

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss(s);
    std::string item;

    while (getline(ss, item, delim)) {
        result.push_back(item);
    }

    return result;
}

int main(int argc, char *argv[]) {
    vector<tuple<string, string, string>> icpc, outside; 

    // get icpc names/emails
    string line;
    while (getline(cin, line)) {
        if (line.size() <= 1) break;


    }

    return 0;
}