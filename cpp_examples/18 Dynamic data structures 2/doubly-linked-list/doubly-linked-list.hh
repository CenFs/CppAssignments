#ifndef DOUBLY_LINKED_LIST_HH
#define DOUBLY_LINKED_LIST_HH

#include <memory>

using namespace std;

class DoublyLinkedList {
  public:
    DoublyLinkedList();
    int size() const;
    bool exists(int value) const;
    void print() const;
    void print_reverse() const;
    bool remove(int value);
    bool add_ascending(int value);
    // No destructor(!)

  private:
    struct Cell {
        int               data;
        shared_ptr<Cell>  next_ptr;
        Cell             *prev_ptr;
    };

    shared_ptr<Cell> first_ptr_;
    Cell            *last_ptr_;
    int              element_count_;
};

#endif
