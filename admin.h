#pragma once
#include <vector>
#include "globalFile.h"
#include "Identity.h"
#include "student.h"
#include "teacher.h"
using namespace std;

class Admin : public Identity {
public:
	//构造
	Admin();
	Admin(string name, string password);

	//菜单界面
	virtual void openMenu();

	//功能
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