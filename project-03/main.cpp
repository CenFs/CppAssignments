// Jingyi Bai
// 267936
// baij@student.tut.fi

// Implement required project functions by calling two classes.

#include "datastructure.hpp"

#include <sstream>
#include <regex>
#include <cctype>
using namespace std;



const string COMMAND = "([[:w:]]*)";
// const string NUMBER = "([[:digit:]]*)"; ^(-?\\d+)(\\.\\d+)?$
const string FLOAT = "(([[:digit:]]+.[[:digit:]]+)*)";
const string STRING = "(([[:w:]]+[[:space:]]?([[:digit:]]+.[[:digit:]]+)*[[:space:]]?)*)";
const string ZERO_OR_MORE_SPACES = "[[:space:]]*";

// If s is string of numbers, return true
// Else, return false
bool isnum(string s) {
    stringstream sin(s);
    double t;
    char p;
    if(!(sin >> t) || sin >> p) return false;
    else return true;
}

int main() {
    Datastructrue data;
    regex reg(ZERO_OR_MORE_SPACES
              + COMMAND
              + "[[:space:]]?"
              + COMMAND
              + "[[:space:]]?"
              + STRING
              + ZERO_OR_MORE_SPACES
    );
    smatch result;
    string line;
    string command = "quit";

    // Loop and get the command until get "quit"
    while (cout << "chores> " and getline(cin, line)) {
        if (regex_match(line, result, reg)) {

            if (result.size() > 0) command = result.str(1);

            // If command is "quit", clear all and end the program
            if (command == "quit") {
                data.clear();
                return 0;
            }


            // If command is "init" and the number of priority levels > 0, a new priority list is created
            else if (command == "init") {
                if (result.str(2) == "")
                    cout << "Error: the number of priority levels is missing." << endl;
                else if (!isnum(result.str(2)))
                    cout << "Error: the number of priority levels must be an integer larger than 0." << endl;
                else
                    data.init(stoi(result.str(2)));
            }


            // If command is "add" and priority level is correct, a new chore will be added to the end of the priority_level's tasks
            else if (command == "add") {
                if (result.str(2) == "")
                    cout << "Error: priority level and chore description are missing." << endl;
                else if (!isnum(result.str(2)))
                    cout << "Error: priority level must be an integer between 1-" << data.size() << "." << endl;
                else if (result.str(3) == "")
                    cout << "Error: chore description is missing." << endl;
                else
                    data.add(stoi(result.str(2)), result.str(3));
            }


            // If command is "print", prints out the current state of the chore list
            else if (command == "print") {
                if (result.str(2) == "") data.print();
                else cout << "Error: extra text after print command." << endl;
            }


            // If command is "next", prints the chore that the next in turn
            else if (command == "next") {
                if (result.str(2) == "") data.next();
                else cout << "Error: extra text after next command." << endl;
            }



            // If command is "erase" and running number is correct, removes the chore whose running number is running_number from the chore list
            else if (command == "erase") {
                if (result.str(2) == "")
                    cout << "Error: the running number is missing." << endl;
                else if (!isnum(result.str(2)))
                    cout << "Error: the running number must be an integer." << endl;
                else
                    data.erase(stoi(result.str(2)));
            }

        } else cerr << "REGEX NOT MATCHING" << endl;

    }


}
