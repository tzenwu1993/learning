#include"interfacebase.h"
#include<windows.h>
int main()
{
	system("color f0");
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);   //句柄语句
	COORD size={158,80};
	SetConsoleScreenBufferSize(hout,size);      //重新设置缓冲区
	interfacebase interfacenow;
	interfacenow.clearscreen();
	while (1)
	{
		interfacenow.showmenu();  //显示窗口
		interfacenow.processmenu();  //处理菜单，出口就在其中
		system("pause");
		interfacenow.clearscreen();
	}
	return 0;
}