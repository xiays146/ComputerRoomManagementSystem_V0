#pragma once

#include "Identity.h"
using namespace std;

class Student : public Identity {
public:
	//����
	Student();
	Student(string instudentID, string inname, string inpassword);

	//�˵�����
	virtual void openMenu();


	//����
	void applyOrder();
	void showMyOrder();
	void showAllOrder();
	void cancelMyOrder();
	string getID();
private:
	//ѧ���������ݣ�ѧ��
	string studentID;
};