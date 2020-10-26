#include "admin.h"
#include "mianFunction.h"
Admin::Admin() {}
Admin::Admin(string name, string password) {
	name = name;
	password = password;
	initVector();
}

//�˵�����
void Admin::openMenu() {
	cout << "\t+----------------+\n";
	cout << "\t|  1.����˺�    |\n";
	cout << "\t|  2.�鿴�˺�    |\n";
	cout << "\t|  3.�鿴����    |\n";
	cout << "\t|  4.���ԤԼ    |\n";
	cout << "\t|  0.ע����½    |\n";
	cout << "\t+----------------+\n";
}

//����
void Admin::addPerson() {

	cout << "����������ӵ����ͣ�" << endl;
	cout << "1.ѧ���˻���" << endl;
	cout << "2.��ʦ�˻���" << endl;

	//�û���ѡ��
	int select;
	cin >> select;

	//�����û�����
	string name;
	string pwd;
	string id;
	string file;

	if (select == 1) {
		cout << "ѧ���ţ�\n";
		cin >> id;
		while (checkRepeat(id, select)) {//����������id�ظ�
			cout << "����ѧ�����ظ�������������..." << endl;
			cin >> id;
		}
		file = STUDENT_FILE;
	}
	else if (select == 2) {
		cout << "��ְ���ţ�\n";
		cin >> id;
		while (checkRepeat(id, select)) {//����������id�ظ�
			cout << "�����ְ�����ظ�������������..." << endl;
			cin >> id;
		}
		file = TEACHER_FILE;
	}
	cout << "������\n";
	cin >> name;
	cout << "���룺\n";
	cin >> pwd;

	//�洢����
	ofstream ofs;
	ofs.open(file, ios::out | ios::app);
	ofs << id << " " << name << " " << pwd << endl;
	ofs.close();
	printMessage("��ӳɹ���");

	//��ӳɹ��󣬵���������ʼ��������ӵ�����
	initVector();

}

void Admin::showPerson() {
	cout << "��ѡ��鿴�����ݣ�" << endl;
	cout << "1.����ѧ���˻���Ϣ��" << endl;
	cout << "2.���н�ʦ�˻���Ϣ��" << endl;

	int select = 0;
	cin >> select;
	if (select == 1) {
		//show student 
		cout << "ѧ���˺���Ϣ���£�" << endl;
		for (auto it = vStudent.begin(); it != vStudent.end(); it++) 
			cout << "ѧ��ID��" << it->getID() << "�� �˻�������" << it->name << "�� �˻����룺" << it->password << endl;
	}
	else {
		//show teacher
		cout << "��ʦ�˺���Ϣ���£�" << endl;
		for (auto it = vTeacher.begin(); it != vTeacher.end(); it++)
			cout << "ְ��ID��" << it->getID() << "�� �˻�������" << it->name << "�� �˻����룺" << it->password << endl;
	}
}
void Admin::showComputer() {}
void Admin::clearFile() {}
void Admin::initVector() {
	ifstream ifs;

	vStudent.clear();
	ifs.open(STUDENT_FILE, ios::in);

	if (!ifs.is_open()) {
		printMessage("�ļ���ʧ�ܣ�");
		return;
	}
	//Student stu;
	string id, name, pwd;
	while (ifs >> id && ifs >> name && ifs >> pwd) {
		Student stu = Student(id, name, pwd);
		vStudent.push_back(stu);
	}
	cout << "��ǰѧ������Ϊ��" << vStudent.size() << endl;
	ifs.close();

	vTeacher.clear();
	ifs.open(TEACHER_FILE, ios::in);

	if (!ifs.is_open()) {
		printMessage("�ļ���ʧ�ܣ�");
		return;
	}
	 
	//string id, name, pwd;
	while (ifs >> id && ifs >> name && ifs >> pwd) {
		Teacher teacher = Teacher(id, name, pwd);
		vTeacher.push_back(teacher);
	}
	cout << "��ǰ��ʦ����Ϊ��" << vTeacher.size() << endl;
	ifs.close();

}
bool Admin::checkRepeat(string id, int type) {
	if (type == 1) {//���ѧ��id
		for (auto it = vStudent.begin(); it != vStudent.end(); it++) {
			if (it->getID() == id)
				return true;
		}
	}
	else {//����ʦid
		for (auto it = vTeacher.begin(); it != vTeacher.end(); it++) {
			if (it->getID() == id)
				return true;
		}
	}
	return false;
}