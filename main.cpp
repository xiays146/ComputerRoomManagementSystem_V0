#include "mianFunction.h"

int main() {
	
	int select;//�û�ѡ��

	while (true){
	cout << "\t+---------------------------+\n";
	cout << "\t|     1.ѧ  ��              |\n";
	cout << "\t|     2.��  ʦ              |\n";
	cout << "\t|     3.����Ա              |\n";
	cout << "\t|     0.��  ��              |\n";
	cout << "\t+---------------------------+\n";
	cout << "����ѡ��";

	cin >> select;

	switch (select)
	{
	case 1://ѧ��
		LogIn(STUDENT_FILE, 1);
		break;
	case 2://��ʦ
		LogIn(TEACHER_FILE, 2);
		break;
	case 3://����Ա
		LogIn(ADMIN_FILE, 3);
		break;
	case 0:
		printMessage("�˳��ɹ���");
		return 0;
		
	default:
		printMessage("�Ƿ����룡");
		break;
	}
	}

	system("pause");
	return 0;
}