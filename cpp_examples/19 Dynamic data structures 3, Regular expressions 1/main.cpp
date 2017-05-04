#include <iostream>
#include <regex>

using namespace std;


int main() {
    // What does it mean, when you write string literals
    // in a row "..." "..." "..." ?
    regex reg(
        "[[:space:]]*"    // Line starts with 0-n spaces.
        "([-+]?)"         // It is possible to have a sign in front of the int.
        "([[:digit:]]+)"  // An integer: 1-n digits.
        "[[:space:]]*"    // Line ends  with 0-n spaces.
    );
    smatch result;

    string line;
    while ( cout << "Input an int: " and getline(cin, line) ) {
        if ( regex_match(line, result, reg) ) {
            for ( smatch::size_type i = 0; i < result.size(); ++i ) {
                cout <<  i << ": '" << result.str(i) << "'" << endl;

            }

        } else {

            cout << "Bad one, try again!" << endl;
        }
    }
}
