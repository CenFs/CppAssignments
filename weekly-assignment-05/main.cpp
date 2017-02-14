#include <iostream>
#include <map>
#include <string>
using namespace std;

using Athlete = map<int, string>;
using Events = map<string, Athlete>;

void print(Events& events);
void add(Events& events, string event, int position, string name);

void print(Events& events) {
    for (auto event:events) {
        cout << event.first << endl;
        for (auto athlete:event.second) {
            cout << "\t" << athlete.first << "\t" << athlete.second << endl;
        }
    }
}
void add(Events& events, string event, int position, string name) {
    if (events.find(event) != events.end()) {
        events.at(event).insert( {position, name} );
    } else {
        events.insert( { event, {} } );
        events.at(event).insert( {position, name} );
    }
}



int main() {
    string n, e, line;
    int p;
    Events events;
    cout << "Input name, position, event of altheles (name,position,event):" << endl;
    while(getline(cin, line) && line != "") {
        n = line.substr(0, line.find(","));
        string tmp = line.substr(line.find(",")+1);
        e = tmp.substr(tmp.find(",")+1);
        string tmp2 = tmp.substr(0, tmp.find(","));
        p = atoi(tmp2.c_str());
        add(events, e, p, n);
    }
    print(events);
    return 0;
}
