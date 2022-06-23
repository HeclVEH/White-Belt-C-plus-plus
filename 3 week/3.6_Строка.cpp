#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class ReversibleString {
public:
	ReversibleString() {};
	ReversibleString(const string& s) {
		tmp = s;
	};
	void Reverse() {
		reverse(begin(tmp),end(tmp));
	}
	string ToString() const{
		return tmp;
	}
private:
	string tmp;
};

int main() {
	ReversibleString s("live");
	ReversibleString t("SHIT");

	s.Reverse();
	cout << s.ToString() << endl;
	t.Reverse();
	cout << t.ToString() << endl;

	s.Reverse();
	const ReversibleString& s_ref = s;
	string tmp = s_ref.ToString();
	cout << tmp << endl;

	ReversibleString empty;
	cout << '"' << empty.ToString() << '"' << endl;

	return 0;
}
