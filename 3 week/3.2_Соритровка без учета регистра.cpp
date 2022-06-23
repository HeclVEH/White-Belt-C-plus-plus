#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void PrintVec(const vector<string>& x/*, const string& title*/) {
	//cout << title << ": ";
	for (const auto& i : x) {
		cout << i << ' ';
	}
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	if (n < 0 || n > 1000) {
		cout << "Out of range";
	}
	else {
		vector<string> N(n);
		for (auto& i : N) {
			cin >> i;
		}
		//PrintVec(N, "Input");		
		sort(begin(N), end(N), [](string x, string y) {
			for (char& i : x) {
				i = tolower(i);
			}
			for (char& i : y) {
				i = tolower(i);
			}			
			return (x < y); 
			}
		);
		PrintVec(N);
	}
	return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// ��������� ������ �����
	int n;
	cin >> n;
	vector<string> v(n);
	for (string& s : v) {
		cin >> s;
	}

	// ���������
	sort(begin(v), end(v),
		// ���������� ��� ���������� � ������-�������, ������������ ������ ��� ����� ��������
		[](const string& l, const string& r) {
			// ���������� �����������������...
			return lexicographical_compare(
				// ... ��� ������� ������ l ...
				begin(l), end(l),
				// ... �� ����� ��������� ������ r ...
				begin(r), end(r),
				// ..., ��������� � �������� ����������� ��������� ��������� �������� ��� ����� ��������
				[](char cl, char cr) { return tolower(cl) < tolower(cr); }
			);
		}
	);

	// ������� ��������������� ������
	for (const string& s : v) {
		cout << s << ' ';
	}

	return 0;
}