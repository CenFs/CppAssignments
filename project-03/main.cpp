// Jingyi Bai
// 267936
// baij@student.tut.fi

#include "datastructure.hpp"

#include <sstream>
#include <regex>
#include <cctype>
using namespace std;

const string COMMAND = "([[:w:]]*)";
// const string NUMBER = "([[:digit:]]*)";
const string STRING = "(([[:w:]]+[[:space:]]?)*)";
const string ZERO_OR_MORE_SPACES = "[[:space:]]*";

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


    while (cout << "chores> " and getline(cin, line)) {
        if (regex_match(line, result, reg)) {

            if (result.size() > 0) command = result.str(1);

            if (command == "quit") return 0;


            else if (command == "init") {
                if (result.str(2) == "")
                    cout << "Error: the number of priority levels is missing." << endl;
                else if (!isnum(result.str(2)))
                    cout << "Error: the number of priority levels must be an integer larger than 0." << endl;
                else
                    data.init(stoi(result.str(2)));
            }


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


            else if (command == "print") {
                if (result.str(2) == "") data.print();
                else cout << "Error: extra text after print command." << endl;
            }


            else if (command == "next") {
                if (result.str(2) == "") data.next();
                else cout << "Error: extra text after next command." << endl;
            }



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
