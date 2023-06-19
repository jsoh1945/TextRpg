#pragma once
#include "usingClass.h"
#include <Windows.h>
#include <conio.h>
enum ClassSelect {
	Class_Start,
	����,
	����,
	������,
	�ü�,
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
void TextRPG_Text();
void showStatInfo(int& gameFlag, int& LastFlag, Player* P);
void showStatInfoG(Player* P);
int PlayerChoosing(); 
void error_msg(std::string err);
int startMSG();
void showInventory(int& gameFlag, int& LastFlag, Player* P);
void BattleWithMonster(int& gameFlag, int& LastFlag, Player* P);
void FindMonster(int& gameFlag, int& LastFlag, Player* P);