#include <iostream>

using namespace std;

class Fractional {
public:
    Fractional();
    Fractional(int numerator, int denominator);

    Fractional multiply(Fractional right_side) const;
    Fractional plus(Fractional right_side) const;
    Fractional minus(Fractional right_side) const;
    Fractional divide(Fractional right_side) const;

    Fractional inverse() const;

    void print() const;

private:
    int numerator_;
    int denominator_;
};

Fractional::Fractional() {
    numerator_ = 0;
    denominator_ = 1;
}

Fractional::Fractional(int numerator, int denominator) {
    numerator_ = numerator;
    denominator_ = denominator;
}

void Fractional::print() const {
    cout << numerator_ << "/" << denominator_ << endl;
}

Fractional Fractional::multiply(Fractional right_side) const {
    Fractional result(numerator_ * right_side.numerator_,
                      denominator_ * right_side.denominator_);
    return result;
}

Fractional Fractional::plus(Fractional right_side) const {
}

Fractional Fractional::minus(Fractional right_side) const {
}

Fractional Fractional::divide(Fractional right_side) const {
    return multiply(right_side.inverse());
}

Fractional Fractional::inverse() const {
    return {denominator_, numerator_};
}


int main(int argc, char *argv[]) {
    Fractional test(3, 4);
    test.print();

    Fractional fr1(3, 7);
    Fractional fr2(5, 9);

    Fractional result;
    result = fr1.multiply(fr2);
    result.print();
    return 0;
}
