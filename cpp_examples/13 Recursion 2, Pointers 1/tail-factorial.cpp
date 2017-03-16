#include <iostream>

using namespace std;

// Tail recursive version of factorial.

unsigned long int tailfactorial(unsigned int n, unsigned long int result) {
    if ( n == 0 ) {
        return result;
    } else {
        // This function is tail recursive because the last thing
        // it does is the recursive call.
        return tailfactorial(n - 1, result * n);
    }

    // Notice similarity with a looo construct
    // unsigned long int result = 1;
    // while ( n > 0 ) {
    //     result = result * n;
    //     n = n - 1;
    // }
    // return result;
}


int main() {
    for ( int n : { 0, 1, 2, 3, 4, 5 } ){
        cout << tailfactorial(n, 1) << endl;
    }
}
