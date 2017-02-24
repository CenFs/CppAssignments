#include <iostream>
#include <string>

using namespace std;


// There is an unexpected problem when a program reads input
// using "cin >> ..." followed later by "getline(cin, ...)".
// The problem arises from the fact that "cin >>" only reads
// input as far as it needs: it leaves the enter/return/newline
// character unread.  When getline later tries to read a line
// of text its requirements are immediatelly satisfied by the
// leftover newline in the input.


int main() {
    int studentid;
    string name;


    //--------------------------------------------------------------
    // Solution 1:
    // Probably the most realiable way to handle the problem
    // is to read numbers as strings using getline and then convert
    // them to actual numerical values using stoi or stod library
    // functions:

    cout << "Student id: ";
    string studentid_as_string;
    getline(cin, studentid_as_string);
    studentid = stoi(studentid_as_string);

    cout << "Name: ";
    getline(cin, name);

    cout << "Hello " << name << " " << studentid << " Welcome" << endl;


    //--------------------------------------------------------------
    // Solution 2:
    // If one wants to read numbers with "cin >>" some steps has to
    // be taken to remove the extra newline from input before the
    // getline(cin, ...) call later in the program.  The following
    // introduces three different approaches to achieve this:

    cout << "Student id: ";
    cin >> studentid;

    cout << "Name: ";

    cin.ignore();  // solution 1: Ignore the next input character.
    // cin.get();  // solution 2: Read one character, don't store it anywere.
    // cin >> ws;  // solution 3: Ignore all whitespapce characters.

    getline(cin, name);

    cout << "Hello " << name << " " << studentid << " Welcome" << endl;
}
