#include <iostream>
#include <algorithm>

using namespace std;

class Student {
public:
	string name;
	int score;
	Student ( string name, int score ) {
		this->name = name;
		this->score = score;
	}

	bool operator <( Student &student ) {
		return this->score < student.score;
	}

};

bool compare( int a, int b ) {
	return a > b;
}

void show(Student* students, int size) {

	for(int i = 0; i < size; i++) {
		cout << students[i].name << " ";
	}
	cout<<"\n";

	return;
}

int main() {

	Student students[] = {
		Student("전지호",10),
		Student("이진형",34),
		Student("최성욱",27),
		Student("정민환",35),
		Student("김민준",43)
	};
	const int size = sizeof(students) / sizeof(Student);

	sort(students, students + size);
	show(students, size);

	return 0;
}