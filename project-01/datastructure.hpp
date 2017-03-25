#ifndef DATASTRUCTURE_HPP
#define DATASTRUCTURE_HPP

#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;

struct Product {
    string name;
    float price;
};

class Datastructure {
public:
    Datastructure();
    ~Datastructure();

    void addProduct(string mkt_name, string location, Product pdt);

    // Prints all the know store chain names in alphabetical order
    void chains();

    // Prints on screen in alphabetical order the locations of all the stores belonging to the given store chain
    void stores(string chain_name);

    // Prints out the cheapest price of the product in all the known stores.
    // Under the price it prints all the store chain and location pairs where the product can be found at the cheapest price
    void cheapest(string pdt_name);

    // The products available at the specified store will be printed in alphabetical order with the prices
    void selection(string chain_name, string location);



    int pdtExist(string mkt_name, string location, Product pdt);


private:
    map<string, map<string, vector<Product>>> mkts_;
    // map<string, vector<Product>> locations_;
    // vector<Product> pdts_;
};

#endif // DATASTRUCTURE_HPP
