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

IMAGE nothing, wall, end, box, human, dbox;
//地图
//0 空地， 1墙壁， 3终点， 4箱子， 5人， 7黑箱子， 8人在终点中
int map[11][15] = {
	{0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1},
	{0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 3, 3, 1},
	{0, 0, 0, 0, 1, 4, 0, 0, 1, 0, 0, 1, 3, 3, 1},
	{0, 0, 1, 1, 1, 0, 0, 4, 1, 1, 0, 1, 3, 3, 1},
	{0, 0, 1, 0, 0, 4, 0, 4, 0, 1, 0, 1, 0, 0, 1},
	{1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1},
	{1, 0, 4, 0, 0, 4, 0, 0, 0, 0, 0, 5, 0, 0, 1},
	{1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1},
	{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
	{0, 0, 0, 0, 1, 1, 1, 1, 1, 1 ,1, 0, 0, 0, 0}
};

void dmap();//画地图

int win();

void loadimage();

void play();
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
	MessageBox(NULL, L"请按任意键退出", L"恭喜",MB_OK);
	getchar();
	return 0;
}
//画地图
void dmap()
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			switch (map[i][j])
			{
			case 0:
				putimage(j * 30, i * 30, &nothing);
				break;
			case 1:
				putimage(j * 30, i * 30, &wall);
				break;
			case 3:
				putimage(j * 30, i * 30, &end);
				break;
			case 4:
				putimage(j * 30, i * 30, &box);
				break;
			case 5:
				putimage(j * 30, i * 30, &human);
				break;
			case 7:
				putimage(j * 30, i * 30, &dbox);
				break;
			case 8:
				putimage(j * 30, i * 30, &human);
				break;
			}
		}
		printf("\n");
	}
}
//玩法操作
void play()
{
	int x, y;
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (map[i][j] == 5 || map[i][j] == 8)
			{
				x = i;
				y = j;
			}
		}
	}
	int ch;
	ch = _getch();
	switch (ch)
	{
	case 'a':
	case 'A':
		if (map[x][y - 1] == 0 || map[x][y - 1] == 3)
		{
			map[x][y] -= 5;
			map[x][y - 1] += 5;
		}
		else if (map[x][y - 1] == 4 || map[x][y - 1] == 7)
		{
			if (map[x][y - 2] == 0 || map[x][y - 2] == 3)
			{
				map[x][y] -= 5;
				map[x][y - 1] += 1;
				map[x][y - 2] += 4;
			}
		}
		break;
	case 'w':
	case 'W':
		if (map[x- 1][y] == 0 || map[x - 1][y] == 3)
		{
			map[x][y] -= 5;
			map[x - 1][y] += 5;
		}
		else if (map[x - 1][y] == 4 || map[x - 1][y] == 7)
		{
			if (map[x - 2][y] == 0 || map[x - 2][y] == 3)
			{
				map[x][y] -= 5;
				map[x - 1][y] += 1;
				map[x - 2][y] += 4;
			}
		}
		break;
	case 's':
	case 'S':
		if (map[x + 1][y] == 0 || map[x + 1][y] == 3)
		{
			map[x][y] -= 5;
			map[x + 1][y] += 5;
		}
		else if (map[x + 1][y] == 4 || map[x + 1][y] == 7)
		{
			if (map[x + 2][y] == 0 || map[x + 2][y] == 3)
			{
				map[x][y] -= 5;
				map[x + 1][y] += 1;
				map[x + 2][y] += 4;
			}
		}
		break;
	case 'd':
	case 'D':
		if (map[x][y + 1] == 0 || map[x][y + 1] == 3)
		{
			map[x][y] -= 5;
			map[x][y + 1] += 5;
		}
		else if (map[x][y + 1] == 4 || map[x][y + 1] == 7)
		{
			if (map[x][y + 2] == 0 || map[x][y + 2] == 3)
			{
				map[x][y] -= 5;
				map[x][y + 1] += 1;
				map[x][y + 2] += 4;
			}
		}
		break;
	default:
		break;
	}
}
//加载图片
void loadimage()
{
	loadimage(&nothing, _T("./blank.png"), 30, 30);
	loadimage(&wall, _T("./WALL.jpg"), 30, 30);
	loadimage(&end, _T("./ENDPOINT.jpg"), 30, 30);
	loadimage(&box, _T("./BOX.jpg"), 30, 30);
	loadimage(&human, _T("./character.jpg"), 30, 30);
	loadimage(&dbox, _T("./DARKBOX.jpg"), 30, 30);
}
//通关提示
int win()
{
	int m = 0;
	for (int i = 0; i < 11; i++)
	{
		for (int  j = 0; j < 15; j++)
		{
			if (map[i][j] == 7)
				m++;
		}
	}
	if (m == 6)
	{
		MessageBox(NULL, L"你赢了！", L"23333", MB_OK);
		return 1;
	}
}