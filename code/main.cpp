/**************************************************
>	作	  者：杭电羊皮卷
>	邮	  箱：2997675141@qq.com
>   文件名称: main.cpp
>   创建日期：2022年10月14日
>   描    述：
**************************************************/

#include <iostream>
using namespace std;

#include "manager_view_impl.h"
#include "emis.h"

int main(int argc,const char* argv[])
{
	//获取单例对象
	Emis& emis = Emis::getEmis();
	//调用系统系统函数
	emis.start();
	return 0;
}
