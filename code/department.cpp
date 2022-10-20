#include "department.h"

Department::Department(const char* name)
{
	strcpy(m_strName,name);
	m_iId = 0;
}

Department::~Department(void)
{
	
}

void Department::setId(int id)
{
	m_iId = id;
}

void Department::setName(char* name)
{
	strcpy(m_strName,name);
}

int Department::getId(void)
{
	return m_iId;
}

char* Department::getName(void)
{
	return m_strName;
}


ostream& operator<<(ostream& os,const Department& dep)
{
	os << dep.m_iId << ' ' << dep.m_strName << endl << dep.empArr.size() <<endl;
	vector<Employee>::const_iterator it;
	for(it=dep.empArr.begin(); it!=dep.empArr.end(); it++)
	{
		os << *it << endl;
	} 
	return os;
}

istream& operator>>(istream& is,Department& dep)
{
	int size;
	dep.empArr.clear();
	is >> dep.m_iId >> dep.m_strName >> size;
	Employee emp;
	for(int i=0; i<size; i++)
	{
		is >> emp;
		dep.empArr.push_back(emp);
	}
	return is;
}

