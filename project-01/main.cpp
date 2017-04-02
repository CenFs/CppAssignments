#include "datastructure.hpp"
#include "splitter.hpp"
#include "commands.hpp"
#include <fstream>
using namespace std;


int main() {
    Splitter splitter;
    Datastructure mkts;
    Commands cmds;
    int error = OK;

    ifstream file("products.txt");
    if (not file) {
        cout << "Error: the input file can not be read." << endl;
        error = FAIL_TO_READ_FILE;
        return 0;
    } else {
        string line;
        while (getline(file, line)) { // store_chain;store_location;product_name;product_price
            splitter.set_string_to_split(line);
            unsigned int fields = splitter.split(';');
            if (fields == 4) {
                Product pdt;
                string store_chain = splitter.fetch_field(0);
                string store_location = splitter.fetch_field(1);
                pdt.name = splitter.fetch_field(2);
                pdt.price = stof(splitter.fetch_field(3));
                // cout << setiosflags(ios::fixed) << setprecision(2) << pdt.price << endl;

                mkts.addProduct(store_chain, store_location, pdt);

            } else {
                cout << "Error: fields != 4!" << endl;
                error = FIELDS_WRONG;
                break;
            }
        }
        file.close();
    }

    error = OK;
    while(1) {
        if (error != OK) {
            cout << "Error: Wrong input command." << endl;
        }

        cin.clear();
        cout << "product search> ";
        Splitter input_splitter;
        string input;
        string command;
        getline(cin, input);
        input_splitter.set_string_to_split(input);
        unsigned int input_fields = input_splitter.split(' ');
        command = input_splitter.fetch_field(0);
        string result = cmds.compare_commands(command, input_fields);

        if (input == "quit") {
            return 0;
        } else if (input == "chains") {
            mkts.chains();
            error = OK;
        } else if (result == "stores") { // stores chain_name
            string chain_name = input_splitter.fetch_field(1);
            mkts.stores(chain_name);
            error = OK;
        } else if (result == "cheapest") { // cheapest product_name
            string product_name = input_splitter.fetch_field(1);
            mkts.cheapest(product_name);
            error = OK;
        } else if (result == "selection") { // selection chain_name store_location
            string chain_name = input_splitter.fetch_field(1);
            string store_location = input_splitter.fetch_field(2);
            mkts.selection(chain_name, store_location);
            error = OK;
        } else if (result == "chains") {
            error = WRONG_COMMAND;
        } else {
            error = WRONG_COMMAND;
        }

        /*else if (command == "stores") { // stores chain_name
            if (input_fields == 2) {
                string chain_name = input_splitter.fetch_field(1);
                mkts.stores(chain_name);
                error = OK;
            } else {
                // cerr << "Error: Wrong command!" << endl;
                error = WRONG_COMMAND;
            }
        } else if (command == "cheapest") { // cheapest product_name
            if (input_fields == 2) {
                string product_name = input_splitter.fetch_field(1);
                mkts.cheapest(product_name);
                error = OK;
            } else {
                // cerr << "Error: Wrong command!" << endl;
                error = WRONG_COMMAND;
            }
        } else if (command == "selection") { // selection chain_name store_location
            if (input_fields == 3) {
                string chain_name = input_splitter.fetch_field(1);
                string store_location = input_splitter.fetch_field(2);
                mkts.selection(chain_name, store_location);
                error = OK;
            } else {
                // cerr << "Error: Wrong command!" << endl;
                error = WRONG_COMMAND;
            }
        } else {
            // cerr << "Error: Wrong command!" << endl;
            error = WRONG_COMMAND;
        }*/
    }
}
