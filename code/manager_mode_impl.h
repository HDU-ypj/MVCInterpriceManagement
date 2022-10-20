#ifndef MANAGER_MODE_IMPL_H
#define MANAGER_MODE_IMPL_H

#include "manager_mode.h"

//管理员存储模型的实现类声明

class ManagerModeImpl : public ManagerMode
{
public:
	void load(vector<Manager>& mgr);
	void save(const vector<Manager>& mgr);
};

#endif
