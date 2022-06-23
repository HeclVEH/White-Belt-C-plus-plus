#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;


vector<int> Reversed1(const vector<int>& x) {
	vector<int> tmp = x;
	int n = x.size();  
	for (int i = 0; i < n / 2; ++i) {		
		int y = tmp[i];
		tmp[i] = tmp[n - 1 - i];
		tmp[n - 1 - i] = y;
	}
	return tmp;
}

vector<int> Reversed2(const vector<int>& input) {
	vector<int> result;
	for (int i = input.size() - 1; i >= 0; --i) {
		result.push_back(input[i]);
	}
	return result;
}

int main() {
	vector<int> v = { 1, 5, 3, 4, 2 };
	auto start1 = steady_clock::now();
	Reversed1(v);
	auto finish1 = steady_clock::now();
	cout << "Your function takes " << duration_cast<microseconds>(finish1 - start1).count()
		<< " microseconds to work." << endl;
	auto start2 = steady_clock::now();
	Reversed2(v);
	auto finish2 = steady_clock::now();
	cout << "The foreign function takes " << duration_cast<microseconds>(finish2 - start2).count()
		<< " microseconds to work." << endl;
	if ((finish1 - start1) > (finish2 - start2))
		cout << endl << "It's so long time, man!" << endl;
	else
		cout << endl << "Good job, man!" << endl;
	return 0;
}