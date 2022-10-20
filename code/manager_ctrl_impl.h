#ifndef MANAGER_CTRL_IMPL_H
#define MANAGER_CTRL_IMPL_H

#include "manager_ctrl.h"
#include "manager_mode.h"

//管理类的实现

class ManagerCtrlImpl : public ManagerCtrl
{
	vector<Manager> mgrArr;
	ManagerMode* mgrMode;
public:
	ManagerCtrlImpl(void);			
	~ManagerCtrlImpl(void);
	bool addMgr(Manager& mgr);			//添加一个管理员
	bool delMgr(int id);				//根据id号删除一个管理员
	vector<Manager>& listMgr(void);		//存储管理员的容器
};

#endif
