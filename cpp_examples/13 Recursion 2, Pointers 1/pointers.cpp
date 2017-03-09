#include <iostream>

using namespace std;

// Simple example of using a pointer.

int main() {
    int i;
    i = 5;

    // Let's create a pointer variable that can store int variable's
    // location in the memory.  nullptr is a good initialization value
    // as it doesn't point anywhere.
    int* ip = nullptr;

    // This would crash as nullptr doesn't point anywhere.
    // cout << *ip << endl;

    ip = &i;  // Let's store i's location in the memory into ip

    cout << *ip << endl;  // Outputs 5

    *ip = 9;
    cout << i << endl;    // Outputs 9

    // Where is the variable i located in the memory?
    cout << ip << endl;

    // Where is the pointer variable ip itself located in the memory?
    cout << &ip << endl;

    // If we need to manipulate doubles using pointers, the type
    // of the pointer variable has to be double*
    double d = 5.0;
    double* dp = nullptr;
    dp = &d;

    cout << *dp << " " << dp << endl;
}
