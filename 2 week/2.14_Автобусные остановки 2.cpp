#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	map <vector<string>, int> A;	
	int q, qc, j = 1;	
	vector<string> tmp;
	string stop;
	cin >> q;
	for (int i = 0; i < q; ++i) {		
		cin >> qc;
		for (int i = 0; i < qc; ++i) {			
			cin >> stop;
			tmp.push_back(stop);
		}		
		if (A.find(tmp) != A.end()) {
			cout << "Already exists for " << A[tmp] << endl;
		}
		else {			
			A[tmp] = j;
			cout << "New bus " << A[tmp] << endl;			
			++j;
		}
		tmp.clear();
	}
	return 0;
}