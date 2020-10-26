#include "teacher.h"
using namespace std;

Teacher::Teacher() {}
Teacher::Teacher(string inteacherID, string inname, string inpassword) {
	teacherID = inteacherID;
	name = inname;
	password = inpassword;
}
void Teacher::openMenu() {}
void Teacher::showAllOrder() {}
void Teacher::dealOrder() {}
string Teacher::getID() {
	return teacherID;
}