#include "usingClass.h"
//Player

Player::Player() {
	HP = 100;
	MP = 100;
	Level = 1;
	CR = 0;
	CD = 100;
	isDead = false;
	Class = "";
	for (int i = 0; i < MAX_INVEN_SLOT; ++i) {
		if (i == 0) {
			P_Inven.itemName[i] = "°ñµå";
			P_Inven.NumberOfItem[i] = 0;
			continue;
		}
		P_Inven.itemName[i] = "NONE";
		P_Inven.NumberOfItem[i] = 0;
	}
}
void Player::damaged(int DMG) {
	HP = HP - DMG;
}
void Player::heal(int DMG) {
	HP = HP + DMG;
}
void Player::setClass(std::string C) {
	Class = C;
}
void Player::LevelUp() {
	Level += 1;
}
int Player::getHP() {
	return HP;
}
int Player::getMP() {
	return MP;
}
int Player::getLevel() {
	return Level;
}
float Player::getCri() {
	return CR;
}
int Player::getCD() {
	return CD;
}
std::string Player::getInvenItemName(int n){
	return P_Inven.itemName[n];
}
int Player::getInvenNumberOfItem(int n){
	return P_Inven.NumberOfItem[n];
}
std::string Player::getClass() {
	return Class;
}