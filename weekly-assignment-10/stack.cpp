#include "stack.hh"
#include <iostream>
using namespace std;

Stack::Stack(): first_ptr{nullptr} {
}

Stack::~Stack() {
    while (!empty()) {
       Cell* remove = first_ptr;
       first_ptr = first_ptr->next_ptr;

       delete remove;
    }
}

bool Stack::empty() const {
    return first_ptr == nullptr;
}

void Stack::push_front(int new_value) {
    Cell* cnew = new Cell;
    cnew->data = new_value;
    cnew->next_ptr = first_ptr;
    first_ptr = cnew;
}

bool Stack::pop_front(int& removed_value) {
    if (empty()) return false;
    Cell* cpop = first_ptr;
    removed_value = cpop->data;
    first_ptr = cpop->next_ptr;
    delete cpop;
    return true;
}

void Stack::print() const {
   Cell* print = first_ptr;
   while (print != nullptr) {
      cout << print->data << endl;
      print = print->next_ptr;
   }
   cout << endl;
}

void Stack::reverse() {
    Cell* reverse_first = nullptr;

    while (!empty()) {
        Cell* move = first_ptr;
        first_ptr = first_ptr->next_ptr;
        move->next_ptr = reverse_first;
        reverse_first = move;
    }

    first_ptr = reverse_first;
}
