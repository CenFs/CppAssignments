#include "commands.hpp"


Commands::Commands() {
}

Commands::~Commands() {
}

string Commands::compare_commands(string command, unsigned int input_fields) {
    if (command == "stores") { // stores chain_name
        if (input_fields == 2) return "stores";
        else return "WRONG_COMMAND";
    } else if (command == "cheapest") { // cheapest product_name
        if (input_fields == 2) return "cheapest";
        else return "WRONG_COMMAND";
    } else if (command == "selection") { // selection chain_name store_location
        if (input_fields == 3) return "selection";
        else return "WRONG_COMMAND";
    } else if (command == "chains") {
        return "chains";
    } else {
        return "WRONG_COMMAND";
    }
}
