#pragma once //��ֹͷ�ļ����ظ�����

#include <string>
using namespace std;

//��ݵĳ������
class Identity {
public:

	//�麯����ʵ�ֶ�̬
	//������=0�����߱��������Ǵ��麯��
	virtual void openMenu() = 0;


	//�û���
	string name;
	//����
	string password;


};
