#include<iostream>
using namespace std;
#include"workmanger.h"
#include"emploee.h"
#include"Worker.h"
#include"boss.h"
#include"manger.h"
int main()
{
	workmanger wm;
	int choice = 0;
	while (1)
	{
		wm.show();
		cout << "请输入您的选择" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:wm.exita();
			break;
		case 1:
			wm.m_add();
			break;
		case 2:
			wm.show_emp();
			break;
		case 3:
			wm.delete_emp();
			break;
		case 4:
			wm.Mod_emp();
			break;
		case 5:
			wm.seek_emp();
			break;
		case 6:
			wm.sort_emp();
			break;
		case 7:
			wm.m_delete();
			break;
		default:
			system("cls");
			break;

		}
	}

	system("pause");
	return 0;
}
