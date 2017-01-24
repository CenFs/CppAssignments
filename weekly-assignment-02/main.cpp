#include <iostream>
#include <iomanip>

using namespace std;


class Clock {
  public:
    Clock(int hour, int minute);
    void tick_tock();
    void print() const;
    int difference(Clock time) const;

  private:
    int hours_;
    int minutes_;
};


int main(int argc, char *argv[]) {
    int count = 3;
    while(count--) {
        string t1, t2;
        cout << "Input time1(hh.mm): ";
        getline(cin, t1);
        cout << "Input time2(hh.mm): ";
        getline(cin, t2);

        int t1h, t1m, t2h, t2m;
        t1h = std::stoi(t1.substr(0, t1.find(".")));
        t1m = std::stoi(t1.substr(t1.find(".") + 1));
        t2h = std::stoi(t2.substr(0, t2.find(".")));
        t2m = std::stoi(t2.substr(t2.find(".") + 1));


        Clock time1(t1h, t1m);
        Clock time2(t2h, t2m);

        int diff = time1.difference(time2);
        cout << "Difference (min): " << diff << endl;

        //time1.tick_tock();
        //time1.print();
    }
    return 0;
}





Clock::Clock(int hour, int minute):
    hours_(hour), minutes_(minute) {
}


void Clock::tick_tock() {
    ++minutes_;
    if ( minutes_ >= 60 ) {
        minutes_ = 0;
        ++hours_;
    }

    if ( hours_ >= 24 ) {
        hours_ = 0;
    }
}


void Clock::print() const {
    cout << setw(2) << setfill('0') << hours_
         << "."
         << setw(2) << minutes_
         << endl;
}


int Clock::difference(Clock time) const {
    int thours = time.hours_;
    int tmins = time.minutes_;

    int mins1 = hours_ * 60 + minutes_;
    int mins2 = thours * 60 + tmins;
    int diff_mins = 0;
    if (hours_ > thours) {
        mins1 = 24 * 60 - mins1;
        diff_mins = mins1 + mins2;
    }
    else {
        if (mins1 > mins2) {
            diff_mins = mins1 - mins2;
        }
        else diff_mins = mins2 - mins1;
    }
    return diff_mins;

}
