#pragma once
//������С��Ϸ
//���� kk rr
//����޸����ڣ�17-11-29
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <fstream>
using namespace std;
//�����ͼ
int map[11][15];
//���ִ��淽�� 1�� 2�� 3�� 4��
int direction = 4;//Ĭ������
//�ؿ���
int check_point_num = 0;
int maps;
//ͼƬ����
IMAGE nothing, wall, box, dbox, ending, lehuman, rihuman, uphuman, dohuman;
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