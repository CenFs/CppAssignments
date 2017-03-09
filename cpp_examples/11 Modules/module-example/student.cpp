#include "student.hh"
#include <iostream>
#include <string>

using namespace std;


// This class is not doing anything useful.  It is merely
// an example of how a class can be turned into a module:
// class definition will be located in .hh-file and
// the member function definitions in the .cpp-file.


Student::Student(): name_(""), id_(UNKNOWN_STUDENT_ID) {
}

void Student::set_name_and_id(const string& nimi, int opiskelijanumero) {
}

void Student::print() const {
    cout << "Hi!" << endl;
}
