/*
人的移动和箱子的移动
当人的前面是箱子/空地/墙壁的时候
当人的前面是墙壁/人的前面是箱子，但箱子的前面是墙壁的时候
*/

/*
实现位移：
数组的变化-> 当数组的一个地方的值为多少时，在控制台上吧对应的字符打印出来
遍历数组
通过修改数组中的值来实现不同坐标的字符的变化
DICKQI
2017/10/28
*/
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <iostream>
//图片对象
IMAGE nothing, wall, end, box, human, dbox;

//画地图
void dmap();
//通关
int win();
//加载图片
void loadimage();
//玩法操作
void play();
//主函数
int main()
{
	int Win = 0;
	initgraph(600, 480);
	loadimage();
	cleardevice();
	while (1)
	{
		BeginBatchDraw();
		cleardevice();
		dmap();
		EndBatchDraw();
		Win = win();
		if (Win == 1)
			break;
		play();
	}
	MessageBox(NULL, L"请按任意键退出", L"恭喜", MB_OK);
	getchar();
	return 0;
}
