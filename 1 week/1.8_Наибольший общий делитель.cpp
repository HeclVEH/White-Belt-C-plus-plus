#include <iostream>
#include <algorithm>
#include <conio.h>

using namespace std;

int main() {
	int a, b ;
	cin >> a >> b;
	// cout << a % b;
	/* if (min(a,b) == 0) {
		cout << max(a,b);
	}
	else {
		for (int i = abs(min(a,b)); i > 0; --i) {
			if (min(a,b) % i == 0 && max(a, b) % i == 0) {				
				cout << i;
				break;				
			}
			--i;
		}
	} */
	while (a > 0 && b > 0) {
		if (a >= b) {
			a %= b;
		}
		else {
			b %= a;
		}
	}
	cout << a + b;
	return 0;	
}