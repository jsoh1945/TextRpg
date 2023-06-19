#pragma once
#include <string>
#include <array>
#include <unordered_map>
#include <iostream>
#include <random>

#define MAX_INVEN_SLOT 20
class Inventory {
	std::unordered_map<std::string,int> items{};
public:
	Inventory();
	void pushItem(std::string item, int amount);
	void popItem(std::string item, int amount);
	std::pair<std::string, int> getItemInfo(std::string name);
	void showList();
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
	int getATT();
	int getDEF();
	void expGain(int e);
	Inventory& getInventory();
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
	int getLevel();
	void showStat();
};