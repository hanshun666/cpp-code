#pragma
#include<iostream>
#include"Worker.h"
#include"boss.h"
#include"emploee.h"
#include"manger.h"
#include<fstream>
#define filename "empflie.txt"
using namespace std;
class workmanger
{
public:
	workmanger();
	//显示菜单
	void show();
	//退出系统
	void  exita();
	//添加职工
	void m_add();
	//职工数量
	int m_num ;
	//员工指针
	worker** m_emparry;
	//保存文件
	void save();
	//判断文件是否存在
	bool m_file;
	//显示当前人数
	int getnum();
	//初始化员工
	void init_emp();
	//显示职工
	void show_emp();
	//判断职工是否存在
	int is_emp(int a);
	//删除员工
	void delete_emp();
	//修改职工信息
	void Mod_emp();
	//查找员工信息
	void seek_emp();
	//排序
	void sort_emp();
	//清空文件
	void m_delete();
	~workmanger();
	
};