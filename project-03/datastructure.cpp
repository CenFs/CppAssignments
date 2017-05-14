#include <datastructure.hpp>

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
    /*while (head_ != nullptr) {
        Urgency* remove = head_;
        head_ = head_->next;
        remove->q->clear();
        delete remove;
    }*/
}

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

void Datastructrue::add(int priority_level, const string desc) {
    if (priority_level <= 0 || priority_level > total_priority_levels_)
        cout << "Error: priority level must be an integer between 1-" << total_priority_levels_ << "." << endl;
    else {
        q_[priority_level-1].push(desc);
        ++total_chores_;
        cout << "New chore added to priority level " << priority_level << "." << endl;
    }
}

void Datastructrue::print() {
    int count = 1;
    int curr_priority_level = total_priority_levels_;
    while (curr_priority_level > 0) {
        if (!q_[curr_priority_level-1].is_empty()) {
            cout << "Priority level " << curr_priority_level << ":" << endl;
            Chore* curr = q_[curr_priority_level-1].get_first();
            Chore* last = q_[curr_priority_level-1].get_last();
            if (curr == last) {
                cout << "  " << count << "." << curr->description << endl;
                ++count;
            } else {
                while (curr != last->next) {
                    cout << "  " << count << "." << curr->description << endl;
                    curr = curr->next;
                    ++count;
                }
            }
        }
        --curr_priority_level;
    }
}

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
                Chore* curr = q_[curr_priority_level-1].get_first();
                Chore* last = q_[curr_priority_level-1].get_last();
                if (curr == last) {
                    --count;
                    desc = curr->description;
                } else {
                    while (count > 0 && curr != last->next) {
                        --count;
                        desc = curr->description;
                        curr = curr->next;
                    }
                }
            }
            --curr_priority_level;
        }
        q_[curr_priority_level].remove(desc);
        --total_chores_;
    }
}

int Datastructrue::size() const {
    return total_priority_levels_;
}
