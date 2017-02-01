#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
using namespace std;

const unsigned int SPLIT_ERROR = 0;

class Splitter {
public:
    Splitter(const string& string_to_split = "");
    void set_string_to_split(const string& string_to_split);
    unsigned int split(char separator, bool ignore_empty = false);
    unsigned int number_of_fields() const;
    string fetch_field(unsigned int field_index) const;

private:
    string string_to_split_ = "";
    vector<string> str_vector_;
};



Splitter::Splitter(const string& string_to_split) {
    string_to_split_ = string_to_split;
    str_vector_.clear();
}

void Splitter::set_string_to_split(const string& string_to_split) {
    string_to_split_ = string_to_split;
    str_vector_.clear();
}

unsigned int Splitter::split(char separator, bool ignore_empty) {
    stringstream ss(string_to_split_);
    string tok;
    while (getline(ss, tok, separator)) {
        str_vector_.push_back(tok);
    }
    if (ignore_empty) {
        for (int i = 0; i < str_vector_.size(); i++) {
            if (str_vector_[i] == "") {
                str_vector_.erase(str_vector_.begin() + i);
                i--;
            }
        }
    }
    return str_vector_.size();
}

unsigned int Splitter::number_of_fields() const {
    if (str_vector_.size()) {
        return str_vector_.size();
    }
    return SPLIT_ERROR;
}

string Splitter::fetch_field(unsigned int field_index) const {
    if (field_index >= str_vector_.size()) {
        throw out_of_range("too large index or split not called");
    }
    return str_vector_[field_index];
}





int main() {

    Splitter splitter_object("a::bc:def::hijlkm"); // Bill:Baxter:234567:CS:1997
    // cout << "fields: " << splitter_object.number_of_fields() << endl;  // 0 SPLIT_ERROR
    // cout << splitter_object.fetch_field(0) << endl;  // out_of_range exception
    splitter_object.split(':');  // Observe: single quotes: parameter is of type char.
    cout << "fields: " << splitter_object.number_of_fields() << endl;  // 6

    cout << splitter_object.fetch_field(0) << endl;  // a
    cout << splitter_object.fetch_field(4) << endl;  // (empty)
    cout << splitter_object.fetch_field(5) << endl;  // hijlkm

    for ( unsigned int i = 0; i < splitter_object.number_of_fields(); ++i ) {
        string current_field_contents = splitter_object.fetch_field(i);
        cout << i << ": [" << current_field_contents << "]" << endl;
    }

    splitter_object.set_string_to_split(" A B  C   D    E     ");
    unsigned int fields = splitter_object.split(' ', true);
    cout << "fields: " << fields << endl;  // 5

    for ( unsigned int i = 0; i < fields; ++i ) {
        string current_field_contents = splitter_object.fetch_field(i);
        cout << i << ": [" << current_field_contents << "]" << endl;
    }

    cout << splitter_object.fetch_field(5) << endl;  // out_of_range exception

    return 0;
}
