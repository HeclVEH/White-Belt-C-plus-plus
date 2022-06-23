#include <map>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

map<char,int> BuildCharCounters(string& x) {
	map<char, int> result;
	for (char& i : x) {
		++result[i];
	}
	return result;
}

void PrintMap(map<char,int>& x) {
	for (auto& item : x) {
		cout << item.first << ": " << item.second << endl;
	}
}

int main() {
	int N;
	cin >> N;
	string s1, s2;
	//cin >> s1;
	//map<char,int> test = BuildCharCounters(s1);
	//PrintMap(test);
	vector<string> YESorNO;
	while (N != 0) {
		--N;
		cin >> s1 >> s2;
		if (s1.size() == s2.size()) {
			if (BuildCharCounters(s1) == BuildCharCounters(s2)) {
				YESorNO.push_back("YES");
			}
			else {
				YESorNO.push_back("NO");
			}
		}
		else {
			YESorNO.push_back("NO");
		}
	}
	for (auto& i : YESorNO) {
		cout << i << endl;
	} 
	return 0;
}

/*#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> BuildCharCounters(const string& word) {
	map<char, int> counters;
	for (char c : word) {
		++counters[c];
	}
	return counters;
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		string first_word, second_word;
		cin >> first_word >> second_word;
		if (BuildCharCounters(first_word) == BuildCharCounters(second_word)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
} */