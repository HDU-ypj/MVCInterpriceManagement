#ifndef SERVICE_CTRL_H
#define SERVICE_CTRL_H

#include "department.h"

//服务子功能的控制模块接口，主要负责对应功能的实现
//向视图层提供服务

class ServiceCtrl
{
public:
	virtual ~ServiceCtrl(void){};
	virtual bool addDept(Department& dep) = 0;			//添加部门
	virtual int delDept(int dep) = 0;					//删除部门
	virtual vector<Department>& listDept(void) = 0;		//罗列部门
	virtual bool addEmp(int dep,Employee& emp) = 0;		//添加员工到部门
	virtual bool delEmp(int emp) = 0;					//删除员工
	virtual bool modEmp(int dep,Employee& emp) = 0;		//修改员工信息
	virtual Department* listEmp(int dep) = 0;			//罗列部门员工
	virtual vector<Department>& listAllEmp(void) = 0;	//罗列所有员工
};
#endif//SERVICE_CTRL_H
