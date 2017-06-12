// Jingyi Bai
// 267936
// baij@student.tut.fi

// Implement all functions defined in class Queue.

#include "queue.hpp"

Queue::Queue(): first_{nullptr}, last_{nullptr} {
}

Queue::~Queue() {
    clear();
}

// Delete all Chores
void Queue::clear() {
    while (first_ != nullptr) {
        Chore* remove = first_;
        first_ = first_->next;

        delete remove;
    }
}

// Add a new Chore into Queue
void Queue::push(const string& new_desc) {
    Chore *new_chore = new Chore;

    new_chore->description = new_desc;
    new_chore->next = nullptr;

    if (first_ == nullptr) {
        first_ = new_chore;
        last_ = new_chore;
    } else {
        last_->next = new_chore;
        last_ = new_chore;
    }
}

// Remove the topmost Chore whose description is desc
bool Queue::remove(const string& desc) {
    if (is_empty() || desc == "") return false;
    else if (first_->description == desc) {
        string tmp;
        return pop(tmp);
    }

    Chore* previous_ptr = first_;
    while (true) {
        if (previous_ptr == last_) return false;
        else if (previous_ptr->next->description == desc) break;
        else previous_ptr = previous_ptr->next;
    }

    Chore* delete_ptr = previous_ptr->next;
    previous_ptr->next = delete_ptr->next;
    if (last_->description == desc) last_ = previous_ptr;

    delete delete_ptr;
    return true;

    /*
    if (first_->description == desc) return pop(desc);
    else {
        Chore *ptr = first_;
        while (ptr != last_)
            if (ptr->next->description == desc) {
                Chore *remove_ptr = ptr->next;
                ptr->next = remove_ptr->next;
                delete remove_ptr;
                return true;
            } else ptr = ptr->next;
        return false;
    }*/
}

// Remove the topmost Chore
bool Queue::pop(string& removed_desc) {
   if (is_empty()) return false;

   Chore *remove_ptr = first_;
   removed_desc = remove_ptr->description;

   if (first_ == last_) {
      first_ = nullptr;
      last_ = nullptr;
   } else first_ = first_->next;

   delete remove_ptr;
   return true;
}

// Return true if no Chores in the Queue
bool Queue::is_empty() const {
    return first_ == nullptr;
}

// Return the number of all Chores
int Queue::size() const {
    if (is_empty()) return 0;
    else {
        int count = 1;
        Chore *curr = first_;
        while (curr != last_) {
            ++count;
            curr = curr->next;
        }
        return count;
    }
}

// Return the nth Chore's description
string Queue::nth_desc(int n) const {
    if (first_ == last_) {
        return first_->description;
    }
    else {
        Chore *curr = first_;
        while (n > 1 && curr != last_->next) {
            --n;
            curr = curr->next;
        }
        return curr->description;
    }
}

// Print all Chores in Queue one by one
void Queue::print(int count) const {
    Chore *curr = first_;
    while (curr != last_->next) {
        cout << "  " << count << ". " << curr->description << endl;
        ++count;
        curr = curr->next;
    }
}

/*
Chore* Queue::get_first() {
    return first_;
}

Chore* Queue::get_last() {
    return last_;
}
*/


