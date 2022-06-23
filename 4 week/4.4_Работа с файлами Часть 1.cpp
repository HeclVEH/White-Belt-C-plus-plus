#include <fstream>
#include <iostream>
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
	const string text = "input.txt";
	ifstream input(text);	
	ReadFile(text);
	return 0;
}