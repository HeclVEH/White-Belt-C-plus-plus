#include <iostream>
#include <map>
#include <set>
#include <vector>
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

bool operator>(const Rational& lhs, const Rational& rhs) {
    return (lhs.Numerator() * rhs.Denominator() > rhs.Numerator() * lhs.Denominator());
}

bool operator<(const Rational& lhs, const Rational& rhs) {
    return (lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator());
}

// Реализуйте для класса Rational оператор(ы), необходимые для использования его
// в качестве ключа map'а и элемента set'а

int main() {
    {
        const set<Rational> rs = { {1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2} };
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{ {1, 25}, { 1, 2 }, { 3, 4 }}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
