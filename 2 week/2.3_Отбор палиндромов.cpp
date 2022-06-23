#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool IsPalindrom(string s) {	
	for (size_t i = 0; i < s.size() / 2; ++i) {
		if (s[i] != s[s.size() - i - 1]) {
			return false;  
		}
	}	
	return true;
}

vector<string> PalindromFilter(vector<string> words, int min_length) {
	vector<string> result;
	for (auto s : words) {		
		if (s.size() >= min_length && IsPalindrom(s)) {
			result.push_back(s);
		}
	}
	return result;
}

int main() {
	vector<string> words = {"aba","abc","keek","woood"};
	int min_Length = 4;	
	//cin >> min_Length;
	vector<string> result= PalindromFilter(words, min_Length);
	for (auto i : result) {
		cout << i << " ";
	}	
	return 0;
}

/*Моя версия
vector<string> PalindromFilter(vector<string> words, int minLength) {
	string str1, str2;
	vector<string> result;
	for (int i = 0; i < words.size(); ++i) {
		str1 = words[i];
		str2.clear();
		if (str1.size() >= minLength) {
			for (int j = str1.size() - 1; j >= 0; --j) {
				str2.append(str1, j, 1);
			}
			if (str2 == str1)
				result.push_back(str1);
		}
	}
	return result;
} */