#include "Util.h"

void coordonnees(string n, int &x, int &y) {
    x = n[0] - 'a'; // a => 0, b => 1 ...
    y = n[1] - '1'; // 1 => 0, 2 => 1 ...
}

void separation(void) {
    cout << "----------------------------" << endl;
}
