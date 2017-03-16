#include <iostream>

using namespace std;


void f_recursive(int i, int repeats) {
    if ( i > repeats ) {
        return;

    } else {

        cout << i << endl;
        f_recursive(i + 1, repeats);
    }
}


int main() {
    int repeats;
    int i;


    repeats = 5;
    i = 0;

    while ( i < repeats + 1 ) {
        cout << i << endl;
        i = i + 1;
    }

    cout << "--------------------------" << endl;

    f_recursive(0, repeats);
}
