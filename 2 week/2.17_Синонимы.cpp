#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
	map <string, set<string>> S;
	int q;
	string command, word1, word2, word;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		cin >> command;
		if (command == "ADD") {
			cin >> word1 >> word2;
			S[word1].insert(word2);
			S[word2].insert(word1);
		}
		else if (command == "COUNT") {
			cin >> word;
			cout << S[word].size() << endl;
		}
		else if (command == "CHECK") {
			cin >> word1 >> word2;
			if (S[word1].count(word2) == 1/*S[word1].find(word2) != S[word1].end()*/) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}			
		}
	}
	return 0;
}