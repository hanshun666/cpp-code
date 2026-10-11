#include<iostream>
#include"emploee.h"
//初始化
Emploee::Emploee(string name, int id, int deptled)
{
	this->m_deptled = deptled;
	this->m_name = name;
	this->m_id = id;
}
//显示个人信息
void Emploee::showperosn()
{
	cout << "员工姓名:" << this->m_name
		<< "\t员工编码:" << this->m_id
		<< "\t员工部门:" << this->showwork()
		<< "\t工作：完成经理给的任务" << endl;
}
//显示岗位信息
string Emploee::showwork()
{
	return string("员工");
}
