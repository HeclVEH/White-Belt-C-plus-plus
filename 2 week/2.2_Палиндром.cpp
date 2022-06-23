/*#include <iostream>
#include <string>
using namespace std; */

bool IsPalindrom(string s) {	
	string y;	
	for (int i = s.size()-1; i >= 0; --i) {
		y.append(s,i,1);		
	}	
	if (s == y)		
		return true;
	else	
		return false;			
}

bool IsPalindrom(string s) {
	// Замечание: более правильным было бы использовать здесь тип size_t вместо int
	// О причинах Вы узнаете на Жёлтом поясе
	for (int i = 0; i < s.size() / 2; ++i) {
		if (s[i] != s[s.size() - i - 1]) {
			return false;
		}
	}
	return true;
}

/*int main() {
	string s;
	cin >> s;
	cout << IsPalindrom(x);
	return 0;
}*/