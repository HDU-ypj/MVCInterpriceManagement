#include "manager_view_impl.h"
#include "manager_ctrl_impl.h"
#include "service_view_impl.h"

ManagerViewImpl::ManagerViewImpl(void)
{
	initId();
	mgrCtrl = new ManagerCtrlImpl;
	srcView = new ServiceViewImpl;
}

ManagerViewImpl::~ManagerViewImpl(void)
{
	delete srcView;
	delete mgrCtrl;
}

void ManagerViewImpl::loginManager(void)
{
	char id[20] = {},pwd[20] = {};
	cout << "请输入超级用户ID:";
	get_str(id,sizeof(id));
	cout << "请输入超级用户密码:";
	get_pass(pwd,sizeof(pwd));
	
	if(!strcmp(id,"admin") && !strcmp(pwd,"123"))
	{
		menuMgr();
		return;
	}
	cout << "用户名或密码出错，请检查!" << endl;
	anyKeyContinue();
}

void ManagerViewImpl::loginService(void)
{
	int id = 0;
	char pwd[20]={};
	cout << "请输入业务管理员ID:";
	cin >> id;
	cout << "请输入业务管理员密码:";
	get_pass(pwd,sizeof(pwd),true);
	vector<Manager>&mgrArr = mgrCtrl->listMgr();
	for(unsigned int i=0; i<mgrArr.size(); i++)
	{
		if(id == mgrArr[i].getId() && !strcmp(pwd,mgrArr[i].getPwd()))
		{
			srcView->menuSrc();
			return;
		}
	}
	cout << "登录失败"<<endl;
	anyKeyContinue();
}

void ManagerViewImpl::menuMgr(void)
{
	while(true)
	{
		system("clear");
		cout << "***超级用户子系统***" <<endl;
		cout << "1、添加管理员"<<endl;
		cout << "2、删除管理员"<<endl;
		cout << "3、列出管理员"<<endl;
		cout << "4、退出子系统"<<endl;
		cout << "enter your choise:";
		switch(getIntCmd(1,4))
		{
			case 1:addMgr();break;
			case 2:delMgr();break;
			case 3:listMgr();break;
			case 4:return;
		}
	}
}
void ManagerViewImpl::addMgr(void)
{
	char name[20]={},pwd[20]={},repwd[20]={};
	cout << "请输入管理员姓名：";
	get_str(name,sizeof(name));
	cout << "请设置密码：";
	get_str(pwd,sizeof(pwd));
	cout << "请确认密码：";
	get_str(repwd,sizeof(repwd));
	if(strcmp(pwd,repwd))
	{
		cout << "两次密码不同，添加失败"<<endl;
		anyKeyContinue();
		return;
	}

	Manager mgr(name,pwd);
	if(mgrCtrl->addMgr(mgr))
	{
		cout << "添加管理员成功!"<<endl;
		anyKeyContinue();
		return;
	}
	cout << "用户名重复，添加管理员失败!"<<endl;
	anyKeyContinue();
}

void ManagerViewImpl::delMgr(void)
{
	int id = 0;
	cout << "请输入要删除的管理员ID:";
	cin >> id;
	
	if(mgrCtrl->delMgr(id))
	{
		cout << "删除管理员成功!" << endl;
		anyKeyContinue();
		return;	
	}
	cout << "管理员ID有误,删除失败!" << endl;
	anyKeyContinue();
}

void ManagerViewImpl::listMgr(void)
{
	vector<Manager>& mgrArr = mgrCtrl->listMgr();
	for(unsigned int i=0; i<mgrArr.size(); i++)
	{
		cout << mgrArr[i] << endl;
	}
	anyKeyContinue();
}

