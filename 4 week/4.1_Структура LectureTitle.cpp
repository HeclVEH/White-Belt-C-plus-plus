#include <string>

using namespace std;

struct Specialization {
	string str;
	explicit Specialization(const string& value) {
		str = value;
	}
};

struct Course {
	string str;
	explicit Course(const string& value) {
		str = value;
	}
};

struct Week {
	string str;
	explicit Week(const string& value) {
		str = value;
	}
};

struct LectureTitle {
	string specialization;
	string course;
	string week;
	LectureTitle(const Specialization& spec,
				 const Course& cour,
			     const Week& wk) {
		specialization = spec.str;
		course = cour.str;
		week = wk.str;
	}
};

int main() {
	LectureTitle title(Specialization("C++"),Course("White belt"),Week("4th"));
	return 0;
}