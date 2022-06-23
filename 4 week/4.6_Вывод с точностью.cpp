#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
	ifstream input("input.txt");
	double value;
	vector<double> values;
	if (input) {
		while (input >> value) {
			values.push_back(value);
		}
	}
	cout << fixed << setprecision(3);
	for (const auto& v : values) {
		cout << v << endl;
	}
	return 0;
}

/*
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	ifstream input("input.txt");

	double a;

	cout << fixed << setprecision(3);

	while (input >> a) {
		cout << a << endl;
	}

	return 0;
}
*/