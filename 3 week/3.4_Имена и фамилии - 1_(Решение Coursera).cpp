#include <map>
#include <string>
#include <iostream>
using namespace std;

// ���� ��� ����������, ���������� ������ ������
string FindNameByYear(const map<int, string>& names, int year) {
    string name;  // ���������� ��� ����������

    // ���������� ��� ������� �� ����������� ����� �������, �� ���� � ��������������� �������
    for (const auto& item : names) {
        // ���� ��������� ��� �� ������ �������, ��������� ���
        if (item.first <= year) {
            name = item.second;
        }
        else {
            // ����� ���� ������������, ��� ��� ��� ������ � ��� ����������� ��������� � ��������
            break;
        }
    }

    return name;
}

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        first_names[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        last_names[year] = last_name;
    }
    string GetFullName(int year) {
        // �������� ��� � ������� �� ��������� �� ��� year
        const string first_name = FindNameByYear(first_names, year);
        const string last_name = FindNameByYear(last_names, year);
        // ���� � ���, � ������� ����������
        if (first_name.empty() && last_name.empty()) {
            return "Incognito";
            // ���� ���������� ������ ���
        }
        else if (first_name.empty()) {
            return last_name + " with unknown first name";
            // ���� ���������� ������ �������
        }
        else if (last_name.empty()) {
            return first_name + " with unknown last name";
            // ���� �������� � ���, � �������
        }
        else {
            return first_name + " " + last_name;
        }
    }

private:
    map<int, string> first_names;
    map<int, string> last_names;
};

int main() {
    Person person;

    //person.ChangeFirstName(1977, "Alexey");
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}

// 4-�� ����
/*
int main() {
    Person person;

    cout << person.GetFullName(2000) << endl;
    person.ChangeLastName(1968, "1968_2nd");
    person.ChangeLastName(1967, "1967_2nd");
    person.ChangeLastName(1965, "1965_2nd");
    person.ChangeLastName(1966, "1966_2nd");

    for (int year : {1900, 1920, 1950, 1965, 1966, 1967, 1968}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1920, "1920_1st");
    person.ChangeFirstName(1900, "1900_1st");
    person.ChangeFirstName(1965, "1965_1st");
    person.ChangeFirstName(1950, "1950_1st");

    for (int year : {1900, 1920, 1950, 1965, 1966, 1967, 1968}) {
        cout << person.GetFullName(year) << endl;
    }
    return 0;
}

//5-�� ����
int main() {
    Person person;

    person.ChangeLastName(3, "3_2nd");
    person.ChangeLastName(6, "6_2nd");

    for (int year : {3, 4, 5, 6}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(-1, "-1_1st");
    person.ChangeFirstName(2, "2_1st");

    for (int year : {-1, 0, 1, 2, 3, 6}) {
        cout << person.GetFullName(year) << endl;
    }
    return 0;
} */

//���� �� Igor Sumin
/*
int main() {
    Person person;
    person.ChangeLastName(3, "3_2nd");
    person.ChangeLastName(6, "6_2nd");

    for (int year : {3, 4, 5, 6}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(-1, "-1_1st");
    person.ChangeFirstName(2, "2_1st");

    for (int year : {-1, 0, 1, 2, 3, 6}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(-2, "-2_1st");
    person.ChangeLastName(7, "7_2nd");

    for (int year : {-3, -2, -1, 0, 1, 2, 3, 6, 7, 8}) {
        cout << person.GetFullName(year) << endl;
    }
    return 0;
} */