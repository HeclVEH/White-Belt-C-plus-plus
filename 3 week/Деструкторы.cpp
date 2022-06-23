#include <string>
#include <vector>
#include <iostream>

using namespace std;

int ComputeDistance(const string& source, const string& destination) {
	return source.length() - destination.length();
}

class Route {
public:
	Route() {
		source = "Moscow";
		destination = "Saint Peterburg";
		UpdateLength();
		cout << "Default constructed\n";
	}
	Route(const string& new_source, const string& new_destination) {
		source = new_source;
		destination = new_destination;
		UpdateLength();
		cout << "Constructed\n";
	}
	~Route() {
		/*for (const string& entry : compute_distance_log) {
			cout << entry << endl;
		} */
		cout << "Destructed\n";
	}
	string GetSource() const {
		return source;
	}
	string GetDestination() const {
		return destination;
	}
	int GetLength() const {
		return length;
	}
	void SetSource(const string& new_source) {
		source = new_source;
		UpdateLength();
	}
	void SetDestination(const string& new_destination) {
		destination = new_destination;
		UpdateLength();
	}

private:
	void UpdateLength() {
		length = ComputeDistance(source, destination);
		compute_distance_log.push_back(
			source + " - " + destination);
	}
	string source;
	string destination;
	int length;
	vector<string> compute_distance_log;
};

Route GetRoute() {
	cout << 1 << "\n";
	return {};
}

int main() {
	GetRoute();
	cout << 2 << "\n";
	return 0;
}

/*
int main() {
	cout << 1 << "\n";
	Route first_route;
	if (false) {
		cout << 2 << "\n";
		return 0;
	}
	cout << 3 << "\n";
	Route second_route;
	cout << 4 << "\n";
	return 0;
}
/*
int main() {
	cout << 1 << endl;
	Route route;
	cout << 2 << endl;
	//Route route("Moscow", "Saint Peterburg");
	//route.SetSource("Vyborg");
	//route.SetDestination("Vologda");
	return 0;
} */