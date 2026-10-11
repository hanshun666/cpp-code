#include"workmanger.h"
#include<iostream>
#include"Worker.h"
workmanger::workmanger()
{
	//文件不存在
	ifstream of;
	of.open(filename, ios::in);
	if (!of.is_open())
	{
		//cout << "文件不存在" << endl;
		this->m_num = 0;
		this->m_emparry = NULL;
		this->m_file= true;
		return;
	}
	else {
		int numm = this->getnum();
		//cout << "当前人数：" << numm << endl;
		this->m_num = numm;
		this->m_emparry = new worker * [this->m_num];
		this->init_emp();
		//for (int i=0;i < this->m_num;i++)
		//{
		//	cout << "职工编号：" << this->m_emparry[i]->m_id<<" "
		//		<< "职工姓名：" << this->m_emparry[i]->m_name<<" "
		//		<< "职工部门" << this->m_emparry[i]->m_deptled<<endl;
		//}
	}
	m_num = 0;
	m_emparry = NULL;
}
void workmanger::show()
{
	cout<< "*******************************" << endl;
	cout << "*****欢迎使用职工管理系统*****" << endl;
	cout << "*******0.退出职工管理系统*****" << endl;
	cout << "*******1.增加职工信息*********" << endl;
	cout << "*******2.显示职工信息*********" << endl;
	cout << "*******3.删除职工信息*********" << endl;
	cout << "*******4.修改职工信息*********" << endl;
	cout << "*******5.查找职工信息*********" << endl;
	cout << "*******6.按照编号排序*********" << endl;
	cout << "*******7.清空文档内容*********" << endl;
	cout << "******************************" << endl;
	cout << endl;
}
void workmanger::exita()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void workmanger::m_add()
{
	cout << "请输入添加的人数:" << endl;
	int addnum;//添加的数量
	cin >> addnum;
	if (addnum > 0)
	{
		//计算添加新的空间大小
		int newnum = this->m_num + addnum;//新空间人数=原来的+新加的
		//开辟新空间
		worker** newspace= new worker * [newnum];
		if (this->m_emparry != NULL)
		{
			//添加原来的人
			for (int i = 0;i < this->m_num;i++)
			{
				newspace[i]=m_emparry[i];
			}
		}
		//添加新员工
		for (int i = 0;i < addnum;i++)
		{
			int id;//编号
			string name;//姓名
			int select;//部门
			cout << "请输入第 " << i + 1 << " 个职工编号" << endl;
			cin >> id;
			cout << "请输入第 " << i + 1 << " 个职工姓名" << endl;
			cin >> name;
			cout << "请输入第 " << i + 1 << " 个职工部门" << endl;
			cin >> select;
			worker* work = NULL;
			switch (select)
			{
			case 1:
				work = new Emploee(name, id, select);
				break;
			case 2:
				work = new manger(name, id, select);
				break;
			case 3:
				work = new boss(name, id, select);
				break;
			default:
				break;

			}
			//将员工加入数组
			newspace[this->m_num + i] = work;
		}
		delete[] this->m_emparry;
		this->m_emparry = newspace;
		this->m_num = newnum;
		cout << "添加成功" << endl;
		this->save();
	}
	else
	{

	}
	system("pause");
	system("cis");

}
void workmanger::save()
{
	ofstream of;
	of.open(filename, ios::out);
	for (int i = 0;i < this->m_num;i++)
	{
		of << this->m_emparry[i]->m_id << " "
			<< this->m_emparry[i]->m_name << " "
			<< this->m_emparry[i]->m_deptled << endl;
	}
	of.close();
}
int workmanger::getnum()
{
	ifstream of;
	of.open(filename, ios::in);
	int id;
	string name;
	int did;
	int num = 0;
	while (of >> id && of >> name && of >> did)
	{
		num++;
	}
	return num;
	of.close();

}
//初始化员工
void workmanger::init_emp()
{
	ifstream of;
	of.open(filename, ios::in);
	int id;
	string name;
	int idi;
	int idx = 0;
	while (of >> id && of >> name && of >> idi)
	{
		worker* work = NULL;
		if (idi == 1)
		{
			work = new Emploee(name,id,idi);
		}
		if (idi == 2)
		{
			work = new manger(name, id, idi);
		}
		if (idi == 3)
		{
			work = new boss(name, id, idi);
		}
		this->m_emparry[idx] = work;
		idx++;
	}
	of.close();
}
//显示职工
void workmanger::show_emp()
{

	if (m_file)
	{
		cout << "文件不存在" << endl;
	}
	else
	{
		int numm = this->getnum();
		this->m_num = numm;
		this->m_emparry = new worker * [this->m_num];
		this->init_emp();
		//
		for (int i = 0;i < this->m_num;i++)
		{
			this->m_emparry[i]->showperosn();
		}
	}
	system("pause");
	system("cis");
}
int workmanger::is_emp(int a)
{
	int ids = -1;
	for (int i = 0;i < this->m_num;i++)
	{
		if (this->m_emparry[i]->m_id == a)
		{
			return i;
	    }
	}	
	return ids;
}
void workmanger::delete_emp()
{
	int w;
	cout << "请输入你要删除的员工：" << endl;
	cin >> w;
	int idx = this->is_emp(w);
	if (idx!=-1)
	{
		for (int i = idx;i < this->m_num - 1;i++)
		{
			this->m_emparry[i] = this->m_emparry[i + 1];
		}
		this->m_num--;
		this->save();
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "该员工不存在" << endl;
	}
	system("pause");
	system("cis");
}
//修改职工信息
void workmanger::Mod_emp()
{
	cout << "请输入要修改第几个员工信息" << endl;
	int a;
	cin >> a;
	int idx = a - 1;
	cout << "修改的姓名：" << endl;
	string newname;
	cin >> newname;
	this->m_emparry[idx]->m_name = newname;
	cout << "修改的编号：" << endl;
	int newid;
	cin >> newid;
	this->m_emparry[idx]->m_id = newid;
	cout << "修改的部门：" << endl;
	int newidi;
	cin >> newidi;
	this->m_emparry[idx]->m_deptled;
	this->save();
	cout << "修改成功" << endl;
	system("pause");
	system("cis");
}
void workmanger::seek_emp()
{
	cout << "请输入你要查找的员工编码：" << endl;
	int a;
	cin >> a;
	int idx = this->is_emp(a);
	if (idx != -1)
	{
		cout << "查找成功" << endl;
		cout << "姓名：" << this->m_emparry[idx]->m_name << " "
			<< "编号：" << this->m_emparry[idx]->m_id << " "
			<< "部门" << this->m_emparry[idx]->showwork() << endl;
	}
	else
	{
		cout << "查找失败" << endl;
	}
	system("pause");
	system("cis");
}
void workmanger::sort_emp()
{
	cout << "请选择排序的方式：" << endl;
	cout << "1.按编号排：" << endl;
	cout << "2.按名字长度排：" << endl;
	cout << "3.按部门排：" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "请选择哪种方式：" << endl;
		cout << "1.升序" << endl;
		cout << "2.降序" << endl;
		int select1 = 0;
		cin >> select1;
		if (select == 1)
		{
			for (int i = 0;i < this->m_num - 1;i++)
			{
				for (int j = 0;j < this->m_num - 1 - i;j++)
				{
					if (this->m_emparry[j]->m_id > this->m_emparry[j + 1]->m_id)
					{
						worker* temp = this->m_emparry[j];
						this->m_emparry[j] = this->m_emparry[j + 1];
						this->m_emparry[j + 1] = temp;
					}
				}
			}
		}
		else
		{
			for (int i = 0;i < this->m_num - 1;i++)
			{
				for (int j = 0;j < this->m_num - 1 - i;j++)
				{
					if (this->m_emparry[j]->m_id < this->m_emparry[j + 1]->m_id)
					{
						worker* temp = this->m_emparry[j];
						this->m_emparry[j] = this->m_emparry[j + 1];
						this->m_emparry[j + 1] = temp;
					}
				}
			}
		}
	}
	else if (select == 2)
	{

	}
	cout << "排序成功" << endl;
	this->save();
	system("pause");
	system("cis");


}
//清空文件
void workmanger::m_delete()
{
	cout << "是否确认清空" << endl;
	cout << "1.确认" << endl;
	cout << "2.取消" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream of(filename, ios::trunc);//删除文件后在重新创建
		of.close();
		if (this->m_emparry != NULL)
		{
			for (int i = 0;i < this->m_num;i++)
			{
				//删除堆区的成员
				delete this->m_emparry[i];
				this->m_emparry[i] = NULL;
			}
			delete[] this->m_emparry;
			this->m_emparry = NULL;
			this->m_num = 0;
			this->m_file = true;
		}
	}
	cout << "清除成功" << endl;
	system("pause");
	system("cis");

}
workmanger::~workmanger()
{
	if (this->m_emparry != NULL)
	{
		
		delete[] this->m_emparry;
		this->m_emparry = NULL;
	}
}