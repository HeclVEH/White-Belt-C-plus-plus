#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <exception>
#include <iomanip>

using namespace std;

class Date {
public:
    Date() {
        year = 0;
        month = 0;
        day = 0;
    }
    Date(const int& new_year, const int& new_month, const int& new_day) {
        year = new_year;
        month = new_month;
        day = new_day;
    }
    int GetYear() const {
        return year;
    }
    int GetMonth() const {
        return month;
    }
    int GetDay() const {
        return day;
    }
private:
    int year;
    int month;
    int day;
};

bool operator < (const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear()) {
        if (lhs.GetMonth() == rhs.GetMonth()) {
            return lhs.GetDay() < rhs.GetDay();
        }
        else {
            return lhs.GetMonth() < rhs.GetMonth();
        }
    }
    else {
        return lhs.GetYear() < rhs.GetYear();
    }
}

void WrongDateFormat(const string& str) {
    string error = "Wrong date format: " + str;
    throw runtime_error(error);   
}

Date ConvertDate(const string& str) {
    stringstream stream(str);
    Date date;
    int year, month, day;
    char def1, def2;
    stream >> year >> def1 >> month >> def2;
    if (!isdigit(stream.peek()) && stream.peek() != ('-', '+')) {
        WrongDateFormat(str);
    }
    stream >> day;
    if (def1 != '-' || def2 != '-' || stream.peek() != EOF) {
        WrongDateFormat(str);
    }
    /*
    if (year < 0 || year > 9999) {
        WrongDateFormat(str);
    }
    */
    if (month < 1 || month > 12) {
        string error = "Month value is invalid: " + to_string(month);
        throw runtime_error(error);
    }
    if (day < 1 || day > 31) {
        string error = "Day value is invalid: " + to_string(day);
        throw runtime_error(error);
    }
    date = Date{ year,month,day };
    return date;
}

ostream& operator << (ostream& stream, const Date& obj) {
    stream << setfill('0');
    stream << setw(4) << obj.GetYear() << '-'
           << setw(2) << obj.GetMonth() << '-'
           << setw(2) << obj.GetDay();
    return stream;
}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        DB[date].insert(event);
    }
    bool DeleteEvent(const Date& date, const string& event) {
        if (DB[date].find(event) == DB[date].end()) {
            return false;
        }
        else {
            DB[date].erase(event);
            return true;
        }
    }
    int  DeleteDate(const Date& date) {
        int N;
        N = DB[date].size();
        DB.erase(date);
        return N;
    }   
    void Find(const Date& date) const{
        if (DB.find(date) != DB.end()) {
            for (const auto& i : DB.at(date)) {
                cout << i << endl;
            }
        }
    }
    void Print() const{
        for (const auto& item : DB) {            
            for (const auto& i : DB.at(item.first)) {
                cout << item.first << " " << i << endl;
            }
        }
    }
private:
    map <Date, set<string>> DB;
};

int main() {  
    Database db;
    string command;
    try {
        while (getline(cin, command)) {
            if (!command.empty()) {
                string query;
                stringstream stream(command);
                stream >> query;
                if (query == "Add" || query == "Del" || query == "Find") {
                    Date date;
                    string date_string, event;
                    stream >> date_string;
                    date = ConvertDate(date_string);
                    stream >> event;
                    if (query == "Add") {
                        db.AddEvent(date, event);
                    }
                    if (query == "Find") {
                        db.Find(date);
                    }
                    if (query == "Del") {
                        if (event == "") {
                            int N;
                            N = db.DeleteDate(date);
                            cout << "Deleted " << N << " events" << endl;
                        }
                        else {
                            if (db.DeleteEvent(date, event)) {
                                cout << "Deleted successfully" << endl;
                            }
                            else {
                                cout << "Event not found" << endl;;
                            }
                        }
                    }
                }
                else if (query == "Print") {
                    db.Print();
                }
                else {
                    cout << "Unknown command: " << query << endl;
                }
            }
        }
    }
    catch (exception& es) {
        cout << es.what();
    }
    return 0;
}