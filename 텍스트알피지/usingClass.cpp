#include "usingClass.h"
//Player

Player::Player() {
	//�⺻ ����
	HP = 100;
	MP = 100;
	Level = 1;
	ATT = 10;
	DEF = 5;
	EXP = 0;
	//�ΰ� ����
	CR = 0;
	CD = 100;
	isDead = false;
	Class = "";
	for (int i = 0; i < MAX_INVEN_SLOT; ++i) {
		if (i == 0) {
			P_Inven.itemName[i] = "���";
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
void Player::expGain(int e) {
	EXP += e;
}
void Player::setClass(std::string C) {
	Class = C;
}
void Player::LevelUp() {
	Level += 1;
	ATT += 5;
	DEF += 2;
	HP += 20;
	MP += 10;
	if (Class == "����") {
		ATT += 3;
		DEF += 2;
		return;
	}
	if (Class == "����") {
		ATT += 4;
		DEF += 1;
		return;
	}
	if (Class == "������") {
		ATT += 4;
		DEF += 1;
		return;
	}
	if (Class == "�ü�") {
		ATT += 4;
		DEF += 1;
		return;
	}
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
int Player::getEXP() {
	return EXP;
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


//Slime
Monster:: Monster(Player* P) {
	std::random_device rdM;
	std::uniform_int_distribution<int> uid(0, 100);

	if (P->getLevel() <= 10) {
		name = "������";
		HP = 40;
		MP = 0;
		ATT = 1;
		DEF = 3;
		Level = uid(rdM) % 10+1;
	}
	else if (P->getLevel() <= 20) {
		name = "��";
		HP = 200;
		MP = 0;
		ATT = 10;
		DEF = 10;
		Level = uid(rdM) % 20+1;
	}
	else if (P->getLevel() <= 30) {
		name = " ";
		HP = 300;
		MP = 0;
		ATT = 30;
		DEF = 30;
		Level = uid(rdM) % 30+1;
	}
	else if (P->getLevel() <= 40) {
		name = " ";
		HP = 0;
		MP = 0;
		ATT = 0;
		DEF = 0;
		Level = uid(rdM) % 40+1;
	}
	else {
		name = "������";
		HP = 0;
		MP = 0;
		ATT = 0;
		DEF = 0;
		Level = uid(rdM) % 50+1;
	}
}
void Monster::getDamaged(int D) {
	HP -= D;
	if (HP <= 0) {
		isDead = true;
	}
}
void Monster::getHeal(int D) {
	HP += D;
}
int Monster::getHP() {
	return HP;
}
void Monster::showStat() {
	std::cout << "------------------------" << std::endl;
	std::cout << "|     Monster Info     |" << std::endl;
	std::cout << "------------------------" << std::endl;
	std::cout << "|  �̸�: " << name << std::endl;
	std::cout << "------------------------" << std::endl;
	std::cout << "|  HP: " << HP << std::endl;
	std::cout << "------------------------" << std::endl;
	std::cout << "|  MP: " << MP << std::endl;
	std::cout << "------------------------" << std::endl;
	std::cout << "|  ����: " << Level << std::endl;
	std::cout << "------------------------" << std::endl;
	std::cout << "|  ���ݷ�: " << ATT << std::endl;
	std::cout << "------------------------" << std::endl;
	std::cout << "|  ����: " << DEF << std::endl;
	std::cout << "------------------------" << std::endl;
}