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
//ͼƬ����
IMAGE nothing, wall, end, box, human, dbox;

//����ͼ
void dmap();
//ͨ��
int win();
//����ͼƬ
void loadimage();
//�淨����
void play();
//������
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
	MessageBox(NULL, L"�밴������˳�", L"��ϲ", MB_OK);
	getchar();
	return 0;
}
