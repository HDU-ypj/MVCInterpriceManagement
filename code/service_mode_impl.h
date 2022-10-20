#ifndef SERVICE_MODE_IMPL_H
#define SERVICE_MODE_IMPL_H

#include "service_mode.h"

//service的存储模型实现，完成对部门信息文件的读写操作

class ServiceModeImpl:public ServiceMode
{
public:
	void load(vector<Department>& dep);
	void save(const vector<Department>& dep);
};
#endif//SERVICE_MODE_IMPL_H
