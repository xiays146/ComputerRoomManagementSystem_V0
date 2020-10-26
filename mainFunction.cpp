#include "mianFunction.h"

void adminMenu(Identity* admin) {
	while (true) {
		//ת��Ϊ����ָ��
		Admin* subAdmin = (Admin*)admin;
		//show menu��ʹ�ø���ָ��
		subAdmin->openMenu();

		//�����û�����
		int select;
		cout << "���������ѡ��" << endl;
		cin >> select;

		if (select == 1) {//����˺�
			cout << "����˺�" << endl;
			subAdmin->addPerson();
		}
		else if (select == 2) {//�鿴�˺�
			cout << "�鿴�˺�" << endl;
			subAdmin->showPerson();
		}
		else if (select == 3) { //�鿴����
			cout << "�鿴����" << endl;
			subAdmin->showComputer();
		}
		else if (select == 4) {//���ԤԼ
			cout << "���ԤԼ" << endl;
			subAdmin->clearFile();
		}
		else {//ע����½
			delete admin;
			cout << "ע����½" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


void LogIn(string idengtityFile, int type) {

	//���ļ�
	ifstream ifs;//���ļ�
	ifs.open(idengtityFile, ios::in);

	//��ʧ��
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//�������ļ�
	//�����û�������Ϣ
	string id;
	string name;
	string password;
	cout << "�������������" << endl;
	cin >> name;
	cout << "����������룺" << endl;
	cin >> password;

	if (type == 1) {//ѧ��
		cout << "�������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2) {//ѧ��
		cout << "�������ְ���ţ�" << endl;
		cin >> id;
	}

	//��ʼ���ļ��в�����Ϣ����֤��½
	Identity* person = NULL;
	if (type == 1) {
		//��֤ѧ����½
		string fId, fName, fPassword;
		while (ifs >> fId && ifs >> fName && ifs >> fPassword) {
			if (fId == id && fName == name && fPassword == password) {
				person = new Student(id, name, password);
				printMessage("ѧ����֤��½�ɹ���");
				//����ѧ���Ӳ˵�����

				return;
			}
		}
	}
	else if (type == 2) {
		//��֤��ʦ��½
		string fId, fName, fPassword;
		while (ifs >> fId && ifs >> fName && ifs >> fPassword) {
			if (fId == id && fName == name && fPassword == password) {
				person = new Teacher(id, name, password);
				printMessage("��ʦ��֤��½�ɹ���");
				//�����ʦ�Ӳ˵�����

				return;
			}
		}
	}
	else if (type == 3) {
		//��֤����Ա��½
		string fName, fPassword;
		while (ifs >> fName && ifs >> fPassword) {
			if (fName == name && fPassword == password) {
				printMessage("����Ա��֤��½�ɹ���");
				//�������Ա�Ӳ˵�����
				person = new Admin(name, password);
				adminMenu(person);
				return;
			}
		}
	}

	//��֤ʧ�ܣ����������Ϣ
	printMessage("��֤ʧ�ܣ�");
	return;
}

void printMessage(const string& s) {
	cout << s << endl;
	system("pause");
	system("cls");
}