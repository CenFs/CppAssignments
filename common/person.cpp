#include <iostream>
#include <string>

using namespace std;


class Person {
  public:
    Person();
    Person(string firstname, string lastname, int age);

    void celebrate_a_birthday();
    void celebrate_a_birthday(int age);
    void get_married(string new_lastname);

    int fetch_age() const;

    void print() const;

  private:
    string firstname_;
    string lastname_;
    int age_;
};


Person::Person(): firstname_("Mr"), lastname_("Unknown"), age_(0) {

}


Person::Person(string firstname, string lastname, int age):
    firstname_(firstname), lastname_(lastname), age_(age) {
}


void Person::celebrate_a_birthday() {
    ++age_;   // Could also be written:  age_ = age_ + 1  or  age_ += 1
}


void Person::celebrate_a_birthday(int age) {
    age_ = age;
}


void Person::get_married(string new_lastname) {
    lastname_ = new_lastname;
}


int Person::fetch_age() const {
    return age_;
}


void Person::print() const {
    cout << "Firstname: " << firstname_ << endl;
    cout << "Lastname:  " << lastname_ << endl;
    cout << "Age:       " << age_ << endl;
}


int main() {
    Person wizard("Harry", "Potter", 11);

    wizard.print();

    wizard.celebrate_a_birthday();
    cout << "The wizard is now at happy age of " << wizard.fetch_age() << endl;

    wizard.celebrate_a_birthday(25);

    wizard.get_married("Weasley");

    wizard.print();

    Person bad_guy;
    bad_guy.print();
}
