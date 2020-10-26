#pragma once

#include "Identity.h"
using namespace std;

class Teacher : public Identity {
public:
	//构造
	Teacher();
	Teacher(string inteacherID, string inname, string inpassword);

	//菜单界面
	virtual void openMenu();


	//功能
	void showAllOrder();
	void dealOrder();
	string getID();
private:
	//学生特有数据：学号
	string teacherID;
};