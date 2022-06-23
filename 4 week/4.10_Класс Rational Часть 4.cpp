#include <iostream>
#include <sstream>
using namespace std;

int GCD(const int& x,const int& y) {
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
    Rational() {
        num = 0;
        denom = 1;
        gcd = 1;
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
    int gcd;
};

bool operator==(const Rational& lhs, const Rational& rhs) {
    return (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator());
}

istream& operator>>(istream& stream, Rational& obj) {    
    if (stream.tellg() == -1) {
        return stream;
    }
    if (!stream.eof()) {
        int num = 0, denom = 1;
        stream >> num;
        stream.ignore(1);
        stream >> denom;
        obj = Rational(num, denom);
    } 
    return stream;
}

ostream& operator<<(ostream& stream, const Rational& obj) {
    stream << obj.Numerator() << '/' << obj.Denominator();        
    return stream;
}
// Реализуйте для класса Rational операторы << и >>

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
