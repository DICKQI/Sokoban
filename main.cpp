#include "function-and-init.h"
const int WIDTH = 550, HEIGHT = 480;
//������
int main()
{
	loadmapp();
	initgraph(WIDTH, HEIGHT);
	welcome();
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
//��ӭ����
void welcome()
{
	cleardevice();
	loadimage(&bk, _T("./bk.jpg"), 550, 480);
	putimage(0, 0, &bk);
	setcolor(YELLOW);
	setfont(16, 0, _T("����"));
	outtextxy(225, 125, _T("ALGЭ���Ʒ"));
	setfont(64, 0, _T("����"));
	outtextxy(120, 50, _T("��������Ϸ"));
	setfont(16, 0, _T("����"));
	int c = 255;
	while (!_kbhit()) {
		setcolor(RGB(c, 0, 0));
		outtextxy(230, 400, _T("�����������"));
		c -= 88;
		if (c < 0) {
			c = 255;
		}
		Sleep(120);
	}
	_getch();
	cleardevice();
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
				if (direction == 1) {
					putimage(j * 30, i * 30, &lehuman);
				}
				else if (direction == 2) {
					putimage(j * 30, i * 30, &rihuman);
				}
				else if (direction == 3) {
					putimage(j * 30, i * 30, &uphuman);
				}
				else if (direction == 4) {
					putimage(j * 30, i * 30, &dohuman);
				}
				break;
			case 7:
				putimage(j * 30, i * 30, &dbox);
				break;
			case 8:
				if (direction == 1) {
					putimage(j * 30, i * 30, &lehuman);
				}
				else if (direction == 2) {
					putimage(j * 30, i * 30, &rihuman);
				}
				else if (direction == 3) {
					putimage(j * 30, i * 30, &uphuman);
				}
				else if (direction == 4) {
					putimage(j * 30, i * 30, &dohuman);
				}
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
	//�ҵ�������
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
	if (_kbhit) {
		ch = _getch();
		switch (ch)
		{
		case 'a':
		case 'A':
			direction = 1;
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
			direction = 3;
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
			direction = 4;
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
			direction = 2;
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

}
//����ͼƬ
void loadimage()
{
	loadimage(&wall, _T("./WALL.jpg"), 30, 30);
	loadimage(&ending, _T("./ENDPOINT.jpg"), 30, 30);
	loadimage(&box, _T("./BOX.jpg"), 30, 30);
	loadimage(&dbox, _T("./DARKBOX.jpg"), 30, 30);
	loadimage(&lehuman, _T("./lehuman.jpg"), 30, 30);
	loadimage(&rihuman, _T("./rihuman.jpg"), 30, 30);
	loadimage(&uphuman, _T("./uphuman.jpg"), 30, 30);
	loadimage(&dohuman, _T("./dohuman.jpg"), 30, 30);
}
//���ص�ͼ�ļ�
void loadmapp()
{
	if (check_point_num == 0) {
		ifstream is("1.txt");
		maps = 6;
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 15; j++) {
				is >> map[i][j];
			}
		}
		is.close();
	}
	else if (check_point_num == 1) {
		maps = 4;
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
	int cnt = 0;
	for (int i = 0; i < 11; i++){
		for (int j = 0; j < 15; j++){
			if (map[i][j] == 7)
				cnt++;
		}
	}
	if (cnt == maps)
	{
		setbkcolor(BLACK);
		cleardevice();
		setcolor(GREEN);
		setfont(25, 0, _T("����"));
		outtextxy(WIDTH / 2 - 100, HEIGHT / 2 - 50, _T("��ϲ��,ͨ���ˣ�"));
		_getch();
		outtextxy(WIDTH / 2 - 120, (HEIGHT / 2) - 50, _T("����Y��һ�����������˳�"));
		int key;
		key = _getch();
		if (key == 'y' || key == 'Y') {
			check_point_num++;
			loadmapp();
			setbkcolor(WHITE);
			return 1;
		}
		else {
			outtextxy(WIDTH / 2 - 100, HEIGHT / 2 - 50, _T("��ϲ��,ͨ���ˣ�"));
			closegraph();
			exit(0);
		}

	}
}