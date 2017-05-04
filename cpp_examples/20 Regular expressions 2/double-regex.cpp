#include <iostream>
#include <regex>

using namespace std;

const string ZERO_OR_MORE_SPACES = "[[:space:]]*";
const string SIGN_MAYBE = "[-+]?";
const string UNSIGNED_INT = "[[:digit:]]+";
const string EXPONENT = "[eE]" + SIGN_MAYBE + UNSIGNED_INT;


int main() {
    // One can write a double in many different ways:
    //      1        1.         .2         1.2
    //     -1       -1.        -.2        -1.2
    //     -1e10    -1.E-20.   -.2e+30    -1.2e0
    // This complicates the regular expression slightly:
    regex reg(
        ZERO_OR_MORE_SPACES
        + "("
                + SIGN_MAYBE
        + ")"
        + "("
                + UNSIGNED_INT
                + "|"
                + UNSIGNED_INT + "\\." + UNSIGNED_INT
                + "|"
                + "\\." + UNSIGNED_INT
                + "|"
                + UNSIGNED_INT + "\\."
        + ")"
        + "("
                + EXPONENT
        + ")?"
        + ZERO_OR_MORE_SPACES
    );
    smatch result;
    string line;

    while ( cout << "Input a double: " and getline(cin, line) ) {
        if ( regex_match(line, result, reg) ) {
            for ( smatch::size_type i = 0; i < result.size(); ++i ) {
                cout <<  i << ": '" << result.str(i) << "'" << endl;
            }

        } else {

            cout << "Bad one, try again!" << endl;
        }
    }
}
