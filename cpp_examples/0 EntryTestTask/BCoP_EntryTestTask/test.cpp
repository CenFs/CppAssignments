#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


static vector<string> names;
static vector<string> phone_numbers;


int main(void) {
	string tmp, name;
	int index;
	string delimiter = ":";
	int exists(string name);

	fstream f;
	f.open("input.txt", ios::in);
	while (!f.eof()) {
		std::getline(f, tmp);
		names.push_back(tmp.substr(0, tmp.find(delimiter)));
		phone_numbers.push_back(tmp.substr(tmp.find(delimiter) + 1));
		
	}
	f.close();

	while (1) {
		cout << "Please, type a name:";
		std::getline(cin, name);
		if (name != "QUIT" && name != "quit") {
			index = exists(name);
			if (index >= 0) {
				cout << phone_numbers[index] << endl;
			}
			else {
				cout << "Phone number is not available" << endl;
			}
		}
		else {
			cout << "Thank you for using this excellent phone number application!" << endl;
			cout << "Good Bye!" << endl;
			cin.get();
			return 0;
		}
	}
}


int exists(string name) {
	for (int i = 0; i < names.size(); i++) {
		if (name == names[i]) {
			return i;
		}
	}
	return -1;
}