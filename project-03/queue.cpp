#include <queue.hpp>


Queue::Queue(): first_{nullptr}, last_{nullptr} {
}

Queue::~Queue() {
    clear();
}

void Queue::clear() {
    while (first_ != nullptr) {
        Chore* remove = first_;
        first_ = first_->next;

        delete remove;
    }
}

void Queue::push(const string& new_desc) {
    Chore* new_chore = new Chore;

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

bool Queue::remove(const string desc) {
    if (is_empty() || desc == "") return false;

    Chore *ptr = first_;
    if (ptr->description == desc) {
        if (first_ == last_) {
            first_ = nullptr;
            last_ = nullptr;
        } else first_ = first_->next;
        return true;
    } else {
        while (ptr->next != nullptr)
            if (ptr->next->description == desc) {
                ptr->next = ptr->next->next;
                return true;
            } else ptr = ptr->next;
        return false;
    }
}

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

bool Queue::is_empty() const {
    return first_ == nullptr;
}

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

Chore* Queue::get_first() {
    return first_;
}

Chore* Queue::get_last() {
    return last_;
}




