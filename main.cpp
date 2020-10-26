#include "mianFunction.h"

int main() {
	
	int select;//用户选择

	while (true){
	cout << "\t+---------------------------+\n";
	cout << "\t|     1.学  生              |\n";
	cout << "\t|     2.老  师              |\n";
	cout << "\t|     3.管理员              |\n";
	cout << "\t|     0.退  出              |\n";
	cout << "\t+---------------------------+\n";
	cout << "输入选择：";

	cin >> select;

	switch (select)
	{
	case 1://学生
		LogIn(STUDENT_FILE, 1);
		break;
	case 2://老师
		LogIn(TEACHER_FILE, 2);
		break;
	case 3://管理员
		LogIn(ADMIN_FILE, 3);
		break;
	case 0:
		printMessage("退出成功！");
		return 0;
		
	default:
		printMessage("非法输入！");
		break;
	}
	}

	system("pause");
	return 0;
}