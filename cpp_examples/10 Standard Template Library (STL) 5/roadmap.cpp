#include <iostream>
#include <map>
#include <string>

using namespace std;

// Giving easier names for existing data types can
// be achieved with the "using" statement:
using DestinationMap = map<string, int>;
using DistanceMatrix = map<string, DestinationMap>;


void print(const DistanceMatrix& data) {
    for ( auto citydata : data ) {
        cout << citydata.first << endl;
        for ( auto destination_data : citydata.second ) {
            cout << "  " << destination_data.first
                 << "  " << destination_data.second
                 << endl;
        }
    }

    // Alternate way, using iterators.
    // -------------------------------
    // DistanceMatrix::const_iterator outer_iter = data.begin();
    // while ( outer_iter != data.end() ) {
    //    cout << outer_iter->first << endl;
    //
    //    DestinationMap::const_iterator inner_iter = outer_iter->second.begin();
    //    while ( inner_iter != outer_iter->second.end() ) {
    //       cout << "  " << inner_iter->first
    //            << "  " << inner_iter->second
    //            << endl;
    //
    //       ++inner_iter;
    //    }
    //
    //    ++outer_iter;
    // }

}

void add_connection_helper(DistanceMatrix& data,
                    const string& departure,
                    const string& destination,
                    int distance) {

    if ( data.find(departure) == data.end() ) {
        data.insert( { departure, {} } );
    }

    if ( data.at(departure).find(destination) == data.at(departure).end() ) {
        data.at(departure).insert( { destination, distance } );
    } else {
        data.at(departure).at(destination) = distance;
    }

    // Alternate way, buyer beware!
    // data[departure][destination] = distance;

    // Problem with []-operator is that a new key-payload-pair
    // is always created in the map.  The following for example is
    // generally not a good idea unless you are certain the key
    // already exists in the map:
    //
    //     cout << some_map[key] << endl;
    //
    // If it does not it will be added with some more or less
    // random payload.
}


void add_connection(DistanceMatrix& data,
                    const string& departure,
                    const string& destination,
                    int distance) {
    add_connection_helper(data, departure, destination, distance);
    add_connection_helper(data, destination, departure, distance);
}


int main() {
    DistanceMatrix distmat = {
        { "OUL", {{ "TRE", 300 },}},
        { "TRE", {{ "OUL", 300 }, { "HEL", 186 }, { "JKL", 179 },}},
        { "JKL", {{ "TRE", 179 },}},
        { "HEL", {{ "TRE", 186 },}},
    };

    add_connection(distmat, "TRE", "TUR", 192);
    add_connection(distmat, "TRE", "HEL", 189);

    print(distmat);
}
