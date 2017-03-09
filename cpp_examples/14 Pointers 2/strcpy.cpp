#include <iostream>

using namespace std;


// Strings in C-language are arrays of strings with
// ASCII-0 character appended at the end of the string.


void strcpy(char* destination, char* source) {
    while ( true ) {
        *destination = *source;

        // Once the ACSII-0 has been copied, we can stop.
        if ( *destination == '\0' ) {
            break;
        }

        // Both of the pointers must be stepped one character ahead.
        ++source;
        ++destination;
    }
}


int main() {
                             // +-----+-----+-----+------+
    char source[] = "abc";   // | 'a' | 'b' | 'c' | '\0' |
    char destination[4];     // +-----+-----+-----+------+

    // In C-programming all the responsibility of thing working out
    // correctly usually falls on the programmer's shoulders. Like
    // in the following: an assumption is made that there is enough
    // room in the destiantion array, strcpy function is certainly
    // not doing any kind of error checks (nor can it).
    strcpy(destination, source);

    cout << destination << endl;
}
