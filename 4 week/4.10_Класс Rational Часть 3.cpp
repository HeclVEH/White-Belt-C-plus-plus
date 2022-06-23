#include <iostream>
using namespace std;

int GCD(int x, int y) {
    while (x > 0 && y > 0) {
        if (x >= y) {
            x %= y;
        }
        else {
            y %= x;
        }
    }
    return x + y;
}

class Rational {
public:
    Rational() {
        num = 0;
        denom = 1;
    }

    Rational(int numerator, int denominator) {
        num = numerator;
        denom = denominator;
        gcd = GCD(abs(num), abs(denom));
    }

    int Numerator() const {
        if (num > 0 && denom < 0) {
            return -num / gcd;
        }
        else if (num < 0 && denom < 0) {
            return abs(num / gcd);
        }
        return num / gcd;
    }

    int Denominator() const {
        if (num == 0) {
            return 1;
        }
        else if (denom < 0) {
            return abs(denom / gcd);
        }
        return denom / gcd;
    }

private:
    int num;
    int denom;
    int gcd = 0;
};

bool operator==(const Rational& lhs, const Rational& rhs) {
    return (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator());
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Numerator(),
                    lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Denominator(),
        lhs.Denominator() * rhs.Numerator());
}

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}