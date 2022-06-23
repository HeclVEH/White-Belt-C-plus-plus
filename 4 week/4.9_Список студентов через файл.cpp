#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

struct student {
	string name;
	string surname;
	int day;
	int month;
	int year;
};

int main() {
	string in = "input.txt";
	ifstream input(in);
	if (input) {
		int N = 0, M = 0;
		input >> N;
		vector<student> data(N);
		for (int i = 0; i < N; ++i) {
			input >> data[i].name >> data[i].surname
				>> data[i].day >> data[i].month
				>> data[i].year;
		}
		input >> M;
		for (int i = 0; i < M; ++i) {
			string command;
			input >> command;
			if (command == "name") {
				int j = 0;
				input >> j;
				cout << data[j - 1].name << " " << data[j - 1].surname;
			}
			else if (command == "date") {
				int j = 0;
				input >> j;
				cout << data[j - 1].day << "." << data[j - 1].month << "." << data[j - 1].year;
			}
			else {
				cout << "bad request";
			}
			if (i != M - 1) {
				cout << endl;
			}

		}
	}
	else {
		cout << "File " << in << " not found";
	}
	return 0;
}