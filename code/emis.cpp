#include "emis.h"
#include "manager_view_impl.h"

Emis Emis::emis;
Emis::Emis(void)
{
	mgrView = new ManagerViewImpl;
}

Emis::~Emis(void)
{
	delete mgrView;
}

Emis& Emis::getEmis(void)
{
	return emis;
}

void Emis::start(void)
{
	while(true)
	{
		system("clear");
		cout << "***welcome***"<<endl;
		cout << "1、登录超级管理员系统"<<endl;
		cout << "2、登录业务管理员子系统"<<endl;
		cout << "3、退出系统"<<endl;
		switch(getIntCmd(1,3))
		{
			case 1:mgrView->loginManager();break;
			case 2:mgrView->loginService();break;
			case 3:return;
		}
	}
}
