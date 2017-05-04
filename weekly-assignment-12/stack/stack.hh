#ifndef STACK_HH
#define STACK_HH

class Stack {
  public:
    Stack();
   ~Stack();

    bool empty() const;
    void push_front(int value);
    bool pop_front(int& removed_value);

    void print() const;

  private:
    int* array_;
    int  max_size_;
    int  current_size_;
};

#endif // STACK_HH
