#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void ReadFile(ifstream& text) {
	//ifstream text(text);
	if (text) {
		string line;
		while (getline(text, line)) {
			cout << line << endl;
		}
	}
	else {
		cout << "Error! File does not exist!";
	}
}

void ReadAndWriteToFile(ifstream& in, ofstream& out) {
	if (in) {
		string line;
		while (getline(in, line)) {
			out << line << endl;
		}
	}
	else {
		cout << "Error! File does not exist!";
	}

}

int main() {	
	ifstream input("input.txt");
	ofstream output("output.txt");
	//ReadFile(input);
	ReadAndWriteToFile(input,output);
	return 0;
}