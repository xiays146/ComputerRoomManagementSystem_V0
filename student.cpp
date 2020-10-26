#include <iostream>
#include "student.h"
using namespace std;

Student::Student() {}
Student::Student(string instudentID, string inname, string inpassword) {
	studentID = instudentID;
	name = inname;
	password = inpassword;
}

void Student::openMenu() {
	
}
void Student::applyOrder() {}
void Student::showMyOrder() {}
void Student::showAllOrder() {}
void Student::cancelMyOrder() {}
string Student::getID() {
	return studentID;
}