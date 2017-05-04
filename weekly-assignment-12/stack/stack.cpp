#include "stack.hh"
#include <iostream>

using namespace std;


const unsigned int INITIAL_SIZE = 5;


Stack::Stack(): array_(new int[INITIAL_SIZE]),
              max_size_(INITIAL_SIZE),
              current_size_(0) {
}


bool Stack::empty() const {
    return current_size_ == 0;
}


Stack::~Stack() {
    delete[] array_;

    current_size_ = 0;
    max_size_ = 0;
    array_ = nullptr;
}


void Stack::push_front(int value) {
    // There is already enough room in the
    // array_ to insert a new element.
    if (max_size_ > current_size_) {
        array_[current_size_] = value;
        ++current_size_;

        return;  // Not needed, but just clarify things

    // array_ is too small have to allocatge a new array
    } else {

        int* new_array;
        int  new_max_size;

        // The new array_ will be twice as big
        // as the old one.
        new_max_size = 2 * max_size_;
        new_array = new int[new_max_size];

        // All the elements from the old array are
        // copied to the new one.
        for (int i = 0; i < current_size_; ++i) {
            new_array[i] = array_[i];
        }

        // The old array is deleted.
        delete[] array_;

        // The member variables are updated to
        // match the newly reserved larger array.
        array_ = new_array;
        max_size_ = new_max_size;

        // Sneaky trick: recursive push_front will
        // absolutely succeed since the code above
        // make ssure there is room in the array.
        push_front(value);

        return;  // Not needed, but just clarify things
    }
}


bool Stack::pop_front(int& removed_value) {
    if (current_size_ == 0) {
        return false;
    }

    --current_size_;

    removed_value = array_[current_size_];

    // Notice: the memory is not freed here.
    return true;
}


void Stack::print() const {
    cout << "[";

    int index = 0;
    while ( index < current_size_ ) {
        cout << array_[index];

        if ( index < current_size_ - 1 ) {
            cout << "|";
        }

        ++index;
    }

    cout << "]" << endl;
}


#ifdef STACK_TEST

int main() {
    Stack p;
    p.print();

    for ( int number : { 1, 2, 3, 4, 5, 6, 7, 8, 9 } ) {
        p.push_front(number);

        cout << "pushed:   " << number << ": ";
        p.print();
    }

    while ( not p.empty() ) {
        int number;
        p.pop_front(number);

        cout << "popped: " << number << ": ";
        p.print();
    }
}

#endif
