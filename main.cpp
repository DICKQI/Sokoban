#include "function-and-init.h"
const int WIDTH = 600, HEIGHT = 480;
//������
int main()
{
	loadmapp();
	initgraph(WIDTH, HEIGHT);
	setbkcolor(WHITE);
	loadimage();
	cleardevice();
	while (1)
	{
		BeginBatchDraw();
		cleardevice();
		dmap();
		EndBatchDraw();
		win();
		play();
	}
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
				putimage(j * 30, i * 30, &ending);
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
		if (map[x - 1][y] == 0 || map[x - 1][y] == 3)
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
	loadimage(&ending, _T("./ENDPOINT.jpg"), 30, 30);
	loadimage(&box, _T("./BOX.jpg"), 30, 30);
	loadimage(&human, _T("./character.jpg"), 30, 30);
	loadimage(&dbox, _T("./DARKBOX.jpg"), 30, 30);
}
//���ص�ͼ�ļ�
void loadmapp()
{
	if (check_point_num == 0) {
		ifstream is("1.txt");
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 15; j++) {
				is >> map[i][j];
			}
		}
		is.close();
	}
	else if (check_point_num == 1) {
		ifstream is("2.txt");
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 15; j++) {
				is >> map[i][j];
			}
		}
		is.close();
	}
	else if (check_point_num == 2) {
		ifstream is("3.txt");
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 15; j++) {
				is >> map[i][j];
			}
		}
		is.close();
	}
	else if (check_point_num == 3) {
		ifstream is("4.txt");
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 15; j++) {
				is >> map[i][j];
			}
		}
		is.close();
	}
	else if (check_point_num == 4) {
		ifstream is("5.txt");
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 15; j++) {
				is >> map[i][j];
			}
		}
		is.close();
	}
	else if (check_point_num == 5) {
		ifstream is("6.txt");
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 15; j++) {
				is >> map[i][j];
			}
		}
		is.close();
	}
	return;
}
//ͨ����ʾ
int win()
{
	int m = 0;
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (map[i][j] == 7)
				m++;
		}
	}
	if (m == 6)
	{
		cleardevice();
		setbkcolor(BLACK);
		outtextxy(WIDTH / 2, HEIGHT / 2, _T("��ϲ��,ͨ���ˣ�"));
		outtextxy(WIDTH / 2, (HEIGHT / 2) - 1, _T("����Y��һ�����������˳�"));
		int key;
		key = _getch();
		if (key == 'y' || key == 'Y') {
			check_point_num++;
			loadmapp();
			setbkcolor(WHITE);
			return 1;
		}
		else {
			closegraph();
			exit(0);
		}

	}
}