#include <iostream>

using namespace std;


// The return value type is se to unsigned long int
// to avoid overflow for little longer.  Not that it makes
// much difference: factorial(21) will already be wrong.
// This problem has nothing to do with recursion, it
// is a result of the nature of number types in C++ and
// many other languages.
unsigned long int factorial(unsigned int n) {
    if ( n == 0 ) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}


int main() {
    for ( int n : { 0, 1, 2, 3, 4, 5, 18, 19, 20, 21 } ){
        cout << factorial(n) << endl;
    }
}
