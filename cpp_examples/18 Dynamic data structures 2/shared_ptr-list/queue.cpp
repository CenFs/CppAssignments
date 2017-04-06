#include "queue.hh"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

Queue::Queue(): first_ptr_(nullptr),
                last_ptr_(nullptr) {
}

void
Queue::add_to_end(const string& new_patient_name) {
    shared_ptr<Cell> new_address(new Cell);

    new_address->patient_name = new_patient_name;
    new_address->next_ptr = nullptr;

    if ( is_empty() ) {
        first_ptr_ = new_address;
        last_ptr_ = new_address;
    } else {
        last_ptr_->next_ptr = new_address;
        last_ptr_ = new_address;
    }
}

bool
Queue::remove_from_front(string& removed_patient_name) {
    if ( is_empty() ) {
        return false;
    }

    shared_ptr<Cell> delete_ptr = first_ptr_;

    removed_patient_name = delete_ptr->patient_name;

    if ( first_ptr_ == last_ptr_ ) {
        first_ptr_ = nullptr;
        last_ptr_ = nullptr;
    } else {
        first_ptr_ = first_ptr_->next_ptr;
    }

    return true;
}

bool
Queue::is_empty() const {
    if ( first_ptr_ == nullptr ) {
        return true;
    } else {
        return false;
    }
}

void
Queue::print() const {
    shared_ptr<Cell> print_ptr = first_ptr_;
    int running_number = 1;

    while ( print_ptr != nullptr ) {
        cout << running_number << ". "
             << print_ptr->patient_name << endl;
        ++running_number;
        print_ptr = print_ptr->next_ptr;
    }
}
