#include"Cskillstudy.h"
#include<iostream>
using namespace std;
const int CUTTINGLINESTART = 1;
const int CUTTINGLINELENGTH = 25;
class interfacebase
{
public:
	Cskillstudy Cskillstudyonface;  //����һ������
	void clearscreen(void);
	void showmenu(void);
	void processmenu(void);
	void showcuttingline(void);
};