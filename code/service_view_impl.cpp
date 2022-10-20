#include "service_view_impl.h"


ServiceViewImpl::ServiceViewImpl()
{
	srcCtrl = new ServiceCtrlImpl;
}

ServiceViewImpl::~ServiceViewImpl()
{
	delete srcCtrl;
}


void ServiceViewImpl::menuSrc(void)
{
	while(true)
	{
		system("clear");
		cout << "***服务子系统***" <<endl;
		cout << "1、添加部门"<<endl;
		cout << "2、删除部门"<<endl;
		cout << "3、列出部门"<<endl;
		cout << "4、添加员工"<<endl;
		cout << "5、删除员工"<<endl;
		cout << "6、修改员工"<<endl;
		cout << "7、列出部门员工"<<endl;
		cout << "8、列出所有员工"<<endl;
		cout << "9、退出子系统"<<endl;
		cout << "enter your choise:";
		switch(getIntCmd(1,9))
		{
			case 1:addDept();break;
			case 2:delDept();break;
			case 3:listDept();break;
			case 4:addEmp();break;
			case 5:delEmp();break;
			case 6:modEmp();break;
			case 7:listEmp();break;
			case 8:listAllEmp();break;
			case 9:return;
		}
		anyKeyContinue();
	}
}

void ServiceViewImpl::addDept(void)
{
	char name[20];
	cout << "请输入部门名称：";
	get_str(name,sizeof(name));
	Department dep(name);
	if(srcCtrl->addDept(dep))
	{
		cout << "添加部门成功"<<endl;
		return;
	}
	cout << "部门名称冲突，添加部门失败！"<<endl;
}

void ServiceViewImpl::delDept(void)
{
	int delDept(int dep);
	int id = 0,cnt = 0;
	cout << "请输入需要删除的部门ID:";
	cin >> id;

	if(-1 == (cnt = srcCtrl->delDept(id)))
	{
		cout << "部门不存在"<<endl;
	}
	else
	{
		cout << "成功删除部门"<<id<<",其中包含部门成员"<<cnt<<"人"<<endl;
	}
}

void ServiceViewImpl::listDept(void)
{
	vector<Department>& dept = srcCtrl->listDept();
	for(unsigned int i=0; i<dept.size(); i++)
	{
		cout << "部门ID:" << dept[i].getId() << " 部门名称："<< dept[i].getName()<<endl;
	}
}

void ServiceViewImpl::addEmp(void)
{
	int age;
	int depid;
	char sex;
	char name[20];
	cout << "请输入员工姓名:";
	get_str(name,sizeof(name));
	cout << "请输入员工性别:";
	cin >> sex;
	cout << "请输入员工年龄:";
	cin >> age;
	cout << "请输入要加入的部门ID:";
	cin >> depid;
	Employee emp(name,sex,age);
	if(srcCtrl->addEmp(depid,emp))
	{
		cout << "添加成功！"<<endl;
		return;
	}
	cout << "添加失败！"<<endl;
}

void ServiceViewImpl::delEmp(void)
{
	int depid;
	cout << "请输入要删除的部门ID:";
	cin >> depid;
	if(-1 == srcCtrl->delDept(depid))
	{
		cout << "部门不存在！"<<endl;
	}
	else
	{
		cout << "删除成功！"<<endl;
	}
}

void ServiceViewImpl::modEmp(void)
{
	int age;
	int id;
	char sex;
	char name[20];
	cout << "请输入修改员工姓名:";
	get_str(name,sizeof(name));
	cout << "请输入修改员工性别:";
	cin >> sex;
	cout << "请输入修改员工年龄:";
	cin >> age;
	cout << "请输入修改员工ID:";
	cin >> id;
	Employee emp(name,sex,age,id);
	
	if(srcCtrl->modEmp(id,emp))
	{
		cout << "修改成功！"<<endl;
	}
	else
	{
		cout << "修改失败！"<<endl;
	}
}

void ServiceViewImpl::listEmp(void)
{
	int depid;
	cout << "请输入要显示成员的部门ID:";
	cin >> depid;
	Department* dept = srcCtrl->listEmp(depid);
	vector<Employee>::iterator it;
	for(it=dept->empArr.begin(); it!=dept->empArr.end(); it++)
	{
		cout << *it << endl;
	}
}

void ServiceViewImpl::listAllEmp(void)
{
	vector<Department>& dep = srcCtrl->listAllEmp();
	vector<Department>::iterator it;
	for(it=dep.begin(); it!=dep.end(); it++)
	{
		vector<Employee>::iterator it_emp;
		for(it_emp=it->empArr.begin(); it_emp!=it->empArr.end(); it_emp++)
		{
			cout << *it_emp << endl;
		}
	}
}


