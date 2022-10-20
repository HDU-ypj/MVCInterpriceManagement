#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <vector>
#include <cstring>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
using namespace std;

//存储自动生成ID号的文件
#define DATA_ID_PATH "../bin/id.txt"
//存储管理员信息的文件
#define DATA_MGR_PATH "../bin/managers.txt"
//存储部门和成员的文件
#define DATA_SRV_PATH "../bin/services.txt"

//从键盘获取字符串
char* get_str(char* str,size_t len);
//从键盘输入密码
char* get_pass(char* pass,size_t len,bool is_show=false);
//任意键退出
void anyKeyContinue(void);
//获取int类型指令
int getIntCmd(int min,int max);
//初始化id.dat文件,系统初始化时必须调用
void initId(void);

//获取自动生成ID
int get_mgrid(void);
int get_deptid(void);
int get_empid(void);

#endif//TOOLS_H
