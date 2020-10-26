#include "admin.h"
#include "mianFunction.h"
Admin::Admin() {}
Admin::Admin(string name, string password) {
	name = name;
	password = password;
	initVector();
}

//菜单界面
void Admin::openMenu() {
	cout << "\t+----------------+\n";
	cout << "\t|  1.添加账号    |\n";
	cout << "\t|  2.查看账号    |\n";
	cout << "\t|  3.查看机房    |\n";
	cout << "\t|  4.清空预约    |\n";
	cout << "\t|  0.注销登陆    |\n";
	cout << "\t+----------------+\n";
}

//功能
void Admin::addPerson() {

	cout << "情输入你添加的类型：" << endl;
	cout << "1.学生账户；" << endl;
	cout << "2.教师账户；" << endl;

	//用户做选择
	int select;
	cin >> select;

	//接受用户输入
	string name;
	string pwd;
	string id;
	string file;

	if (select == 1) {
		cout << "学生号：\n";
		cin >> id;
		while (checkRepeat(id, select)) {//输入与现有id重复
			cout << "输入学生号重复！请重新输入..." << endl;
			cin >> id;
		}
		file = STUDENT_FILE;
	}
	else if (select == 2) {
		cout << "教职工号：\n";
		cin >> id;
		while (checkRepeat(id, select)) {//输入与现有id重复
			cout << "输入教职工号重复！请重新输入..." << endl;
			cin >> id;
		}
		file = TEACHER_FILE;
	}
	cout << "姓名：\n";
	cin >> name;
	cout << "密码：\n";
	cin >> pwd;

	//存储数据
	ofstream ofs;
	ofs.open(file, ios::out | ios::app);
	ofs << id << " " << name << " " << pwd << endl;
	ofs.close();
	printMessage("添加成功！");

	//添加成功后，调用容器初始化更新添加的数据
	initVector();

}

void Admin::showPerson() {
	cout << "请选择查看的内容：" << endl;
	cout << "1.所有学生账户信息；" << endl;
	cout << "2.所有教师账户信息；" << endl;

	int select = 0;
	cin >> select;
	if (select == 1) {
		//show student 
		cout << "学生账号信息如下：" << endl;
		for (auto it = vStudent.begin(); it != vStudent.end(); it++) 
			cout << "学生ID：" << it->getID() << "； 账户姓名：" << it->name << "； 账户密码：" << it->password << endl;
	}
	else {
		//show teacher
		cout << "教师账号信息如下：" << endl;
		for (auto it = vTeacher.begin(); it != vTeacher.end(); it++)
			cout << "职工ID：" << it->getID() << "； 账户姓名：" << it->name << "； 账户密码：" << it->password << endl;
	}
}
void Admin::showComputer() {}
void Admin::clearFile() {}
void Admin::initVector() {
	ifstream ifs;

	vStudent.clear();
	ifs.open(STUDENT_FILE, ios::in);

	if (!ifs.is_open()) {
		printMessage("文件打开失败！");
		return;
	}
	//Student stu;
	string id, name, pwd;
	while (ifs >> id && ifs >> name && ifs >> pwd) {
		Student stu = Student(id, name, pwd);
		vStudent.push_back(stu);
	}
	cout << "当前学生数量为：" << vStudent.size() << endl;
	ifs.close();

	vTeacher.clear();
	ifs.open(TEACHER_FILE, ios::in);

	if (!ifs.is_open()) {
		printMessage("文件打开失败！");
		return;
	}
	 
	//string id, name, pwd;
	while (ifs >> id && ifs >> name && ifs >> pwd) {
		Teacher teacher = Teacher(id, name, pwd);
		vTeacher.push_back(teacher);
	}
	cout << "当前教师数量为：" << vTeacher.size() << endl;
	ifs.close();

}
bool Admin::checkRepeat(string id, int type) {
	if (type == 1) {//检测学生id
		for (auto it = vStudent.begin(); it != vStudent.end(); it++) {
			if (it->getID() == id)
				return true;
		}
	}
	else {//检测教师id
		for (auto it = vTeacher.begin(); it != vTeacher.end(); it++) {
			if (it->getID() == id)
				return true;
		}
	}
	return false;
}