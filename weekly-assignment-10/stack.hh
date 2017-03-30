#ifndef STACK_HH
#define STACK_HH

class Stack {
      public:
        Stack();
        ~Stack();

        // empty will only return true, if there are no elements
        // in the stack i.e. the linked  list is empty.
        bool empty() const;

        // push_front will insert the new_value on top of the stack
        // i.e. in front of the linked list.
        void push_front(int new_value);


        // pop_front will remove the topmost value from the stack
        // i.e. the first element of the linked list.  The removed
        // value will be stored into removed_value and the return
        // value will be true if the removal of an element is successfull.
        // If not (i.e. the stack is empty), return value is false.
        bool pop_front(int& removed_value);

        // Print the elements stored in the stack on top to bottom
        // order.  This method is mainly for testing purposes.
        void print() const;
        void reverse();

      private:
        struct Cell {
            int data;
            Cell* next_ptr;
        };

        Cell* first_ptr;
    };

#endif // STACK_HH
