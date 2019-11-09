#include "structures.h"
#include <fstream>
/*
Write a program to read a list of students from a file and create a list.The program should
use a linked list for implementation. Each node in the linked list should have the student’s
name, a pointer to the next student, and a pointer to a linked list of scores.There may be
up to four scores for each student
*/

#define FILENAME "students.txt"

class student {
public:
	std::string name;
	linkedList<int> grades;

	std::ostream& print(std::ostream& os) const {
		os << "Name: " << name << "\n";
		os << "Grades:\n" << grades.toString();
		return os;
	}

};
std::ostream& operator<<(std::ostream& os, student& obj) {
	return obj.print(os);
}


int main() {
	linkedList<student> list;
	std::string n;
	int g;
	std::ifstream fin(FILENAME);

	//put all students to the list
	while (getline(fin, n)) {
		student st;
		st.name = n;
		while (getline(fin, n) && n != "") {
			g = std::stoi(n);
			st.grades.pushBack(g);
		}
		list.pushBack(st);
	}
	fin.close();

	//print from the list
	student temp = list.at(1);
	for (int i = 0; temp.name != list.at(i).name; i++) {
		temp = list.at(i);
		std::cout << temp;
	}

	std::cin.get();
}
