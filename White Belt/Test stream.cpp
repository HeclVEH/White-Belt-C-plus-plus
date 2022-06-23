#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
	string checkdate;
	while (getline(cin, checkdate)) {
		//string date = "0-a1-2";
		stringstream str(checkdate);
		int year, month, day;
		char def1, def2;
		str >> year >> def1 >> month >> def2 >> day;
		if (def1 == '-' && def2 == '-') {
			cout << "good";
		}
		else {
			cout << "bad";
		}
		cout << endl;
		checkdate.clear();
	}
	//cout << cin.good() << endl;
	return 0;
}