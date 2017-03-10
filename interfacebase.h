#include"Cskillstudy.h"
#include<iostream>
using namespace std;
const int CUTTINGLINESTART = 1;
const int CUTTINGLINELENGTH = 25;
class interfacebase
{
public:
	Cskillstudy Cskillstudyonface;  //定义一个对象
	void clearscreen(void);
	void showmenu(void);
	void processmenu(void);
	void showcuttingline(void);
};