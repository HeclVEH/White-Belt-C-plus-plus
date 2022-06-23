#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a, b, c, D;
	cin >> a >> b >> c;
	D = pow(b, 2) - 4 * a * c;
	if (a == 0) {
		if (b !=0) {
			cout << -1*( c / b);
		}
	}
	else if (D == 0) {
		cout << -b / (2 * a);
	}		
	else if (D > 0) {		
			cout << (-b + sqrt(D)) / (2 * a) << " ";
			cout << (-b - sqrt(D)) / (2 * a);
	}	
	return 0;
}