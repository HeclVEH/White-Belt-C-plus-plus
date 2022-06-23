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

class Plus_or_Minus {
public:
    Plus_or_Minus(char new_operation, const Rational& lhs, const Rational& rhs) {
        operation = new_operation;
        lhs_denom = lhs.Denominator();
        lhs_num = lhs.Numerator();
        rhs_denom = rhs.Denominator();
        rhs_num = rhs.Numerator();
    }
    Rational Result() {
        if (lhs_denom == rhs_denom) {
            if (operation == '+') {
                return Rational(lhs_num + rhs_num, lhs_denom);
            } 
            else {
                return Rational(lhs_num - rhs_num, lhs_denom);
            }
        } 
        else {
            if (operation == '+') {
                int common_denom = lhs_denom * rhs_denom;
                int sum_num = lhs_num * rhs_denom + rhs_num * lhs_denom;
                return Rational(sum_num, common_denom);
            }
            else {
                int common_denom = lhs_denom * rhs_denom;
                int sum_num = lhs_num * rhs_denom - rhs_num * lhs_denom;
                return Rational(sum_num, common_denom);
            }
        }
    }
private:
    char operation;
    int lhs_denom = 0;
    int lhs_num = 0;
    int rhs_denom = 0;
    int rhs_num = 0;
};

bool operator==(const Rational& lhs, const Rational& rhs) {
    return (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator());
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
    Plus_or_Minus item('+', lhs, rhs);
    return item.Result();   
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    Plus_or_Minus item('-', lhs, rhs);
    return item.Result();
}

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}