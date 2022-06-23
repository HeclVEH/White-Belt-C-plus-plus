#include <iostream>
#include <string>
#include <map>
using namespace std;

void PrintMap(map<string, string>& x) {
	for (auto& item : x) {
		cout << item.first << "/" << item.second << " ";
	}
}

int main() {
	int q;
	cin >> q;
	string command, old_capital;
	map<string, string> cc;
	string country, capital, new_country, old_country;
	while (q != 0) {
		--q;
		cin >> command;
		if (command == "CHANGE_CAPITAL") {			
			cin >> country >> capital;
			if (cc.find(country) == cc.end()) {				
				cc[country] = capital;
				cout << "Introduce new country " << country << " with capital " << capital << endl;
			}
			else {
				if (cc[country] == capital) {
					cout << "Country " << country << " hasn't changed its capital" << endl;
				}
				else {
					old_capital = cc[country];
					cc[country] = capital;
					cout << "Country " << country << " has changed its capital from " 
						<< old_capital << " to " << capital << endl;
				}
			}
		}
		else if (command == "RENAME") {
			cin >> old_country >> new_country;
			if (old_country == new_country || cc.find(old_country) == cc.end() || cc.find(new_country) != cc.end()) {
				cout << "Incorrect rename, skip" << endl;
			}
			else {
				cc[new_country] = cc[old_country];
				cc.erase(old_country);
				cout << "Country " << old_country << " with capital " << cc[new_country]
					<< " has been renamed to " << new_country << endl;
			}
		}
		else if (command == "ABOUT") {
			cin >> country;
			if (cc.find(country) == cc.end()) {
				cout << "Country " << country << " doesn't exist" << endl;
			}
			else {
				cout << "Country " << country << " has capital " << cc[country] << endl;
			}
		}
		else if (command == "DUMP") {
			if (cc.size() == 0) {
				cout << "There are no countries in the world" << endl;
			}
			else {
				PrintMap(cc);
			}
		}
	}
	return 0;
}

/*
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	int q;
	cin >> q;

	map<string, string> country_to_capital;

	for (int i = 0; i < q; ++i) {
		string operation_code;
		cin >> operation_code;

		if (operation_code == "CHANGE_CAPITAL") {

			string country, new_capital;
			cin >> country >> new_capital;
			if (country_to_capital.count(country) == 0) {
				cout << "Introduce new country " << country << " with capital " << new_capital << endl;
			}
			else {
				const string& old_capital = country_to_capital[country];
				if (old_capital == new_capital) {
					cout << "Country " << country << " hasn't changed its capital" << endl;
				}
				else {
					cout << "Country " << country << " has changed its capital from " << old_capital << " to " << new_capital << endl;
				}
			}
			country_to_capital[country] = new_capital;

		}
		else if (operation_code == "RENAME") {

			string old_country_name, new_country_name;
			cin >> old_country_name >> new_country_name;
			if (old_country_name == new_country_name || country_to_capital.count(old_country_name) == 0 || country_to_capital.count(new_country_name) == 1) {
				cout << "Incorrect rename, skip" << endl;
			}
			else {
				cout << "Country " << old_country_name << " with capital " << country_to_capital[old_country_name] <<
					" has been renamed to " << new_country_name << endl;
				country_to_capital[new_country_name] = country_to_capital[old_country_name];
				country_to_capital.erase(old_country_name);
			}

		}
		else if (operation_code == "ABOUT") {

			string country;
			cin >> country;
			if (country_to_capital.count(country) == 0) {
				cout << "Country " << country << " doesn't exist" << endl;
			}
			else {
				cout << "Country " << country << " has capital " << country_to_capital[country] << endl;
			}

		}
		else if (operation_code == "DUMP") {

			if (country_to_capital.empty()) {
				cout << "There are no countries in the world" << endl;
			}
			else {
				for (const auto& country_item : country_to_capital) {
					cout << country_item.first << "/" << country_item.second << " ";
				}
				cout << endl;
			}

		}

	}

	return 0;
}
*/