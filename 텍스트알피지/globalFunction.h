#pragma once
#include "usingClass.h"
#include <iostream>
#include <Windows.h>
enum ClassSelect {
	Class_Start,
	전사,
	도적,
	마법사,
	궁수,
	Class_End
};

enum gameFlag {
	END,
	MAIN,
	TOWN,
	FIELD,
	FIND_MONSTER,
	BATTLE,
	CHECK_INVENTORY,
	SHOP,
	STAT_INFO
};

extern int PlayerChoice;
extern int flag;
extern int LastFlag;
void showStatInfo(int& gameFlag, int& LastFlag, Player* P);
void showStatInfoG(Player* P);
int PlayerChoosing(); 
void error_msg(std::string err);
int startMSG();
void showInventory(int& gameFlag, int& LastFlag, Player* P);