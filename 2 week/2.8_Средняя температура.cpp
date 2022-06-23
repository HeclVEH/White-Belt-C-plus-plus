#include <iostream>
#include <vector>
using namespace std;

void Decision(vector<int>& x) {
	int sum = 0;
	vector<int> tmp;
	for (int i = 0; i < x.size(); ++i) {
		sum += x[i];
	}
	for (int i = 0; i < x.size(); ++i) {
		if ((sum / x.size()) < x[i]) {
			tmp.push_back(i);
		}
	}	
	cout << tmp.size() << endl;
	for (auto s : tmp)
		cout << s << " ";
}

int main() {
	int N;
	cin >> N;
	vector<int> v(N);	
	for (int& i : v) {
		cin >> i;
	}
	Decision(v);
	return 0;
}

/* #include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> temperatures(n);
	int sum = 0;
	for (int& temperature : temperatures) {
		cin >> temperature;
		sum += temperature;
	}

	int average = sum / n;
	vector<int> result_indices;
	for (int i = 0; i < n; ++i) {
		if (temperatures[i] > average) {
			result_indices.push_back(i);
		}
	}

	cout << result_indices.size() << endl;
	for (int result_index : result_indices) {
		cout << result_index << " ";
	}
	cout << endl;

	return 0;
} */