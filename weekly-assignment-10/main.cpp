#include <iostream>
#include "stack.hh"
using namespace std;

int main() {
    Stack test_stack;
    for (int i = 0; i < 5; i++) {
        test_stack.push_front(i);
    }

    cout << "Pushed numbers from 0 to 4:" << endl;
    test_stack.print();

    int to_pop = 0;

    if (test_stack.pop_front(to_pop)) {
        cout << "Item popped: " << to_pop << endl;
        cout << "Items left in the stack:" << endl;
        test_stack.print();
    }

    test_stack.reverse();

    cout << "Reversed:" << endl;
    test_stack.print();
}
