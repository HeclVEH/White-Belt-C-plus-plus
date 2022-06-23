#include <map>
#include <string>
#include <iostream>
#include <vector>
//#include <algorithm>
using namespace std;

string FindNameByYear(const map<int, string>& names, int year) {
    string name;    
    for (const auto& item : names) {       
        if (item.first <= year) {
            name = item.second;
        }
        else {
            break;
        }
    }
    return name;
}

string GetHistory(const map<int, string>& names, int year) {
    string tmp; 
    string result;    
    vector<string> history;      
    for (const auto& item : names) {
        if (item.first <= year) {
            if (tmp != item.second) {
                history.push_back(item.second);
            }
            tmp = item.second;                       
        }
        else {
            break;
        }
    }
    if (history.size() != 1) {
        result = " (";
        for (int i = history.size() - 2; i >= 0; --i) {
            result += history[i];
            if (i != 0) {
                result += ", ";
            }
            else {
                result += ")";
            }
        }
    } 
    return result;
}

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        name[year] = first_name;        
    }
    void ChangeLastName(int year, const string& last_name) {
        surname[year] = last_name;       
    }
    string GetFullName(int year) {       
        const string first_name = FindNameByYear(name, year);
        const string last_name = FindNameByYear(surname, year);        
        if (first_name.empty() && last_name.empty()) {
            return "Incognito";           
        }
        else if (first_name.empty()) {
            return last_name + " with unknown first name";            
        }
        else if (last_name.empty()) {
            return first_name + " with unknown last name";            
        }
        else {
            return first_name + " " + last_name;
        }
    }
    string GetFullNameWithHistory(int year) {
        const string first_name = FindNameByYear(name, year);
        const string last_name = FindNameByYear(surname, year);
        const string history_first_name = GetHistory(name, year);
        const string history_last_name = GetHistory(surname, year);
        if (first_name.empty() && last_name.empty()) {
            return "Incognito";
        }
        else if (first_name.empty()) {
            return last_name + history_last_name + " with unknown first name";
        }
        else if (last_name.empty()) {
            return first_name + history_first_name + " with unknown last name";
        }
        else {
            return first_name + history_first_name + " " + last_name + history_last_name;
        }        
    }
private:
    map<int, string> name;
    map<int, string> surname;  
};


//Пример 1
/*
int main() {
    Person person;

    person.ChangeFirstName(1900, "Eugene");
    person.ChangeLastName(1900, "Sokolov");
    person.ChangeLastName(1910, "Sokolov");
    person.ChangeFirstName(1920, "Evgeny");
    person.ChangeLastName(1930, "Sokolov");
    cout << person.GetFullNameWithHistory(1940) << endl;

    return 0;
} 
*/


//Пример 2
int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;

    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;

    return 0;
}


//Пример 3
/*
int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeFirstName(1965, "Appolinaria");

    person.ChangeLastName(1965, "Sergeeva");
    person.ChangeLastName(1965, "Volkova");
    person.ChangeLastName(1965, "Volkova-Sergeeva");

    for (int year : {1964, 1965, 1966}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}
*/