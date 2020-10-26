#include "mianFunction.h"

void adminMenu(Identity* admin) {
	while (true) {
		//转换为子类指针
		Admin* subAdmin = (Admin*)admin;
		//show menu，使用父类指针
		subAdmin->openMenu();

		//接受用户输入
		int select;
		cout << "请输入你的选择：" << endl;
		cin >> select;

		if (select == 1) {//添加账号
			cout << "添加账号" << endl;
			subAdmin->addPerson();
		}
		else if (select == 2) {//查看账号
			cout << "查看账号" << endl;
			subAdmin->showPerson();
		}
		else if (select == 3) { //查看机房
			cout << "查看机房" << endl;
			subAdmin->showComputer();
		}
		else if (select == 4) {//清空预约
			cout << "清空预约" << endl;
			subAdmin->clearFile();
		}
		else {//注销登陆
			delete admin;
			cout << "注销登陆" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


void LogIn(string idengtityFile, int type) {

	//读文件
	ifstream ifs;//打开文件
	ifs.open(idengtityFile, ios::in);

	//打开失败
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//正常打开文件
	//接收用户输入信息
	string id;
	string name;
	string password;
	cout << "输入你的姓名：" << endl;
	cin >> name;
	cout << "输入你的密码：" << endl;
	cin >> password;

	if (type == 1) {//学生
		cout << "输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2) {//学生
		cout << "输入你的职工号：" << endl;
		cin >> id;
	}

	//开始在文件中查找信息和验证登陆
	Identity* person = NULL;
	if (type == 1) {
		//验证学生登陆
		string fId, fName, fPassword;
		while (ifs >> fId && ifs >> fName && ifs >> fPassword) {
			if (fId == id && fName == name && fPassword == password) {
				person = new Student(id, name, password);
				printMessage("学生验证登陆成功！");
				//进入学生子菜单界面

				return;
			}
		}
	}
	else if (type == 2) {
		//验证教师登陆
		string fId, fName, fPassword;
		while (ifs >> fId && ifs >> fName && ifs >> fPassword) {
			if (fId == id && fName == name && fPassword == password) {
				person = new Teacher(id, name, password);
				printMessage("教师验证登陆成功！");
				//进入教师子菜单界面

				return;
			}
		}
	}
	else if (type == 3) {
		//验证管理员登陆
		string fName, fPassword;
		while (ifs >> fName && ifs >> fPassword) {
			if (fName == name && fPassword == password) {
				printMessage("管理员验证登陆成功！");
				//进入管理员子菜单界面
				person = new Admin(name, password);
				adminMenu(person);
				return;
			}
		}
	}

	//验证失败，输出错误信息
	printMessage("验证失败！");
	return;
}

void printMessage(const string& s) {
	cout << s << endl;
	system("pause");
	system("cls");
}