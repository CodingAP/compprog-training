#include <iostream>
#include <numeric>

using namespace std;

int main(int argc, char *argv[]) {
    // **** REMOVE BEFORE SUBMISSION ****
    if (argc == 1) {
        // no cmdline input, run from input
    } else if (argc == 2) {
        // reads from input file and outputs to output file
        freopen(argv[1], "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    int chairs, commands;
    cin >> chairs >> commands;

    int *occupiedSeats = new int[chairs];
    for (int i = 0; i < chairs; i++) {
        occupiedSeats[i] = (i == 0) ? 12 : i;
    }

    int totalRotation = 0;
    int totalMultiplication = 1;
    int peopleLeft = chairs;
    for (int i = 0; i < commands; i++) {
        int x;
        char instruction;
        cin >> instruction >> x;

        if (instruction == '?') {
            cout << occupiedSeats[((x - totalRotation) / totalMultiplication) % chairs] << endl;
        } else if (instruction == '+') {
            totalRotation += x;
        } else if (instruction == '*') {
            int collisions = gcd(x, peopleLeft);
            if (collisions > 1) {
                // collisions happen
                int *newSeats = new int[chairs];
                for (int i = 0; i < chairs; i++) {
                    newSeats[i] = -1;
                }

                // simulate multiplication rotations
                for (int i = 0; i < chairs; i++) {
                    if (occupiedSeats[i] != -1) {
                        int newSeat = (i * x) % chairs;
                        cout << newSeat << " ";
                        if (newSeats[newSeat] == -1) {
                            newSeats[newSeat] = occupiedSeats[i];
                        } else {
                            int dist = (newSeat - newSeats[newSeat]) % chairs;
                            if (dist > (newSeat - occupiedSeats[i]) % chairs) {
                                newSeats[newSeat] = occupiedSeats[i];
                            }
                        }
                    }
                }
                cout << endl;

                occupiedSeats = newSeats;
                delete[] newSeats;

                for (int i = 0; i < chairs; i++) {
                    cout << occupiedSeats[i] << ", ";
                }
                cout << endl;

                totalRotation = 0;
                totalMultiplication = 1;
                peopleLeft /= collisions;
            } else {
                totalRotation *= x;
                totalMultiplication *= x;
            }
        }
        cout << totalRotation << ", " << totalMultiplication << endl;
    }

    delete[] occupiedSeats;

    return 0;
}