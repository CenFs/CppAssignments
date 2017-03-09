#include <iostream>
#include <list>
#include <string>

using namespace std;

const char NORTH  = 'N';
const char EAST   = 'E';
const char SOUTH  = 'S';
const char WEST   = 'W';


void print_route(const list<char>& route_list) {
    // An iterator can remember a location of one element in a container.
    // begin() method returns the location of the first elemtn of a container.
    list<char>::const_iterator iter = route_list.begin();

    // We know all the elements of a container have been dealt with
    // once the iterator reaches the value of end() iterator. In other words:
    // As long as the iterator is different from the end() iterator,
    // there are still elements left.
    while ( iter != route_list.end() ) {
        // Unary *-operator evaluates to the actual value in the element
        // the iterator points to.
        cout << *iter;

        // ++-operator moves the iterator to the
        // next element inside the container.
        ++iter;
    }

    cout << endl;
}


int main() {
   string original_route = "";
   cout << "Enter original route: ";
   getline(cin, original_route);

   list<char> optimal_route = { };
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
