#ifndef SERVICE_CTRL_IMPL_H
#define SERVICE_CTRL_IMPL_H

#include "service_ctrl.h"
#include "service_mode_impl.h"

//service自模块的实现，主要是对接口进行实现
//父类指针指向子类对象即多态

class ServiceCtrlImpl : public ServiceCtrl
{
private:
	ServiceMode* srcMode;		//用来操作存储模型的接口
	vector<Department> deptArr;	//存放部门信息
public:
	ServiceCtrlImpl(void);
	~ServiceCtrlImpl(void);
	
	bool addDept(Department& dep);			//添加部门
	int delDept(int depid);					//删除部门
	vector<Department>& listDept(void);		//罗列所有的部门
	bool addEmp(int dep,Employee& emp);		//添加员工到部门
	bool delEmp(int emp);					//删除员工
	bool modEmp(int empid,Employee& emp);	//改变员工信息
	Department* listEmp(int dep);			//罗列部门员工
	vector<Department>& listAllEmp(void);	//罗列所有员工
};
#endif//SERVICE_CTRL_IMPL_H
