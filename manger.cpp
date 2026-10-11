#include"manger.h"
#include<iostream>
manger::manger(string name, int id, int deptled)
{
	this->m_name = name;
	this->m_id = id;
	this->m_deptled = deptled;
}
//显示个人信息
void manger::showperosn()\
{
	cout << "员工姓名:" << this->m_name
		<< "\t员工编码:" << this->m_id
		<< "\t员工部门:" << this->showwork()
		<< "\t工作：完成老板给的任务" << endl;
}
//显示岗位信息
string manger::showwork()
{
	return string("经理");
}