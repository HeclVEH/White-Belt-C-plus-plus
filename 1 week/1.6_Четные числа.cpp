#include <iostream>
using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	if (A <= B && A >= 1 && B <= 30000) {
		do {
			if (A % 2 == 0) {
				cout << A << " ";
			}
			A += 1;
		} while (A != B+1);
	}
	else {
		cout << "Wrong, it's out of range!";
	}
	return 0;
}