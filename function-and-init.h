#pragma once
//推箱子小游戏
//作者 kk rr
//最后修改日期：17-11-28
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <fstream>
using namespace std;
//定义地图
int map[11][15];
//关卡数
int check_point_num = 0;
//图片对象
IMAGE nothing, wall, box, human, dbox, ending;
//加载地图文档
void loadmapp();
//画地图
void dmap();
//通关
int win();
//加载图片
void loadimage();
//玩法操作
void play();
