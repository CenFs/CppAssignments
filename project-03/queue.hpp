#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <string>
using namespace std;

struct Chore {
    string description;
    Chore* next;
};

class Queue {
public:
    Queue();
    ~Queue();

    void push(const string& new_desc);
    bool remove(const string desc);
    bool pop(string& removed_desc);
    bool is_empty() const;
    void clear();
    int size() const;
    Chore* get_first();
    Chore* get_last();

private:
    Chore* first_;
    Chore* last_;
};

/*struct Urgency {
    Queue* q;
    Urgency* next;
};*/

#endif // QUEUE_HPP
