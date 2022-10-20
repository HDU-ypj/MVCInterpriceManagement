#include "service_ctrl_impl.h"

ServiceCtrlImpl::ServiceCtrlImpl(void)
{
	srcMode = new ServiceModeImpl;
	srcMode->load(deptArr);
}

ServiceCtrlImpl::~ServiceCtrlImpl(void)
{
	srcMode->save(deptArr);
	delete srcMode;
}

bool ServiceCtrlImpl::addDept(Department& dep)
{
	//如果有相同的部门已经存在那么添加失败
	vector<Department>::iterator it;
	for(it=deptArr.begin(); it!=deptArr.end(); it++)
	{
		if(0 == strcmp(it->getName(),dep.getName()))
		{
			return false;
		}
	}
	//从文件中读取ID
	dep.setId(get_deptid());
	deptArr.push_back(dep);
	return true;
}

int ServiceCtrlImpl::delDept(int depid)
{
	//返回删除部门的人数
	int cnt = -1;
	vector<Department>::iterator it;
	for(it=deptArr.begin(); it!=deptArr.end(); it++)
	{
		if(it->getId() == depid)
		{
			cnt = it->empArr.size();
			deptArr.erase(it);
			return cnt;
		}
	}
	return cnt;
}

vector<Department>& ServiceCtrlImpl::listDept(void)
{
	return deptArr;
}

bool ServiceCtrlImpl::addEmp(int dep,Employee& emp)
{
	vector<Department>::iterator it;
	for(it=deptArr.begin(); it!=deptArr.end(); it++)
	{
		if(it->getId() == dep)
		{
			//找到了对应的部门
			emp.setId(get_empid());
			it->empArr.push_back(emp);
			return true;
		}
	}
	return false;
}

bool ServiceCtrlImpl::delEmp(int emp)
{
	vector<Department>::iterator it;
	for(it=deptArr.begin(); it!=deptArr.end(); it++)
	{
		vector<Employee>::iterator it_emp;
		for(it_emp=it->empArr.begin(); it_emp!=it->empArr.end(); it_emp++)
		{
			if(emp == it_emp->getId())
			{
				it->empArr.erase(it_emp);
				return true;
			}
		}
	}
	return false;
}

bool ServiceCtrlImpl::modEmp(int empid,Employee& emp)
{
	vector<Department>::iterator it;
	for(it=deptArr.begin(); it!=deptArr.end(); it++)
	{
		vector<Employee>::iterator it_emp;
		for(it_emp=it->empArr.begin(); it_emp!=it->empArr.end(); it_emp++)
		{
			if(empid == it_emp->getId())
			{
				it_emp->setAge(emp.getAge());
				it_emp->setName(emp.getName());
				it_emp->setSex(emp.getSex());
				return true;
			}
		}
	}
	return false;
}

Department* ServiceCtrlImpl::listEmp(int dep)
{
	vector<Department>::iterator it;
	for(it=deptArr.begin(); it!=deptArr.end(); it++)
	{
		if(it->getId() == dep)
		{
			//找到了对应的部门
			return &(*it);
		}
	}
	return nullptr;
}

vector<Department>& ServiceCtrlImpl::listAllEmp(void)
{
	return deptArr;
}

