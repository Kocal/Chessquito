#include "Util.h"

int* coordonnees(string n) {
    int *p = new int[2];

    p[0] = n[0] - 'a'; // a => 0, b => 1 ...
    p[1] = n[1] - '1'; // 1 => 0, 2 => 1 ...

    return p;

}

void separation(void) {
    cout << "----------------------------" << endl;
}
