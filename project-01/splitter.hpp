#ifndef SPLITTER_HPP
#define SPLITTER_HPP

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


#endif // SPLITTER_HPP
