#pragma once
#include <vector>
#include "globalFile.h"
#include "Identity.h"
#include "student.h"
#include "teacher.h"
using namespace std;

class Admin : public Identity {
public:
	//����
	Admin();
	Admin(string name, string password);

	//�˵�����
	virtual void openMenu();

	//����
	void addPerson();
	void showPerson();
	void showComputer();
	void clearFile();
	void initVector();
	bool checkRepeat(string id, int type);

private:
	vector<Student> vStudent;
	vector<Teacher> vTeacher;

};