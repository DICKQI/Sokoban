#pragma once
//推箱子小游戏
//作者 kk rr
//最后修改日期：17-11-29
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <fstream>
using namespace std;
//定义地图
int map[11][15];
//数字代替方向 1左 2右 3上 4下
int direction = 4;//默认向下
//关卡数
int check_point_num = 0;
int maps;
//图片对象
IMAGE nothing, wall, box, dbox, ending, lehuman, rihuman, uphuman, dohuman;
//画地图
void dmap();
//加载地图
void loadmapp();
//通关
int win();
//加载图片
void loadimage();
//玩法操作
void play();