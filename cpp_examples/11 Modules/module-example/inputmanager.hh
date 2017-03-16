#ifndef INPUTMANAGER_HH
#define INPUTMANAGER_HH

#include <string>

using namespace std;

// Function declarations (prototypes) of the modules public
// interface will be placed in the .hh-file.
// The definitions (implementations) of these functions
// are in the .cpp-file.

string ask_name(const string& prompt);
int ask_number(const string& prompt);

#endif
