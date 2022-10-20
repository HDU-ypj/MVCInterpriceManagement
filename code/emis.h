#ifndef EMIS_H
#define EMIS_H

#include "manager_view.h"

class Emis
{
	ManagerView* mgrView;			//操作管理的接口
	static Emis emis;				//饿汉式单例
	Emis(void);						//私有构造和拷贝构造
	Emis(const Emis& that) {}
public:
	static Emis& getEmis(void);
	~Emis(void);
	void start(void);				//系统启动函数
};
#endif//EMIS_H
