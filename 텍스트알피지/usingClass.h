#pragma once
#include <string>
#include <array>
#include <iostream>
#include <random>

#define MAX_INVEN_SLOT 20
struct Inventory {
	std::array<std::string, MAX_INVEN_SLOT> itemName{};
	std::array<int, MAX_INVEN_SLOT> NumberOfItem{};
};
class Player {
	int HP;
	int MP;
	int Level;
	int ATT;
	int DEF;
	int EXP;

	float CR;
	int CD;
	bool isDead;
	std::string Class;
	Inventory P_Inven;
public:
	Player();
	void damaged(int DMG);
	void heal(int DMG);
	void setClass(std::string C);
	void LevelUp();
	int getHP();
	int getMP();
	int getLevel();
	float getCri();
	int getCD();
	int getEXP();
	void expGain(int e);
	std::string getInvenItemName(int n);
	int getInvenNumberOfItem(int n);
	std::string getClass();
};

class Monster {
	std::string name;
	//±âº» ½ºÅÝ
	int HP;
	int MP;
	int Level;
	int ATT;
	int DEF;

	bool isDead;
public:
	Monster(Player* P);
	void getDamaged(int D);
	void getHeal(int D);
	int getHP();
	void showStat();
};