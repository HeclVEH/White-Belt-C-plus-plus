#include <iostream>
#include <string>
#include <vector>
using namespace std;

void MoveStrings(vector<string>& x, vector<string>& y) {
	for (auto i : x) {
		y.push_back(i);
	}
	x.clear();
}

int main() {	
	vector<string> source = { "a", "b", "c" };
	vector<string> destination = { "z" };
	MoveStrings(source, destination);
	for (auto i : destination) {
		cout << i << " ";
	}
 	return 0;
}