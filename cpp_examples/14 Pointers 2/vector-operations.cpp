#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


double square(double x);


// We will utilize the using mechanism to give a clear name
// for a type that is pointer to a function returning a double
// and taking a double as a parameter.
using Functiontype = decltype(&square);


// This function replaces all the elements of «vec» with a value
// «operation_function» returns when the element in question is passed
// as a parameter to it.
void foreach_element(vector<double>& vec, Functiontype operation_function) {

    // Notice the trick how the «element» variable used as the
    // loop variable can be a reference: we can modify the elements
    // of the vector we are looping through.
    for ( double& element: vec ) {
        element = operation_function(element);
    }
}


void print_vector(const vector<double>& vec) {
    cout << "{ ";

    for ( double element: vec ) {
        cout << element << " ";
    }

    cout << "}" << endl;
}


int main() {
    vector<double> testvector;

    testvector = { 0.0, 1.0, 2.0, 3.0, 4.0 };
    foreach_element(testvector, square);
    print_vector(testvector);

    // The function sqrt is also a function that returns a double
    // and takes one double as a parameter.  In other words
    // the same type of function as square function we made ourself:
    // we can pass that as a parameter to foreach_element-function.
    testvector = { 0.0, 1.0, 2.0, 3.0, 4.0 };
    foreach_element(testvector, sqrt);
    print_vector(testvector);

}


double square(double x) {
    return x * x;
}
