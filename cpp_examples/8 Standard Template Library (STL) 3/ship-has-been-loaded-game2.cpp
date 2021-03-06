#include <iostream>
#include <string>
#include <set>
#include <cctype>  // tolower, isalpha

using namespace std;

bool has_the_game_ended(const set<string>& word_container, const string& word) {
    // With set (and later map) container it is more efficient to
    // use set's own find method instead of the generic
    // find function from the algorithm library.
    if ( word_container.find(word) != word_container.end() ) {
        cout << "The word " << word << " has already been used."
             << endl << "You have lost the game!" << endl;

        return true;
    }

    return false;
}


int main() {
    set<string> words = { };
    string initial;

    while ( true ) {
        cout << "Please, enter initial letter: ";
        getline(cin, initial);

        if ( initial.size() == 1 and isalpha(initial.at(0)) ) {
            break;
        }

        cout << "You must answer with exactly one letter!" << endl << endl;
    }

    initial = tolower(initial.front());

    cout << endl
         << "The ship has been loaded with items beginning with the letter "
         << initial << "."
         << endl << endl;

    while ( true ) {
        cout << "Enter a word beginning with " << initial << ": ";
        string answer;

        getline(cin, answer);

        if ( answer.empty() ) {
            cout << "Empty words are not allowed. Try again!"
                 << endl << endl;
            continue;
        }

        answer.front() = tolower(answer.front());

        if ( not isalpha(answer.front()) ) {
            cout << "Word must begin with a letter. Try again!" << endl << endl;
            continue;
        }

        if ( answer.front() != initial.front() ) {
            cout << "Word must begin with the letter " << initial << "."
                 << endl << endl;
            continue;
        }

        if ( has_the_game_ended(words, answer) ) {
            break;
        }

        cout << answer << " has been loaded into the ship!" << endl << endl;

        words.insert(answer);  // With sets you have to use insert, push_back
    }                          // works with vectors, deques, and lists.
}
