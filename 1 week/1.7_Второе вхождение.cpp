#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int result = -2;     // ������� �����
                        // ���� f �� ���� �� ����������, �� ��������� ������ -2
    for (int i = 0; i < s.size(); ++i) {
        // ���� ������� ������ ����� f, ������� ������� �����
        if (s[i] == 'f') {
            // ���� �� ����� �� ���� �� ������ ���������, ������, ������ ����� ������
            if (result == -2) {
                result = -1;  // ������ ��������� ����� ����
              // �� ����� ���� ����� ���� ��������� ? ������ ��� ��� ������  
            }
            else if (result == -1) {
                result = i;
                break;  // ���� ����� ���������, ������ ��� ����� ��� ������
            }

        }
    }
    cout << result;
    return 0;
}
int main() {
	string a;
	int b = 0, i = 0;
	cin >> a;
	for (auto c : a) {
		if (c == 'f') {
			++b;
		}		
		if (b == 2) {
			cout << i;
			break;
		}
		++i;
	}
	// cout << b;
	if (b == 0) {
		cout << "-2";
	}
	else if (b == 1) {
		cout << "-1";
	}	
	return 0;
}