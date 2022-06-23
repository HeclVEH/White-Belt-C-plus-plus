#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct student {
	string name;
	string surname;
	int day;
	int month;
	int year;
};

int main() {
	int N;
	cin >> N;
	vector<student> data;
	string name, surname;
	int day, month, year;
	for (int i = 0; i < N; ++i) {
		cin >> name >> surname >> day >> month >> year;
		data.push_back(student{ name,surname,day, month, year });
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; ++i) {
		string command;
		int j;
		cin >> command >> j;
		--j;
		if (command == "name" && j >= 0 && j < N) {			
			cout << data[j].name << " " << data[j].surname;
		}
		else if (command == "date" && j >= 0 && j < N) {
			cout << data[j].day << "." << data[j].month << "." << data[j].year;
		}
		else {
			cout << "bad request";
		}
		if (i != M - 1) {
			cout << endl;
		}

	}
	return 0;
}