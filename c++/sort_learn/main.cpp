#include"interfacebase.h"
#include<windows.h>
int main()
{
	system("color f0");
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);   //������
	COORD size={158,80};
	SetConsoleScreenBufferSize(hout,size);      //�������û�����
	interfacebase interfacenow;
	interfacenow.clearscreen();
	while (1)
	{
		interfacenow.showmenu();  //��ʾ����
		interfacenow.processmenu();  //����˵������ھ�������
		system("pause");
		interfacenow.clearscreen();
	}
	return 0;
}