#ifndef MANAGER_MODE_H
#define MANAGER_MODE_H

#include "manager.h"

//管理员的存储模型接口，负责管理员的信息存储和读写操作

class ManagerMode
{
public:
	virtual ~ManagerMode(void) {}
	virtual void load(vector<Manager>& mgr) = 0;
	virtual void save(const vector<Manager>& mgr) = 0;
};
#endif
