#include<iostream>
#include"boss.h"
//初始化
boss::boss(string name, int id, int deptled)
{
	this->m_deptled = deptled;
	this->m_name = name;
	this->m_id = id;
}
//显示个人信息
void boss::showperosn()
{
	cout << "员工姓名:" << this->m_name
		<< "\t员工编码:" << this->m_id
		<< "\t员工部门:" << this->showwork()
		<< "\t工作：完成总裁给的任务" << endl;
}
//显示岗位信息
string boss::showwork()
{
	return string("总裁");
}