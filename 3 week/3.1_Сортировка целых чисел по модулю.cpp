#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void PrintVec(const vector<int>& x/*, const string& title*/) {
	//cout << title << ": ";
	for (const auto& i : x) {
		cout << i << ' ';
	}
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	if (n < 0 || n > 1000) {
		cout << "Out of range";
	}
	else {
		vector<int> N(n);
		for (auto& i : N) {
			cin >> i;
		}
		//PrintVec(N, "Input");		
		sort(begin(N), end(N), [](int x, int y) {return (abs(x) < abs(y)); });
		PrintVec(N);
	}
	return 0;
}