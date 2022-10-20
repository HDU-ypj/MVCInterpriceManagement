#include <fstream>
#include <getch.h>
#include "tools.h"

//	从键盘获取字符串
char* get_str(char* str,size_t len)
{
	if(NULL == str || 0 == len) return NULL;

	size_t index = 0;

	stdin->_IO_read_ptr = stdin->_IO_read_end;
	while(index < len-1)
	{
		char key_val = getch();
		if(10 == key_val) break;
		if(127 == key_val)
		{
			if(0 < index)
			{
				index--;
				printf("\b \b");	//显示退格效果
			}	
			continue;
		}
		printf("%c",key_val);
		str[index++] = key_val;
	}
	str[index] = '\0';
	printf("\n");

	//	清理输入缓冲区
	stdin->_IO_read_ptr = stdin->_IO_read_end;

	return str;
}

//	从键盘输入密码
char* get_pass(char* pass,size_t len,bool is_show)
{
	if(NULL == pass || 0 == len) return NULL;
	size_t index = 0;
	
	//	清理输入缓冲区
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	
	while(index < len-1)
	{
		char key_val = getch();
		if(10 == key_val) break;
		if(127 == key_val)
		{
			if(0 < index)
			{
				index--;
				if(is_show) printf("\b \b");	//显示退格效果
			}	
			continue;
		}
		if(is_show) printf("*");
		pass[index++] = key_val;
	}
	pass[index] = '\0';
	printf("\n");
	//	清理输入缓冲区
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	return pass;
}

void anyKeyContinue(void)
{
	//清空缓存区
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	cout << "any key continue……";
	cout.flush();
	//获取一个按键输入
	getch();
}

int getIntCmd(int min,int max)
{
	int cmd;
	while(true)
	{
		cin >> cmd;
		if(cin.fail() || cmd<min || cmd>max)
		{
			cin.clear();
			continue;
		}
		break;
	}
	return cmd;
}

void initId(void)
{
	ifstream ifs;
	ifs.open(DATA_ID_PATH);

	if(ifs.good())
	{
		ifs.close();
		return;
	}
	
	ofstream ofs(DATA_ID_PATH,ios::out|ios::binary);
	int id[3] = {1000,2000,3000};
	ofs.write((char*)id,sizeof(id));
	ofs.close();
}

int get_mgrid(void)
{
	fstream fs;
	fs.open(DATA_ID_PATH);
	if(fs.fail())
	{
		cout << "请调用init函数后使用"<<endl;
		anyKeyContinue();
		return -1;
	}
	int id;
	fs.read((char*)&id,4);
	id++;
	fs.seekg(0);
	fs.write((char*)&id,4);
	fs.close();
	return id-1;
}
int get_deptid(void)
{
	fstream fs;
	fs.open(DATA_ID_PATH);
	if(fs.fail())
	{
		cout << "请调用init函数后使用"<<endl;
		anyKeyContinue();
		return -1;
	}
	int id;
	fs.seekg(4,ios::beg);
	fs.read((char*)&id,4);
	id++;
	fs.seekg(4,ios::beg);
	fs.write((char*)&id,4);
	fs.close();
	return id-1;
}
int get_empid(void)
{
	fstream fs;
	fs.open(DATA_ID_PATH);
	if(fs.fail())
	{
		cout << "请调用init函数后使用"<<endl;
		anyKeyContinue();
		return -1;
	}
	int id;
	fs.seekg(8,ios::beg);
	fs.read((char*)&id,4);
	id++;
	fs.seekg(8,ios::beg);
	fs.write((char*)&id,4);
	fs.close();
	return id-1;
}

