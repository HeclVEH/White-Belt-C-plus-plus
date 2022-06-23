#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> quantity;
	vector<bool> people(false);
	int operations;
	cin >> operations;
	string operation;
	int i;
	while (operations != 0) {
		--operations;
		cin >> operation;
		if (operation == "WORRY_COUNT") {
			i = 0;
			for (auto j : people) {
				if (j == true) {
					++i;
				}
			}
			quantity.push_back(i);
		}
		else if (operation == "COME") {
			cin >> i;
			if (i > 0) {
				people.resize(people.size() + i);
			}
			else {
				if (people.size() > 0) {
					if (-i <= people.size()) {
						people.resize(people.size() + i);
					}
					else {
						people.assign(0,false);
					}
				}					
			}					
		}
		else if (operation == "WORRY") {
			cin >> i;
			people[i] = true;
		}
		else if (operation == "QUIET") {
			cin >> i;
			people[i] = false;
		}
	}
	for (auto k : quantity) {
		cout << k << endl;
	}	
	return 0;
}

/*int main() {
	int q;
	cin >> q;
	vector<bool> is_nervous;

	for (int i = 0; i < q; ++i) {
		string operation_code;
		cin >> operation_code;

		if (operation_code == "WORRY_COUNT") {

			// ������������ ���������� ��������� � ������� is_nervous, ������ true
			cout << count(begin(is_nervous), end(is_nervous), true) << endl;

		}
		else {
			if (operation_code == "WORRY" || operation_code == "QUIET") {

				int person_index;
				cin >> person_index;

				// ��������� � ������� ����� ��� bool � ����� true ��� ������� WORRY,
				// ������� is_nervous[person_index] ������ ������ false ��� true
				// � ����������� �� operation_code
				is_nervous[person_index] = (operation_code == "WORRY");

			}
			else if (operation_code == "COME") {

				int person_count;
				cin >> person_count;

				// ����� resize ����� ��� ��������� ������ �������, ��� � �����������,
				// ������� ���������� ������������� ������ � �������������
				// � ������������� person_count �� �����
				is_nervous.resize(is_nervous.size() + person_count, false);

			}
		}
	}

	return 0;
} */