#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    string name, gender;
    int mr_or_miss(string gender);

    cout << "Hello and welcome! Plz type your name here:" << endl;
    getline(cin, name);
    cout << "And what's your gender? (f/m)"<< endl;
    while(getline(cin, gender)) {
    if (mr_or_miss(gender) == 0) {
        cout << "Hello, Miss " + name + "! :)"<< endl;
        return 0;
    }
    else if (mr_or_miss(gender) == 1) {
        cout << "Hello, Mr " + name + "! :)"<< endl;
        return 0;
    }
    else
        cout << "Plz type only letter f or m :)"<< endl;
    }

}

int mr_or_miss(string gender) {
    if (gender == "f" || gender == "F") return 0;
    else if (gender == "m" || gender == "M") return 1;
    else return -1;
}
