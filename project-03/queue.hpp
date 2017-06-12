#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <string>
using namespace std;


class Queue {
public:
    Queue();
    ~Queue();
    // Queue(const Queue&) = delete;
    // Queue& operator=(const Queue&) = delete;

    void push(const string& new_desc);
    bool remove(const string& desc);
    bool pop(string& removed_desc);
    bool is_empty() const;
    void clear();
    int size() const;
    string nth_desc(int n) const;
    void print(int start_count) const;
    // Chore* get_first();
    // Chore* get_last();

private:
    struct Chore {
        string description;
        Chore* next;
    };
    Chore* first_;
    Chore* last_;
};

/*struct Urgency {
    Queue* q;
    Urgency* next;
};*/

#endif // QUEUE_HPP
