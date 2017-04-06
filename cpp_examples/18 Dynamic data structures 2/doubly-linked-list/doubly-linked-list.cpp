#include "doubly-linked-list.hh"
#include <iostream>
#include <memory>

using namespace std;

DoublyLinkedList::DoublyLinkedList():
    first_ptr_(nullptr),
    last_ptr_(nullptr),
    element_count_(0) {
}

int
DoublyLinkedList::size() const {
    return element_count_;
}

bool
DoublyLinkedList::exists(int value) const {
    shared_ptr<Cell> current_ptr = first_ptr_;

    while ( current_ptr != nullptr ) {
        if ( current_ptr->data == value ) {
            return true;
        } else if ( current_ptr->data > value ) {
            return false;
        }

        current_ptr = current_ptr->next_ptr;
    }

    return false;
}

void
DoublyLinkedList::print() const {
    shared_ptr<Cell> print_ptr = first_ptr_;

    cout << "List size: " << size() << endl;

    while ( print_ptr != nullptr ) {
        cout << print_ptr->data << " ";

        print_ptr = print_ptr->next_ptr;
    }

    cout << endl;
}


void
DoublyLinkedList::print_reverse() const {
    Cell *print_ptr = last_ptr_;

    cout << "List size: " << size() << endl;

    while ( print_ptr != nullptr ) {
        cout << print_ptr->data << " ";

        print_ptr = print_ptr->prev_ptr;
    }

    cout << endl;
}


bool
DoublyLinkedList::remove(int value) {
   if ( size() == 0 ) {
       return false;
   }

   shared_ptr<Cell>
       delete_ptr{ first_ptr_ };

   while ( true ) {
      if ( delete_ptr->data == value ) {
         break;         // value to be removed was found

      } else if ( delete_ptr->data > value ) {
         return false;  // Value is not in the list

      } else if ( delete_ptr->next_ptr == nullptr ) {
         return false;  // Value is not in the list

      } else {
         delete_ptr = delete_ptr->next_ptr;
      }
   }

   // Here we know that value we want to remove exists
   // in the list and delete_ptr points to it.

   // We are removing the only element in the list.
   if ( first_ptr_.get() == last_ptr_ ) {

      first_ptr_ = nullptr;
      last_ptr_ = nullptr;

   // We are removing the first element of the list.
   } else if ( delete_ptr == first_ptr_ ) {

      first_ptr_ = first_ptr_->next_ptr;
      first_ptr_->prev_ptr = nullptr;

   // We are removing the last element of the list.
   } else if ( delete_ptr.get()
                 == last_ptr_ ) {

      last_ptr_ = last_ptr_->prev_ptr;
      last_ptr_->next_ptr = nullptr;

   // We are removing an element inside the list.
   } else {

      delete_ptr->prev_ptr->next_ptr = delete_ptr->next_ptr;
      delete_ptr->next_ptr->prev_ptr = delete_ptr->prev_ptr;
   }

   --element_count_;

   return true;
}


bool
DoublyLinkedList::add_ascending(int value) {
   shared_ptr<Cell> new_ptr( new Cell );

   new_ptr->data = value;

   // Adding to an empty list.
   if ( size() == 0 ) {

      new_ptr->next_ptr = nullptr;
      new_ptr->prev_ptr = nullptr;

      first_ptr_ = new_ptr;
      last_ptr_ = new_ptr.get();

   // Adding to the beginning of the list.
   } else if ( value < first_ptr_->data ) {

      new_ptr->next_ptr = first_ptr_;
      new_ptr->prev_ptr = nullptr;

      first_ptr_->prev_ptr = new_ptr.get();
      first_ptr_ = new_ptr;

   // Adding to the end of the list.
   } else if ( value > last_ptr_->data ) {

      new_ptr->next_ptr = nullptr;
      new_ptr->prev_ptr = last_ptr_;

      last_ptr_->next_ptr = new_ptr;
      last_ptr_ = new_ptr.get();

   // Adding in the middle of the list.
   } else {
      shared_ptr<Cell> current_ptr = first_ptr_;

      // This loop will search the element of the list that has
      // value grater or equal than the value we are trying to add.
      while ( current_ptr->data < value ) {
          current_ptr = current_ptr->next_ptr;
      }

      // Value is only allowed to be in list once.
      if ( current_ptr->data == value ) {
          return false;
      }

      // At this point we can be cartain that current_ptr
      // contains the address of the element that will be
      // the follower of the newly added element.

      new_ptr->next_ptr = current_ptr;
      new_ptr->prev_ptr = current_ptr->prev_ptr;

      new_ptr->prev_ptr->next_ptr = new_ptr;
      new_ptr->next_ptr->prev_ptr = new_ptr.get();
   }

   ++element_count_;

   return true;
}


// #ifdef DOUBLY_LINKED_TEST

int main() {
    DoublyLinkedList testlist;

    testlist.print();
    testlist.add_ascending(5);  testlist.print();
    testlist.add_ascending(2);  testlist.print();
    testlist.add_ascending(8);  testlist.print();
    testlist.add_ascending(0);  testlist.print();
    testlist.add_ascending(10); testlist.print();

    testlist.add_ascending(10); testlist.print();
    testlist.add_ascending(0);  testlist.print();

    testlist.add_ascending(4);  testlist.print();
    testlist.add_ascending(6);  testlist.print();
    testlist.add_ascending(1);  testlist.print();
    testlist.add_ascending(9);  testlist.print();
    testlist.add_ascending(1);  testlist.print();
    testlist.add_ascending(9);  testlist.print();

    testlist.print_reverse();

    testlist.remove(1);  testlist.print();
    testlist.remove(9);  testlist.print();
    testlist.remove(0);  testlist.print();
    testlist.remove(10); testlist.print();
    testlist.remove(5);  testlist.print();
}

// #endif
