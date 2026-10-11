#pragma once
#include<iostream>
using namespace std;
#include<string>
//抽象职工类
class worker
{
public:
	//显示个人信息
	virtual void showperosn() = 0;
	//显示岗位信息
	virtual string showwork() = 0;
	//姓名
	string m_name;
	//编号
	int m_id;
	//部门编号
	int m_deptled;
};
