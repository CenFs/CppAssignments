#include <iostream>
#include <vector>
#include <string>

using namespace std;

const char NORTH  = 'N';
const char EAST   = 'E';
const char SOUTH  = 'S';
const char WEST   = 'W';


void print_route(const vector<char>& route_vector) {
    vector<char>::size_type index = 0;

    while ( index < route_vector.size() ) {
        cout << route_vector.at(index);
        ++index;
    }

    cout << endl;
}


int main() {
   string original_route = "";
   cout << "Enter original route: ";
   getline(cin, original_route);

   vector<char> optimal_route = { };
   string::size_type index = 0;

   while ( index < original_route.length() ) {
      char new_direction = original_route.at(index);

      if ( optimal_route.size() == 0 ) {
         optimal_route.push_back(new_direction);

      } else {

         char previous_direction = optimal_route.back();

         if ( previous_direction == EAST and new_direction == WEST ) {
             optimal_route.pop_back();

         } else if ( previous_direction == WEST and new_direction == EAST ) {
             optimal_route.pop_back();

         } else if ( previous_direction == NORTH and new_direction == SOUTH ) {
             optimal_route.pop_back();

         } else if ( previous_direction == SOUTH and new_direction == NORTH ) {
             optimal_route.pop_back();

         } else {

             optimal_route.push_back(new_direction);
         }
      }

      ++index;
   }

   print_route(optimal_route);
}
