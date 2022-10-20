#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "tools.h"

//员工对象模型

class Employee
{
public:
	Employee(const char* name="",char sex='m',int age=0,int id=0);
	void setId(int id);
	void setAge(int age);
	void setName(const char* name);
	void setSex(char sex);
	int getId(void);
	int getAge(void);
	char* getName(void);
	char getSex(void);

	friend ostream& operator<<(ostream& os,const Employee& emp);
	friend istream& operator>>(istream& is,Employee& emp);

private:
	int m_iId;
	int m_iAge;
	char m_strName[20];
	char m_cSex;
};
#endif//EMPLOYEE_H
