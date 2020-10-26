#pragma once

#include "Identity.h"
using namespace std;

class Student : public Identity {
public:
	//构造
	Student();
	Student(string instudentID, string inname, string inpassword);

	//菜单界面
	virtual void openMenu();


	//功能
	void applyOrder();
	void showMyOrder();
	void showAllOrder();
	void cancelMyOrder();
	string getID();
private:
	//学生特有数据：学号
	string studentID;
};