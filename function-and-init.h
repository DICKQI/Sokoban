#pragma once
//������С��Ϸ
//���� kk rr
//����޸����ڣ�17-11-28
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <fstream>
using namespace std;
//�����ͼ
int map[11][15];
//�ؿ���
int check_point_num = 0;
//ͼƬ����
IMAGE nothing, wall, box, human, dbox, ending;
//����ͼ
void dmap();
//���ص�ͼ
void loadmapp();
//ͨ��
int win();
//����ͼƬ
void loadimage();
//�淨����
void play();