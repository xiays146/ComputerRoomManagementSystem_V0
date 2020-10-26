#pragma once //防止头文件的重复包含

#include <string>
using namespace std;

//身份的抽象基类
class Identity {
public:

	//虚函数，实现多态
	//必须有=0，告诉编译器这是纯虚函数
	virtual void openMenu() = 0;


	//用户名
	string name;
	//密码
	string password;


};
