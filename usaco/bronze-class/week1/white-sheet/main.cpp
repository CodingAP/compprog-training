// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://codeforces.com/contest/1216/problem/C
// Codeforces Round 587, Div. 3, Problem C: White Sheet
//
// Author: Alex Prosser
// Date: 2/27/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <bits/stdc++.h>

using namespace std;

#define ll long long

// rectangle struct
struct Rectangle {
    ll x1;
    ll y1;
    ll x2;
    ll y2;
};

// gets the rectangle of the intersecting parts of the given rectangle
Rectangle getIntersectingRect(Rectangle a, Rectangle b) {
    ll x1 = max(a.x1, b.x1);
    ll y1 = max(a.y1, b.y1);
    ll x2 = min(a.x2, b.x2);
    ll y2 = min(a.y2, b.y2);

    return {x1, y1, x2, y2};
}

// gets the area of a rectangle
// returns 0 if area is invalid
ll getArea(Rectangle a) {
    ll width = a.x2 - a.x1;
    ll height = a.y2 - a.y1;
    
    if (width <= 0 || height <= 0) return 0;
    return width * height;
}

int main() {
    // take input
    vector<Rectangle> papers(3);
    ll x1, y1, x2, y2;
    for (int i = 0; i < papers.size(); i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        papers[i] = {x1, y1, x2, y2};
    }

    // get intersecting areas
    Rectangle whiteblack1 = getIntersectingRect(papers[0], papers[1]);
    Rectangle whiteblack2 = getIntersectingRect(papers[0], papers[2]);
    Rectangle blackblack = getIntersectingRect(whiteblack1, whiteblack2);

    // if all the white paper is covered, then print "NO"; else print "YES"
    if (getArea(whiteblack1) + getArea(whiteblack2) - getArea(blackblack) >= getArea(papers[0])) cout << "NO" << endl;
    else cout << "YES" << endl;

    return 0;
}