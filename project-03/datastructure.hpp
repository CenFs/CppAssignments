#ifndef DATASTRUCTURE_HPP
#define DATASTRUCTURE_HPP

#include <queue.hpp>
#include <iostream>
#include <string>
using namespace std;

class Datastructrue {
public:
    Datastructrue();
    ~Datastructrue();

    // A new priority list is created.
    void init(int number_of_priority_levels);

    // A new chore will be added to the end of the priority_level's tasks.
    void add(int priority_level, const string desc);

    // Prints out the current state of the chore list.
    void print();

    // Prints the chore that the next in turn.
    void next();

    // Removes the chore whose running number is running_number from the chore list.
    void erase(int running_number);

    // Number of Chore_list
    int size() const;

    void clear();

private:
    int total_priority_levels_;
    int total_chores_;
    // Urgency* head_;
    Queue* q_;
};

#endif // DATASTRUCTURE_HPP
