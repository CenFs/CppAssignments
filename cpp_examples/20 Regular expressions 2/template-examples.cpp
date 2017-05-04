#include <iostream>
#include <string>

using namespace std;


// This template function can choose the larger of two values
// as long as the values are the same type.  Also, there is
// the implicit assumption that it is possible to do
// >-operation for the value of the parameter's type.
template <typename TYPE>
TYPE maximum(TYPE d1, TYPE d2) {
    if ( d1 > d2) {
        return d1;
    } else {
        return d2;
    }
}


// The my_pair type defines a struct that has two fields
// first and second whose types are not predefined.
// my_pair closely resembles the pair-type from STL
// which is used to store key and payload pairs
// within the map container's implementation.
template <typename KEY, typename PAYLOAD>
struct my_pair {
    KEY     first;
    PAYLOAD second;
};


// This generic function takes two parameters of non-predefined
// type and constructs and returns a my_pair type value initialized
// by using the parameter values.
template<typename KEY, typename PAYLOAD>
my_pair<KEY, PAYLOAD> make_my_pair(KEY val1, PAYLOAD val2) {
    my_pair<KEY, PAYLOAD> result = { val1, val2 };
    return result;
}


int main() {
    cout << maximum(1, 2) << endl;
    cout << maximum(2.4, 3.5) << endl;

    string s1 = "abc";
    string s2 = "def";
    cout << maximum(s1, s2) << endl;

    my_pair<int, string> p = { 1, "abc" };
    cout << p.first << ":" << p.second << endl;

    auto pp = make_my_pair('a', true);
    cout << boolalpha << pp.first << ":" << pp.second << endl;

    my_pair<int, string> ppp = make_my_pair(1, string("xyz"));
}
