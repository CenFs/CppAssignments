#include <iostream>

using namespace std;


// Returns n th fibonacci number:
//          n:   0 1 2 3 4 5  6  7  8 ...
//     fib(n):   1 1 2 3 5 8 13 21 34 ...
// Can you see how there is a serious problem
// with this function? Try using it to calculate
// 30th fibonacci number.  How about 50th?
unsigned int fib(unsigned int n) {
    if ( n < 2 ) {
        return 1;
    } else {
        return fib(n - 2) + fib(n - 1);
    }
}


int main() {
    unsigned int n;
    cout << "n: ";
    cin >> n;

    cout << fib(n) << endl;
}
