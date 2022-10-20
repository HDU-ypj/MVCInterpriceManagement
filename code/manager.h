#ifndef MANAGER_H
#define MANAGER_H

//这里采用了直接导入全部头文件的方式，尤其导入了命名空间std，
//在实际开发过程中，应当尽量避免在头文件中导入命名空间对原有命名空间造成污染
//这里直接导入了相关的头文件也是不太合理的，鉴于个人精力有限，就从简处理

#include "tools.h"

class Manager
{
	int m_iId;
	char m_strName[20];
	char m_strPwd[20];
public:
	Manager(const char* name="",const char* pwd="123");
	int getId(void)const;
	const char* getName(void)const;
	const char* getPwd(void)const;
	void setId(int id);
	void setName(const char* name);
	void setPwd(const char* pwd);
	friend ostream& operator<<(ostream& os,const Manager& mgr);
	friend istream& operator>>(istream& is,Manager& mgr);
};
#endif
