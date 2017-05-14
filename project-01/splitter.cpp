#include "splitter.hpp"

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
