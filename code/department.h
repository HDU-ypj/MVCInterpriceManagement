#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "employee.h"

class Department
{
public:
	Department(const char* name="");
	~Department(void);
	void setId(int id);
	void setName(char* name);
	int getId(void);
	char* getName(void);

	friend ostream& operator<<(ostream& os,const Department& dep);
	friend istream& operator>>(istream& is,Department& dep);

	vector<Employee> empArr;

private:
	int m_iId;
	char m_strName[20];

};
#endif//DEPARTMENT_H
