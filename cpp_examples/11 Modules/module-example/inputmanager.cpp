#include <iostream>
#include <string>

using namespace std;


string ask_name(const string& prompt) {
    cout << prompt;

    string answer;
    getline(cin, answer);

    return answer;
}


int ask_number(const string& prompt) {
    cout << prompt;

    int answer;
    cin >> answer;
    cin.ignore();

    return answer;
}
