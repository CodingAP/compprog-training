// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://usaco.org/index.php?page=viewproblem2&cpid=783
// USACO 2018 January Bronze Contest, Problem 1: Blocked Billboard II
//
// Author: Alex Prosser
// Date: 2/26/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <bits/stdc++.h>

using namespace std;

// returns whether or not a point is contained in a rectangle
bool contains(int x, int y, int x1, int y1, int x2, int y2) {
    return x >= x1 && x <= x2 && y >= y1 && y <= y2;
}

// gets the area of the intersecting parts of the rectangle
// if not colliding, returns 0
int getIntersectingArea(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    int intersectW = min(x2, x4) - max(x1, x3);
    int intersectH = min(y2, y4) - max(y1, y3);
    return (intersectW > 0 && intersectH > 0) ? intersectW * intersectH : 0;
}

int main() {
    // take line 1 input
    int billboardAX1, billboardAY1, billboardAX2, billboardAY2;
    cin >> billboardAX1 >> billboardAY1 >> billboardAX2 >> billboardAY2;

    // get area of billboard a
    int billboardAArea = (billboardAX2 - billboardAX1) * (billboardAY2 - billboardAY1);

    // take line 2 input
    int billboardBX1, billboardBY1, billboardBX2, billboardBY2;
    cin >> billboardBX1 >> billboardBY1 >> billboardBX2 >> billboardBY2;

    // find amount of intersecting corners
    int intersectingCorners = 0;
    if (contains(billboardAX1, billboardAY1, billboardBX1, billboardBY1, billboardBX2, billboardBY2)) intersectingCorners++;
    if (contains(billboardAX2, billboardAY1, billboardBX1, billboardBY1, billboardBX2, billboardBY2)) intersectingCorners++;
    if (contains(billboardAX1, billboardAY2, billboardBX1, billboardBY1, billboardBX2, billboardBY2)) intersectingCorners++;
    if (contains(billboardAX2, billboardAY2, billboardBX1, billboardBY1, billboardBX2, billboardBY2)) intersectingCorners++;

    int coveredArea = 0;
    if (intersectingCorners < 2) {
        // if 0 or 1 corner(s) are intersecting, we have to cover the entire billboard
        coveredArea = billboardAArea;
    } else if (intersectingCorners == 2) {
        // if 2 corners are intersecting, we need to remove the area covered already
        coveredArea = billboardAArea - getIntersectingArea(billboardAX1, billboardAY1, billboardAX2, billboardAY2, billboardBX1, billboardBY1, billboardBX2, billboardBY2);
    }
    // if 3 or 4 corners are intersecting, the entire billboard is covered, so no tarp is needed (also 3 corners is impossible to have, so...)

    cout << coveredArea << endl;

    return 0;
}