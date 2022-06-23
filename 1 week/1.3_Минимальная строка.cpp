#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<string> a(3);
	cin >> a[0] >> a[1] >> a[2];
	sort(begin(a), end(a));
	cout << a[0];
	return 0;
}