/*
�˵��ƶ������ӵ��ƶ�
���˵�ǰ��������/�յ�/ǽ�ڵ�ʱ��
���˵�ǰ����ǽ��/�˵�ǰ�������ӣ������ӵ�ǰ����ǽ�ڵ�ʱ��
*/

/*
ʵ��λ�ƣ�
		����ı仯-> �������һ���ط���ֵΪ����ʱ���ڿ���̨�ϰɶ�Ӧ���ַ���ӡ����
		��������
		ͨ���޸������е�ֵ��ʵ�ֲ�ͬ������ַ��ı仯
		DICKQI
		2017/10/28
*/
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <iostream>

IMAGE nothing, wall, end, box, human, dbox;
//��ͼ
//0 �յأ� 1ǽ�ڣ� 3�յ㣬 4���ӣ� 5�ˣ� 7�����ӣ� 8�����յ���
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

void dmap();//����ͼ

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
	MessageBox(NULL, L"�밴������˳�", L"��ϲ",MB_OK);
	getchar();
	return 0;
}
//����ͼ
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
//�淨����
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
//����ͼƬ
void loadimage()
{
	loadimage(&nothing, _T("./blank.png"), 30, 30);
	loadimage(&wall, _T("./WALL.jpg"), 30, 30);
	loadimage(&end, _T("./ENDPOINT.jpg"), 30, 30);
	loadimage(&box, _T("./BOX.jpg"), 30, 30);
	loadimage(&human, _T("./character.jpg"), 30, 30);
	loadimage(&dbox, _T("./DARKBOX.jpg"), 30, 30);
}
//ͨ����ʾ
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
		MessageBox(NULL, L"��Ӯ�ˣ�", L"23333", MB_OK);
		return 1;
	}
}