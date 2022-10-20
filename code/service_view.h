#ifndef SERVICE_VIEW_H
#define SERVICE_VIEW_H

//服务类功能接口

class ServiceView
{
public:
	virtual ~ServiceView(void){}
	virtual void menuSrc(void) = 0;	//服务子菜单入口函数
	virtual void addDept(void) = 0;	//添加部门
	virtual void delDept(void) = 0;	//删除部门
	virtual void listDept(void) = 0;//罗列部门
	virtual void addEmp(void) = 0;	//增加员工
	virtual void delEmp(void) = 0;	//删除员工
	virtual void modEmp(void) = 0;	//修改员工
	virtual void listEmp(void) = 0;	//显示部门员工
	virtual void listAllEmp(void) = 0;//显示所有员工
};
#endif//SERVICE_VIEW_H
