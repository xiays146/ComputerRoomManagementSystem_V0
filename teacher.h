#pragma once

#include "Identity.h"
using namespace std;

class Teacher : public Identity {
public:
	//����
	Teacher();
	Teacher(string inteacherID, string inname, string inpassword);

	//�˵�����
	virtual void openMenu();


	//����
	void showAllOrder();
	void dealOrder();
	string getID();
private:
	//ѧ���������ݣ�ѧ��
	string teacherID;
};