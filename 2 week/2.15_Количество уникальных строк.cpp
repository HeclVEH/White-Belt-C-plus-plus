#include <iostream>
#include <set>
using namespace std;

int main() {
	set<string> a;
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		string tmp;
		cin >> tmp;
		a.insert(tmp);
	}
	cout << a.size();
	return 0;
}