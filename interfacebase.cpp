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
	cout << "         ��������������㷨ѧϰϵͳ                 " << endl;
	cout << "================================================" << endl;
	cout << "�������˵����                            " << endl;
	cout << "�ò˵���ʽѧϰ�����㷨             " << endl;
	cout << "================================================" << endl;
	cout << "         ���ܲ˵�                             " << endl;
	cout << "================================================" << endl;
	cout << "1.��������                                " << endl;
	cout << "2.�����������                            " << endl;
	cout << "3.���������                             " << endl;
	cout << "4.�鲢�������                            " << endl;
	cout << "5.��������                                " << endl;
	cout << "0.��������                             " << endl;
	cout << "================================================" << endl;
	cout << "����������ѡ��  " << endl;
}

void interfacebase::processmenu(void)
{
    char menuchoice;
	cin >> menuchoice;
	switch (menuchoice)
	{
	case '1':
		cout << "1.�������� " << endl;
		Cskillstudyonface.input();
		showcuttingline();
		break;
	case '2':
		cout << "2.����������� " << endl;
		Cskillstudyonface.insert_sort();
		showcuttingline();
		break;
	case '3':
		cout << "3.��������� " << endl;
		Cskillstudyonface.HeapSort(Cskillstudyonface.length);
		Cskillstudyonface.output();
		showcuttingline();
		break;
	case '4':
		cout << "4.�鲢������� " << endl;
		Cskillstudyonface.MergeSort(Cskillstudyonface.length);
		Cskillstudyonface.output();
		showcuttingline();
		break;
	case '5':
		cout << "5.��������  " << endl;
		Cskillstudyonface.fast_sort(0, Cskillstudyonface.length-1);
		Cskillstudyonface.output();
		showcuttingline();
		break;
	case '0':
		cout << endl << endl << "���Ѿ��ɹ��˳���ϵͳ����ӭ�ٴ�ʹ�ã�����" << endl;
		system("pause");
		exit(1);
	default:
		cout << "�Բ���������Ĺ��ܱ���д����������룡����" << endl;
		break;
	}
}