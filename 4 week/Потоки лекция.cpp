#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void ReadFile(const string& text) {
	ifstream input(text);
	if (input) {
		string line;
		while (getline(input, line)) {
			cout << line << endl;
		}
	}
	else {
		cout << "Error! File does not exist!";
	}
}

int main() {
	const string text = "text.txt";
	const string fortest = "Out.txt";
	ofstream output(fortest, ios::app);
	ifstream input(text);
	output << "Common man its so easy" << endl;
	ReadFile(fortest);	

	return 0;
}