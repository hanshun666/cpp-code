#pragma once
#include<iostream>
#include"Worker.h"
using namespace std;
class manger :public worker
{
public:
	//初始化
	manger(string name, int id, int deptled);
	//显示个人信息
	void showperosn();
	//显示岗位信息
	string showwork();

};