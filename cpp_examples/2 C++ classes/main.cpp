#include <iostream>
#include <string>

using namespace std;

class Student {
  public:
    // Overloaded constructors:
    // overload: there are multiple functions with same name but there is
    //           a difference between parameters.
    // constructor: a class method which C++ uses to automatically
    //              initialize objects (i.e. variables).
    // initialize: means same as setting the initial value at the point
    //             in program where a variable is defined.
    Student();
    Student(string name, int id);

    // const: makes a promise that the print method *will not modify*
    // name_ and id_ member variables (the variables in the private section).
    void print() const;

    // The following member functions are missing the const qualifier
    // since they clearly do modify name_ and/or id_.
    void store_name_and_id(string name, int id);
    void get_married(string new_last_name);

  private:
    string name_;
    int id_;
};


Student::Student(): name_("unknown student"), id_(-1) {
}


Student::Student(string name, int id): name_(name), id_(id) {
}


void Student::print() const {
    cout << name_ << " " << id_ << endl;
}


void Student::store_name_and_id(string name, int id) {
    name_ = name;
    id_ = id;
}


void Student::get_married(string new_last_name) {
    name_ = new_last_name;
}


int main() {
    // Default costructor Student::Student() is used for initialization.
    Student x;

    x.print();

    x.store_name_and_id("Pendelton K.", 72226);

    x.print();

    // Student::Student(string name, int id) is used for initialization.
    Student y("Derrick L.", 234567);

    y.print();
}
