#include <iostream>
#include <exception>
//#include <stdexcept>
using namespace std;

int GCD(const int& x, const int& y) {
    int num = x, denom = y;
    while (num > 0 && denom > 0) {
        if (num >= denom) {
            num %= denom;
        }
        else {
            denom %= num;
        }
    }
    return num + denom;
}

class Rational {
public:
    // Конструктор по умолчанию
    Rational() {
        num = 0;
        denom = 1;
    }
    Rational(int numerator, int denominator) {
        if (denominator == 0) {
            throw invalid_argument("The denominator can't be 0");
        }
        const int gcd = GCD(abs(numerator), abs(denominator));
        num = numerator / gcd;
        denom = denominator / gcd;
        if (denom < 0) {
            denom = -denom;
            num = -num;
        }
    }
    int Numerator() const {
        return num;
    }
    int Denominator() const {
        return denom;
    }
private:
    int num;
    int denom;
};

Rational operator / (const Rational& lhs, const Rational& rhs) {
    if (lhs.Denominator() * rhs.Numerator() == 0) {
        throw domain_error("Division is impossible");
    }
    return {        
        lhs.Numerator() * rhs.Denominator(),
        lhs.Denominator() * rhs.Numerator()
    };
}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    }
    catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    }
    catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
