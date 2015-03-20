#include "Util.h"

int* coordonnees(string n) {
    int *p = new int[2];

    p[0] = n[0] + 1 - 'a';
    p[1] = n[1] - '0';

    return p;

}

void separation(void) {
    cout << "----------------------------" << endl;
}
