#include "function.h"
//0 �յأ� 1ǽ�ڣ� 3�յ㣬 4���ӣ� 5�ˣ� 7�����ӣ� 8�����յ���
int map1[11][15] = {
	{ 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1 },
	{ 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 3, 3, 1 },
	{ 0, 0, 0, 0, 1, 4, 0, 0, 1, 0, 0, 1, 3, 3, 1 },
	{ 0, 0, 1, 1, 1, 0, 0, 4, 1, 1, 0, 1, 3, 3, 1 },
	{ 0, 0, 1, 0, 0, 4, 0, 4, 0, 1, 0, 1, 0, 0, 1 },
	{ 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1 },
	{ 1, 0, 4, 0, 0, 4, 0, 0, 0, 0, 0, 5, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1 },
	{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
	{ 0, 0, 0, 0, 1, 1, 1, 1, 1, 1 ,1, 0, 0, 0, 0 }
};
//����ͼ
void dmap()
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			switch (map1[i][j])
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
			if (map1[i][j] == 5 || map1[i][j] == 8)
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
		if (map1[x][y - 1] == 0 || map1[x][y - 1] == 3)
		{
			map1[x][y] -= 5;
			map1[x][y - 1] += 5;
		}
		else if (map1[x][y - 1] == 4 || map1[x][y - 1] == 7)
		{
			if (map1[x][y - 2] == 0 || map1[x][y - 2] == 3)
			{
				map1[x][y] -= 5;
				map1[x][y - 1] += 1;
				map1[x][y - 2] += 4;
			}
		}
		break;
	case 'w':
	case 'W':
		if (map1[x - 1][y] == 0 || map1[x - 1][y] == 3)
		{
			map1[x][y] -= 5;
			map1[x - 1][y] += 5;
		}
		else if (map1[x - 1][y] == 4 || map1[x - 1][y] == 7)
		{
			if (map1[x - 2][y] == 0 || map1[x - 2][y] == 3)
			{
				map1[x][y] -= 5;
				map1[x - 1][y] += 1;
				map1[x - 2][y] += 4;
			}
		}
		break;
	case 's':
	case 'S':
		if (map1[x + 1][y] == 0 || map1[x + 1][y] == 3)
		{
			map1[x][y] -= 5;
			map1[x + 1][y] += 5;
		}
		else if (map1[x + 1][y] == 4 || map1[x + 1][y] == 7)
		{
			if (map1[x + 2][y] == 0 || map1[x + 2][y] == 3)
			{
				map1[x][y] -= 5;
				map1[x + 1][y] += 1;
				map1[x + 2][y] += 4;
			}
		}
		break;
	case 'd':
	case 'D':
		if (map1[x][y + 1] == 0 || map1[x][y + 1] == 3)
		{
			map1[x][y] -= 5;
			map1[x][y + 1] += 5;
		}
		else if (map1[x][y + 1] == 4 || map1[x][y + 1] == 7)
		{
			if (map1[x][y + 2] == 0 || map1[x][y + 2] == 3)
			{
				map1[x][y] -= 5;
				map1[x][y + 1] += 1;
				map1[x][y + 2] += 4;
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
		for (int j = 0; j < 15; j++)
		{
			if (map1[i][j] == 7)
				m++;
		}
	}
	if (m == 6)
	{
		MessageBox(NULL, L"��Ӯ�ˣ�", L"23333", MB_OK);
		return 1;
	}
}