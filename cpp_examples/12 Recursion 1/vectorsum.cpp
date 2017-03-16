#include <iostream>
#include <vector>

using namespace std;


int sum(vector<int> v) {
    if ( v.empty() ) {
        return 0;

    } else {

        // Add the last element to the sum of the rest of the elements.
        int last = v.back();
        v.pop_back();
        return last + sum(v);
    }
}


int main() {
    vector<int> vec = { 1, 3, 5, 7, 9, 2, 4, 6, 8 };

    cout << sum(vec) << endl;
}
