#ifndef SERVICE_MODE_H
#define SERVICE_MODE_H

#include "department.h"

//service存储模型的对外接口

class ServiceMode
{
public:
	virtual ~ServiceMode(void) {}
	virtual void load(vector<Department>& dep) = 0;
	virtual void save(const vector<Department>& dep) = 0;
};
#endif//SERVICE_MODE_H
