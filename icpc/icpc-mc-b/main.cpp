#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

using exlong = long long;
using point_t = pair<exlong, exlong>;

int cross(point_t a, point_t b) { return a.first * b.second - a.second * b.first; }

bool sortAngleAroundOrigin(point_t a, point_t b) {
    point_t reference = make_pair(1LL, 0LL);
    int detB = cross(reference, b);
    if (detB == 0 && reference.first * b.first + reference.second * b.second >= 0) return false;

    int detA = cross(reference, a);
    if (detA == 0 && reference.first * a.first + reference.second * a.second >= 0) return true;

    if (detA * detB >= 0) return cross(a, b) > 0;

    return detA > 0;
}

bool sortAngleAroundBase(point_t a, point_t b, int base) {
    point_t reference = make_pair(1LL, 0LL);
    point_t translatedA = make_pair(a.first + base, a.second);
    point_t translatedB = make_pair(b.first + base, b.second);

    int detB = cross(reference, translatedB);
    if (detB == 0 && reference.first * translatedB.first + reference.second * translatedB.second >= 0) return true;

    int detA = cross(reference, translatedA);
    if (detA == 0 && reference.first * translatedA.first + reference.second * translatedA.second >= 0) return false;

    if (detA * detB >= 0) return cross(translatedA, translatedB) < 0;

    return detA < 0;
}

int main(int argc, char *argv[]) {
    // **** REMOVE BEFORE SUBMISSION ****
    if (argc == 1) {
        // no cmdline input, run from input
    } else if (argc == 2) {
        // reads from input file and outputs to output file
        freopen(argv[1], "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    int triangleCount, base;
    cin >> triangleCount >> base;
    map<point_t, exlong> values;
    vector<point_t> points;
    for (int i = 0; i < triangleCount; i++) {
        exlong x, y, v;
        cin >> x >> y >> v;
        point_t point = make_pair(x - base, y);

        values[point] = v;
        points.push_back(point);
    }

    for (auto point : points) {
        cout << (point.first + base) << ", " << point.second << endl;
    }

    sort(points.begin(), points.end(), sortAngleAroundOrigin);
    for (int i = 0; i < points.size() - 1; i++) {
        exlong sum = 0;
        int scan = i + 1;
        cout << points[i].first << ", " << points[i].second << " : " << points[scan].first << ", " << points[scan].second << " : " << sortAngleAroundBase(points[i], points[scan], base) << endl;
        while (!sortAngleAroundBase(points[i], points[scan], base)) {
            sum += values[points[i]];
            scan++;
            cout << points[i].first << ", " << points[i].second << " : " << points[scan].first << ", " << points[scan].second << " : " << sortAngleAroundBase(points[i], points[scan], base) << endl;
        }
        cout << sum << endl;
        cout << endl;
    }

    return 0;
}