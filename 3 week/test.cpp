#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string GetPositivity(int x) {
	return x > 0 ? "positive"
		: (x == 0 ? "zero" : "negative");
}

string EstimateLength(const string& s) {
	return s.size() > 10 ? "long" : "short";
}

int main() {
	{
		vector<string> w;
		w.push_back("One");
		{
			w.push_back("Two");
			{
				w.push_back("Three");
			}
		}
		for (auto s : w) {
			cout << s;
		}
	}
	/*int a = 5;
	cout << GetPositivity(-5);
	/*int value;
	value += 15;
	cout << value;
	/*string s;
	s += "Hello";
	{
		s += " world";
	}
	cout << s;
	/*vector<int> v = {
	1, 2 ,3 ,4, 5, 5, 6
	}/* инициализация */;
	//int cnt = count_if(begin(v), end(v), [](int x) { return x % 2 != 0; });
	//int cnt = count(begin(v), end(v), [](int x) { return x % 2 != 0; });
	/*int cnt = 0;
	for (const auto& i : v) {
		cnt += (i % 2 != 0);
	}*/
	/*int cnt = 0;
	for (int i = 0; i < v.size(); ++i) {
		cnt += i % 2;
	}
	cout << cnt; */
	// код
}