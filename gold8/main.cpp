// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// https://www.seminolestate.edu/computers/competition/samples/2021
// Gold 8 - Museum Tour
//
// USAGE: ./program.exe [input_file]
//     - input_file <optional>: if present, runs program off file rather than cmdline
//
// Author: Alex Prosser
// Date: 1/25/2024
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// include standard library stuff
#include <iostream>
#include <set>
#include <utility> // for pair

// to prevent having to type 'std::' all the time
using namespace std;

// constants to make direction stuff easier
const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;

int main(int argc, char *argv[]) {
    // **** REMOVE BEFORE SUBMISSION ****
    if (argc == 1) {
        // no cmdline input, run from input
    } else if (argc == 2) {
        // reads from input file and outputs to output file
        freopen(argv[1], "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    cout << "Enter number of rows then columns:" << endl;
    int rows, columns;
    cin >> rows >> columns;

    cout << "Enter starting room (row then column):" << endl;
    int y, x;
    cin >> y >> x;

    // find correct starting direction (corners can't be entered from east or west, so only north and south is possible)
    int direction = NORTH;
    if (y == 0) direction = SOUTH;

    // start instruction input
    cout << "Enter instructions:" << endl;
    int instruction;
    cin >> instruction;

    // counts how many instructions in total
    int instructionCount = 1;
    int leftBuilding = -1;
    set<pair<int, int>> visited; // stores pairs of coordinates already visited
    visited.insert(make_pair(x, y)); // put initial spot in there
    while (instruction != 99) {
        // to change direction, we can use numbers 0..3 to represent the direction
        // to turn right (instruction = 1), we add 1
        // to turn left (instruction = 2), we add 3 (one left turn = three right turns)
        // no turn (instruction = 0), no add (add 0)
        direction = (direction + ((instruction == 2) ? 3 : instruction)) % 4;

        if (direction == NORTH) y--;
        if (direction == EAST) x++;
        if (direction == SOUTH) y++;
        if (direction == WEST) x--;

        pair<int, int> coord = make_pair(x, y);

        // if current coord has been visited, stop program
        if (visited.find(coord) != visited.end()) {
            cout << "visited same room more than once" << endl;
            return 0;
        } else {
            visited.insert(coord);
        }

        // if we have left the bounds for the first time, mark when we did
        if ((x < 0 || x >= columns || y < 0 || y >= rows) && leftBuilding == -1) leftBuilding = instructionCount;
        
        // get next instruction and add to count
        cin >> instruction;
        if (instruction != 99) instructionCount++;
    }

    if (leftBuilding == -1) { // if we never left
        cout << "tour ended before leaving building" << endl;
    } else if (leftBuilding != instructionCount) { // if we left too early
        cout << "left building before tour was over" << endl;
    } else { // perfect solution
        cout << "successful tour" << endl;
    }

    return 0;
}