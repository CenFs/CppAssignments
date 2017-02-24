#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include <algorithm>
using namespace std;


class Clock {
  public:
    Clock(int hour, int minute);
    void tick_tock();
    void print() const;
    string get_time() const;
    int fetch_hour() const;
    int fetch_minutes() const;
    bool operator<(const Clock &clk) const;

  private:
    // Minutes since the previous midnight.
    int minutes_since_midnight_;
};


int main() {
    vector<Clock> time_vector;
    string t1;
    cout << "Input time(hh.mm), Enter again to quit!" << endl;

    while(getline(cin, t1) && t1 != "") {

        int t1h, t1m;
        t1h = std::stoi(t1.substr(0, t1.find(".")));
        t1m = std::stoi(t1.substr(t1.find(".") + 1));
        Clock time1(t1h, t1m);

        //cout << time1.get_time() << endl;
        //time_vector.push_back(time1.get_time());
        time_vector.push_back(time1);

    }

    // cout << time_vector.size() << endl;
    sort(time_vector.begin(), time_vector.end());
    for (Clock &c : time_vector) {
        c.print();
    }
    return 0;
}


Clock::Clock(int hour, int minute):
    minutes_since_midnight_(60 * hour + minute) {
}


bool Clock::operator<(const Clock &clk) const {
    if (get_time() < clk.get_time()) {
        return true;
    } else {
        return false;
    }
}

string Clock::get_time() const {
    int h = fetch_hour();
    stringstream hh;
    hh << h;
    string hour = hh.str();

    int m = fetch_minutes();
    stringstream mm;
    mm << m;
    string minute = mm.str();

    return hour + "." + minute;
}


void Clock::tick_tock() {
    ++minutes_since_midnight_;

    if ( minutes_since_midnight_ >= 24 * 60 ) {
        minutes_since_midnight_ = 0;
    }
}


int Clock::fetch_hour() const {
    return minutes_since_midnight_ / 60;
}


int Clock::fetch_minutes() const {
    return minutes_since_midnight_ % 60;
}


void Clock::print() const {
    cout << setfill('0') << setw(2) << fetch_hour()
         << "."
         << setw(2) << fetch_minutes()
         << endl;
}
