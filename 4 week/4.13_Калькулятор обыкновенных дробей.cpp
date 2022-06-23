#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <exception>
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
    // ����������� �� ���������
    Rational() {
        num = 0;
        denom = 1;
    }
    Rational(int numerator, int denominator) {
        if (denominator == 0) {
            throw invalid_argument("Invalid argument");
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

//���������� ��������� "+"
Rational operator + (const Rational& lhs, const Rational& rhs) {
    return {
        lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
        rhs.Denominator() * lhs.Denominator()
    };
}

//���������� ��������� "-"
Rational operator - (const Rational& lhs, const Rational& rhs) {
    return {
        lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
        rhs.Denominator() * lhs.Denominator()
    };
}

//���������� ��������� "=="
bool operator == (const Rational& lhs, const Rational& rhs) {
    return (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator());
}

//���������� ��������� "*"
Rational operator * (const Rational& lhs, const Rational& rhs) {
    return {
        lhs.Numerator() * rhs.Numerator(),
        lhs.Denominator() * rhs.Denominator()
    };
}

//���������� ��������� "/"
Rational operator / (const Rational& lhs, const Rational& rhs) {
    if (lhs.Denominator() * rhs.Numerator() == 0) {
        throw domain_error("Division by zero");
    }
    return {
        lhs.Numerator() * rhs.Denominator(),
        lhs.Denominator() * rhs.Numerator()
    };
}

//���������� ��������� ">"
bool operator > (const Rational& lhs, const Rational& rhs) {
    return (lhs.Numerator() * rhs.Denominator() > rhs.Numerator() * lhs.Denominator());
}

//���������� ��������� "<"
bool operator < (const Rational& lhs, const Rational& rhs) {
    return (lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator());
}

//���������� ��������� ����� ">>"
istream& operator >> (istream& stream, Rational& obj) {
    int n, d;
    char c;
    if (stream) {
        stream >> n >> c >> d;
        if (stream && c == '/') {
            obj = Rational(n, d);
        }
    }
    /*
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
    */
    return stream;
}

//���������� ��������� ������ "<<"
ostream& operator << (ostream& stream, const Rational& obj) {
    stream << obj.Numerator() << '/' << obj.Denominator();
    return stream;
}

int main() {    
    char operation;
    Rational first, second, result;
    try {
        cin >> first >> operation;
        if (operation == '+') {
            cin >> second;
            result = first + second;
        }
        else if (operation == '-') {
            cin >> second;
            result = first - second;
        }
        else if (operation == '*') {
            cin >> second;
            result = first * second;
        }
        else {
            try {
                cin >> second;
                result = first / second;
            }
            catch (domain_error& s) {
                cout << s.what();
                return 0;
            }

        }
    }
    catch (invalid_argument& s) {
        cout << s.what();
        return 0;
    }
    cout << result;
    return 0;
}