// Jingyi Bai
// 267936
// baij@student.tut.fi

// Implement all functions defined in class Datastructrue.

#include "datastructure.hpp"

Datastructrue::Datastructrue(): total_priority_levels_{0}, total_chores_{0} {
}

Datastructrue::~Datastructrue() {
    clear();
}

void Datastructrue::clear() {
    if (total_priority_levels_ > 0) {
        for (int i = 0; i < total_priority_levels_; i++) q_[i].clear();
        total_priority_levels_ = 0;
    }
    delete [] q_;
    total_chores_ = 0;
    total_priority_levels_ = 0;
    q_ = nullptr;
    /*while (head_ != nullptr) {
        Urgency* remove = head_;
        head_ = head_->next;
        remove->q->clear();
        delete remove;
    }*/
}

// A new priority list is created
// If there was an earlier list, it is destroyed and a new one is initialized from scratch
void Datastructrue::init(int number_of_priority_levels) {
    if (number_of_priority_levels <= 0) {
        cout << "Error: it is not possible to create a priority list with 0 or less levels." << endl;
    } else {
        if (total_priority_levels_ > 0) clear();
        else total_chores_ = 0;
        q_ = new Queue[number_of_priority_levels];
        total_priority_levels_ = number_of_priority_levels;
        if (total_priority_levels_ == 1)
            cout << "New priority list with level 1 initialized." << endl;
        else
            cout << "New priority list with levels 1-" << total_priority_levels_ << " initialized." << endl;
    }
}

// A new chore will be added to the end of the priority_level's tasks
void Datastructrue::add(int priority_level, const string desc) {
    if (priority_level <= 0 || priority_level > total_priority_levels_)
        cout << "Error: priority level must be an integer between 1-" << total_priority_levels_ << "." << endl;
    else {
        q_[priority_level-1].push(desc);
        ++total_chores_;
        cout << "New chore added to priority level " << priority_level << "." << endl;
    }
}

// Prints out the current state of the chore list
void Datastructrue::print() {
    int count = 1;
    int curr_priority_level = total_priority_levels_;
    while (curr_priority_level > 0) {
        if (!q_[curr_priority_level-1].is_empty()) {
            cout << "Priority level " << curr_priority_level << ":" << endl;
            q_[curr_priority_level-1].print(count);
            count += q_[curr_priority_level-1].size();
        }
        --curr_priority_level;
    }
}

// Prints the chore that the next in turn
void Datastructrue::next() {
    if (total_chores_ == 0)
        cout << "--- no chores left ---" << endl;
    else {
        int curr_priority_level = total_priority_levels_;
        while (curr_priority_level > 0 && q_[curr_priority_level-1].is_empty())
            --curr_priority_level;
        string desc = "";
        if (q_[curr_priority_level-1].pop(desc)) {
            --total_chores_;
            cout << desc << endl;
        }
    }
}

// Removes the chore whose running number is running_number from the chore list
void Datastructrue::erase(int running_number) {
    if (running_number == 0)
        cout << "Error: the running number must be larger than 0." << endl;
    else if (running_number > total_chores_)
        cout << "Error: there is no such chore." << endl;
    else {
        int count = running_number;
        int curr_priority_level = total_priority_levels_;
        string desc = "";

        while (count > 0 && curr_priority_level > 0) {
            if (!q_[curr_priority_level-1].is_empty()) {
                int size = q_[curr_priority_level-1].size();
                if (count <= size) desc = q_[curr_priority_level-1].nth_desc(count);
                count -= size;
            }
            --curr_priority_level;
        }
        // cerr << desc << endl;
        q_[curr_priority_level].remove(desc);
        --total_chores_;
    }
}

// Number of Chore_list
int Datastructrue::size() const {
    return total_priority_levels_;
}
