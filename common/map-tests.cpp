#include <iostream>
#include <map>

using namespace std;


int main() {
    map<string, double> pricelist = {
        { "milk",      1.05 },
        { "tuna",      1.39 },
    };

    // Internally (behind the scenes) STL map structure's elements
    // are structs that contain the key in the field named first and
    // the data in the fields named second.  The types of the fields
    // are defined by the the key and the data types used in the
    // map contained definition earlier.
    //
    //   struct pair {
    //      string first;
    //      double second;
    //   };

    pricelist.insert( { "carrots", 0.99 } );
    pricelist.insert( { "potatos", 0.99 } );


    // How to add key/data pair when one is not certain
    // if the key is already in the map.

    string key = "bread";
    double price = 1.49;

    if ( pricelist.find(key) == pricelist.end() ) {
        pricelist.insert( { key, price } );
    } else {
        pricelist.at(key) = price;
    }

    // You might be aware that []-operator can be used to achieve
    // the same reasult as the preceeding 5 lines of code:
    //
    //     pricelist[key] = price;
    //
    // This is fine. But you must understand the the following is wrong
    // unless "tomatos" is already present as a key in the map:
    //
    //     cout << pricelist["tomatos"] << endl;
    //
    // If it is not, it just got added with more or less random value
    // as the data (second field in the element struct).



    // Two ways to print the pricelist

    // for ( auto product : pricelist ) {
    //     cout << product.first << " " << product.second << endl;
    // }

    map<string, double>::iterator iter = pricelist.begin();
    while ( iter != pricelist.end() ) {
        cout << iter->first << "  " <<  iter->second << endl;

        ++iter;
    }
}
