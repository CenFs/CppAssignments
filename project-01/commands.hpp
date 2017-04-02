#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include "datastructure.hpp"
#include <string>
using namespace std;

class Commands {
public:
    Commands();
    ~Commands();

    string compare_commands(string command, unsigned int input_fields);

private:

};

#endif // COMMANDS_HPP
