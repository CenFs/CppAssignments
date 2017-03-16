#include "inputmanager.hh"
#include "student.hh"
#include <iostream>
#include <string>

using namespace std;

int main() {
    string name = ask_name("Please input your name: ");
    int student_id = ask_number("Please input your student id: ");

    cout << "Welcome to the class " << name
         << " (" << student_id << ")" << endl;

    Student student;
    student.set_name_and_id(name, student_id);
    student.print();
}
