#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
	int N = 0, M = 0, value;
	ifstream input("input.txt");	
	if (input) {
		input >> N;
		input >> M;		
		for (int i = 0; i < N; ++i) {
			for (int i = 0; i < M; ++i) {				
				input >> value;
				input.ignore(1);
				cout << setw(10) << value;
				if (i != M - 1) {
					cout << " ";
				}
			}
			if (i != N - 1) {
				cout << endl;
			}
		}
	}
	return 0;
}

/*


using namespace std;

int main() {
	ifstream input("input.txt");

	double a;

	cout << fixed << setprecision(3);

	while (input >> a) {
		cout << a << endl;
	}

	return 0;
}
*/