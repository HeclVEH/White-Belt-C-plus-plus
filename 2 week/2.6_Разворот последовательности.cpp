#include <iostream>
#include <vector>
#include <chrono>
#include <functional>
using namespace std;
using namespace std::chrono;

void Reverse(vector<int>& x) {
	vector<int> tmp = x;
	for (size_t i = 0; i < x.size(); ++i) {
		x[i] = tmp[x.size() - i - 1];
		// cout << x[i] << " ";
	}
}

void Reverse1(vector<int>& v) {
	int n = v.size();  // для удобства сохраним размер вектора в переменную n
	for (int i = 0; i < n / 2; ++i) {
		// элемент с индексом i симметричен элементу с индексом n - 1 - i
		// поменяем их местами с помощью временной переменной tmp
		int tmp = v[i];
		v[i] = v[n - 1 - i];
		v[n - 1 - i] = tmp;
	}	
}

template<typename Func, typename arg>
void Checker(Func func1, Func func2, arg& x) {
	auto start1 = steady_clock::now();
	func1(x);
	auto finish1 = steady_clock::now();
	cout << "Your function takes " << duration_cast<microseconds>(finish1 - start1).count()
		<< " microseconds to work." << endl;
	auto start2 = steady_clock::now();
	func2(x);
	auto finish2 = steady_clock::now();
	cout << "The foreign function takes " << duration_cast<microseconds>(finish2 - start2).count()
		<< " microseconds to work." << endl;
	if ((finish1 - start1) > (finish2 - start2))
		cout << endl << "It's so long time, man!" << endl;
	else
		cout << endl << "Good job, man!" << endl;
}


/*template<typename T1, typename T2>
void Fun(T1 myfunction(*f1)(vector<int>), T2 forfunction(*f2)(vector<int>), vector<int>& v) {
	auto start1 = steady_clock::now();
	(*f1)(v);
	auto finish1 = steady_clock::now();
	cout << "Your function takes " << duration_cast<nanoseconds>(finish1 - start1).count()
		<< " microseconds to work." << endl;
	auto start2 = steady_clock::now();
	(*f2)(v);
	auto finish2 = steady_clock::now();
	cout << "The foreign function takes " << duration_cast<nanoseconds>(finish2 - start2).count()
		<< " microseconds to work." << endl;
	if ((finish1 - start1) > (finish2 - start2))
		cout << endl << "It's so long time, man!" << endl;
	else
		cout << endl << "Good job, man!" << endl;
}*/

int main() {
	vector<int> v = { 1, 5, 3, 4, 2 };
	//for (int i = 0; i < 11500; ++i) {
		//v.push_back(i);
	//}
	/*auto start1 = steady_clock::now();
	Reverse(v);
	auto finish1 = steady_clock::now();
	cout << "Your function takes " << duration_cast<microseconds>(finish1 - start1).count() 
		<< " microseconds to work." << endl;
	auto start2 = steady_clock::now();
	Reverse1(v);
	auto finish2 = steady_clock::now();
	cout << "The foreign function takes " << duration_cast<microseconds>(finish2 - start2).count() 
		<< " microseconds to work." << endl;
	 */
	Checker(Reverse, Reverse1, v);
	return 0;
}