#ifndef SERVICE_VIEW_IMPL_H
#define SERVICE_VIEW_IMPL_H

#include "service_ctrl_impl.h"
#include "service_view.h"

class ServiceViewImpl : public ServiceView
{
public:
	ServiceCtrl* srcCtrl;
	ServiceViewImpl();
	~ServiceViewImpl();
	
	void menuSrc(void);		//服务子菜单入口函数
	void addDept(void);		//添加部门
	void delDept(void);		//删除部门
	void listDept(void);	//罗列部门
	void addEmp(void);		//增加员工
	void delEmp(void);		//删除员工
	void modEmp(void);		//修改员工
	void listEmp(void);		//显示部门员工
	void listAllEmp(void);	//显示所有员工
};

#endif//SERVICE_VIEW_IMPL_H
