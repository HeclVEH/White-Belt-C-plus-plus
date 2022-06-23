#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {        
        name[year] = first_name;        
    }
    void ChangeLastName(int year, const string& last_name) {
        surname[year] = last_name;        
    }
    string GetNameOrSurname(const map<int, string>& data,const int& year) {
        string tmp;
        for (const auto& item : data) {
            if (item.first <= year) {
                tmp = item.second;
            }
            else {                
                break;
            }            
        }       
        return tmp;
    }
    string GetFullName(const int& year) {
        if (name.size() != 0 && surname.size() != 0) {
            if (year < name.begin()->first && year < surname.begin()->first) {
                return "Incognito";
            }
            else if (year >= name.begin()->first && year < surname.begin()->first) {
                string tmp;
                tmp = GetNameOrSurname(name, year) + " with unknown last name";
                return tmp;
            }
            else if (year < name.begin()->first && year >= surname.begin()->first) {
                string tmp;
                tmp = GetNameOrSurname(surname, year) + " with unknown first name";
                return tmp;
            }
            else if (year >= name.begin()->first && year >= surname.begin()->first) {
                string tmp;
                tmp = GetNameOrSurname(name, year) + " " + GetNameOrSurname(surname, year);
                return tmp;
            }
        }
        else if (name.size() != 0) {
            if (year >= name.begin()->first) {
                string tmp;
                tmp = GetNameOrSurname(name, year) + " with unknown last name";
                return tmp;
            }
            else {
                return "Incognito";
            }
        }
        else if (surname.size() != 0) {
            if (year >= surname.begin()->first) {
                string tmp;
                tmp = GetNameOrSurname(surname, year) + " with unknown first name";
                return tmp;
            }
            else {
                return "Incognito";
            }
        }
        else if (name.size() == 0 && surname.size() == 0) {
            return "Incognito";
        }
    }
private:
    map<int, string> name ,surname;
};

//Главная программа

/*
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
} */


// 4-ый тест
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

//5-ый тест
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

//Тест от Igor Sumin
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
}