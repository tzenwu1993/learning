#include"interfacebase.h"
void interfacebase::clearscreen(void)
{
	system("cls");
}
void interfacebase::showcuttingline(void)
{
	for (int i = 0; i < CUTTINGLINESTART + CUTTINGLINELENGTH; i++)
	{
		if (i < CUTTINGLINESTART)
			cout << "";
		else
			cout << "=";
	}
	cout << endl;
}
void interfacebase::showmenu(void)
{
	cout << "================================================" << endl;
	cout << "         各种排序与查找算法学习系统                 " << endl;
	cout << "================================================" << endl;
	cout << "软件功能说明：                            " << endl;
	cout << "用菜单方式学习排序算法             " << endl;
	cout << "================================================" << endl;
	cout << "         功能菜单                             " << endl;
	cout << "================================================" << endl;
	cout << "1.输入数据                                " << endl;
	cout << "2.插入排序输出                            " << endl;
	cout << "3.堆排序输出                             " << endl;
	cout << "4.归并排序输出                            " << endl;
	cout << "5.快速排序                                " << endl;
	cout << "0.结束程序                             " << endl;
	cout << "================================================" << endl;
	cout << "请输入您的选择：  " << endl;
}

void interfacebase::processmenu(void)
{
    char menuchoice;
	cin >> menuchoice;
	switch (menuchoice)
	{
	case '1':
		cout << "1.输入数据 " << endl;
		Cskillstudyonface.input();
		showcuttingline();
		break;
	case '2':
		cout << "2.插入排序输出 " << endl;
		Cskillstudyonface.insert_sort();
		showcuttingline();
		break;
	case '3':
		cout << "3.堆排序输出 " << endl;
		Cskillstudyonface.HeapSort(Cskillstudyonface.length);
		Cskillstudyonface.output();
		showcuttingline();
		break;
	case '4':
		cout << "4.归并排序输出 " << endl;
		Cskillstudyonface.MergeSort(Cskillstudyonface.length);
		Cskillstudyonface.output();
		showcuttingline();
		break;
	case '5':
		cout << "5.快速排序  " << endl;
		Cskillstudyonface.fast_sort(0, Cskillstudyonface.length-1);
		Cskillstudyonface.output();
		showcuttingline();
		break;
	case '0':
		cout << endl << endl << "您已经成功退出本系统，欢迎再次使用！！！" << endl;
		system("pause");
		exit(1);
	default:
		cout << "对不起，您输入的功能编号有错！请重新输入！！！" << endl;
		break;
	}
}