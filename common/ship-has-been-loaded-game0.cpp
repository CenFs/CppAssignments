#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <cctype>

using namespace std;

bool has_the_game_ended(const list<string>& word_container,
                        const string& word) {
    // Variation 1
    //------------
    // Using algorithm library function find to check if word
    // is already in the container.
    if ( find(word_container.begin(),
              word_container.end(),
              word) != word_container.end() ) {

        cout << "The word " << word << " has already been used."
             << endl << "You have lost the game!" << endl;

        return true;
    }

    return false;

    // Variation 2
    //------------
    // Using for loop to iterate though the container.
    // for ( auto element : word_container ) {
    //     if ( element == word ) {
    //         cout << "The word " << word << " has already been used."
    //              << endl << "You have lost the game!" << endl;
    //         return true;
    //     }
    // }
    //
    // return false;

    // Variation 3
    //------------
    // Iterating through the container manually using suitable iterator type.
    // list<string>::const_iterator iter = word_container.begin();
    // while ( iter != word_container.end() ) {
    //     if ( *iter == word ) {
    //         cout << "The word " << word << " has already been used."
    //              << endl << "You have lost the game!" << endl;
    //
    //         return true;
    //     }
    //
    //     ++iter;
    // }
    //
    // return false;
}


int main() {
    list<string> words = { };
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

        words.push_back(answer);
    }
}
