#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a;
	vector<int> v;
	cin >> a;
	while (a != 1) {		
		v.insert(v.begin(), a % 2);
		a /= 2;
	}
	v.insert(v.begin(), 1);
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i];
	}	
	/* while (a > 0) {
		v.push_back(a % 2);
		a /= 2;
	}
	for (int i = v.size() - 1; i >= 0; --i) {
		cout << v[i];
	} */
	cout << endl;
	system("pause");
	return 0;
}