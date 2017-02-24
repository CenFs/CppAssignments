#include <iostream>
#include <map>
#include <string>
using namespace std;

int count_names(const map<string, string>& phonebook, char initial_letter) {
    int count = 0;
    map<string, string>::const_iterator iter = phonebook.begin();
    while ( iter != phonebook.end() ) {
        if ( iter->first.at(0) == initial_letter ) {
            ++count;
        }
        ++iter;
    }
    return count;
}

int count_names_recursive(const map<string, string>& phonebook, map<string, string>::const_iterator iter, char initial_letter) {
    int count = 0;
    if ( iter != phonebook.end() ) {
        count = count_names_recursive(phonebook, ++iter, initial_letter);
        --iter;
        if ( iter->first.at(0) == initial_letter ) {
            ++count;
        }
    }
    return count;
}

int main() {
    map<string, string> phonebook;
    phonebook["aaa"] = "123456";
    phonebook["bbb"] = "234567";
    phonebook["ccc"] = "345678";
    phonebook["ddd"] = "456789";
    phonebook["bbd"] = "234567";
    phonebook["eee"] = "567891";
    phonebook["fff"] = "678912";
    phonebook["ggg"] = "789123";
    phonebook["hhh"] = "891234";
    phonebook["iii"] = "912345";
    phonebook["bbc"] = "234567";
    char initial_letter = 'b';
    // int count = count_names(phonebook, initial_letter); // 3
    int count = count_names_recursive(phonebook, phonebook.begin(), initial_letter); // 3
    cout << count << endl;
    return 0;
}
