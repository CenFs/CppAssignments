#include <iostream>
#include <iomanip>
#include <string>
#include <regex>

using namespace std;


const string SPACE_REGEX        = "[[:space:]]*";
const string DAY_REGEX          = "([[:digit:]]{1,2})";
const string MONTH_REGEX        = DAY_REGEX;
const string YEAR_REGEX         = "([[:digit:]]{4})";

const string FINNISH_DATE_REGEX = SPACE_REGEX
                                     + DAY_REGEX
                                     + "\\."
                                     + MONTH_REGEX
                                     + "\\."
                                     + YEAR_REGEX
                                     + SPACE_REGEX;


int main() {
    regex finnish_date_re(FINNISH_DATE_REGEX);
    smatch result;

    string line;
    while ( cout << "Input a date (dd.mm.yyyy): " and getline(cin, line) ) {
        if ( regex_match(line, result, finnish_date_re) ) {
            int day = stoi(result.str(1));
            int month = stoi(result.str(2));
            int year = stoi(result.str(3));

            cout << setfill('0')
                 << year << "-"
                 << setw(2) << month << "-"
                 << setw(2) << day << endl;

        } else {

            // What is cerr?
            cerr << "The line \""
                 << line
                 << "\" is not a finnish date!"
                 << endl;
        }
    }
}
