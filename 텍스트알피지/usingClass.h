#pragma once
#include <string>
#include <array>

#define MAX_INVEN_SLOT 20
struct Inventory {
	std::array<std::string, MAX_INVEN_SLOT> itemName{};
	std::array<int, MAX_INVEN_SLOT> NumberOfItem{};
};
class Player {
	int HP;
	int MP;
	int Level;
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
	std::string getInvenItemName(int n);
	int getInvenNumberOfItem(int n);
	std::string getClass();
};

class Monster {
	int HP;
	int MP;
	int Level;
	bool isDead;
public:
	Monster() :HP{ 0 }, MP{ 0 }, Level{ 0 }, isDead{ false } {}
	void setHP(int setHP) {
		HP = setHP;
	}
	int getHP() {
		return HP;
	}
};