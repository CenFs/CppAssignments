#ifndef STUDENT_HH
#define STUDENT_HH

#include <string>

using namespace std;


// This class is not doing anything useful.  It is merely
// an example of how a class can be turned into a module:
// class definition will be located in .hh-file and
// the member function definitions in the .cpp-file.


const int UNKNOWN_STUDENT_ID = 0;

class Student {
  public:
    Student();
    void set_name_and_id(const string& nimi, int opiskelijanumero);
    void print() const;

  private:
    string name_;
    int    id_;
};

#endif
