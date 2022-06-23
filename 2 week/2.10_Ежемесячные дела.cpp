#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<vector<string>> CM(31);
	int operations, i, k = 1;
	cin >> operations;
	string operation, delo;
	vector<int> DIM = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	//cout << days_in_months[0];
	while (operations != 0) {
		--operations;
		cin >> operation;
		if (operation == "ADD") {			
			cin >> i;
			--i;
			cin >> delo;
			CM[i].push_back(delo);
		}
		else if (operation == "NEXT") {			
			if (k == 12) {
				k = 0;
			}			
			if (CM.size() > DIM[k]) {
				for (int i = DIM[k]; i < CM.size(); ++i) {
					CM[DIM[k] - 1].insert(end(CM[DIM[k] - 1]), begin(CM[i]), end(CM[i]));
				}
			}
			CM.resize(DIM[k]);			
			++k;
		}
		else if (operation == "DUMP") {
			cin >> i;
			cout << CM[i - 1].size() << " ";
			for (auto s : CM[i - 1]) {
				cout << s << " ";
			}
			cout << endl;
		}
	}
	return 0;
}

/* 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ���������� (��������� �� ���� ���������) ���������
// ����� ������� �������� ����������_�������
const vector<int> MONTH_LENGTHS =
  {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int MONTH_COUNT = MONTH_LENGTHS.size();

int main() {
  int q;
  cin >> q;

  // ����� �������� ������ (�� 0 �� 11)
  int month = 0;

  // ������� ������ ������ ����� �����, ������ ���������� ���� � ������ ������;
  // ��� ���������� ������� �� ��������� �����, ������ ��� ��� ���������� ���
  vector<vector<string>> days_concerns(MONTH_LENGTHS[month]);

  for (int i = 0; i < q; ++i) {
    string operation_code;
    cin >> operation_code;

    if (operation_code == "ADD") {

      int day;
      string concern;
      cin >> day >> concern;
      --day;  // �������� ������� ���������� � ����
      days_concerns[day].push_back(concern);

    } else if (operation_code == "NEXT") {

      // ����� ��������� � ���������� ������ �������� ����� �����������
      // ��������� ��� ���������� �����������, ������ ��� ������ � �� ���������
      const int old_month_length = MONTH_LENGTHS[month];

      // ����� ������ ������ ����������� �� 1, �� ����� ������� ��� ������:
      // ��������, (5 + 1) % 12 = 6, �� (11 + 1) % 12 = 0
      month = (month + 1) % MONTH_COUNT;

      const int new_month_length = MONTH_LENGTHS[month];

      // ���� ����� ����� ������ �����������, ���������� ������� resize;
      // ����� ����� resize ���� ����������� ���� � �������� ��������� ����
      if (new_month_length < old_month_length) {

        // ����� ����������� ��������� ����� ���� � ��������� ���� ������ ������
        // ����� �� ������ ��������� ��� days_concerns[new_month_length - 1],
        // �������� ������ � ����� �������� ��������� ��� ����� �������
        vector<string>& last_day_concerns = days_concerns[new_month_length - 1];

        // ���������� ��� ������� ��� � ����� ������
        for (int day = new_month_length; day < old_month_length; ++day) {
          // �������� ������ days_concerns[day]
          // � ����� ������� last_day_concerns
          last_day_concerns.insert(
              end(last_day_concerns),
              begin(days_concerns[day]), end(days_concerns[day]));
        }
      }
      days_concerns.resize(new_month_length);

    } else if (operation_code == "DUMP") {

      int day;
      cin >> day;
      --day;

      // ������� ������ ��� � ���������� ���� � ������ �������
      cout << days_concerns[day].size() << " ";
      for (const string& concern : days_concerns[day]) {
        cout << concern << " ";
      }
      cout << endl;

    }
  }

  return 0;
}
*/