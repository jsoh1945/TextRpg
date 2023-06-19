#include "usingClass.h"
#include <algorithm>
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
Inventory& Player::getInventory()
{
	return P_Inven;
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

int Player::getATT()
{
	return ATT;
}

int Player::getDEF()
{
	return DEF;
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
int Monster::getLevel()
{
	return Level;
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

Inventory::Inventory()
{
	items.insert(std::make_pair("���", 0));
}

void Inventory::pushItem(std::string item, int amount)
{
	auto loc = items.find(item);
	if (loc == items.end()) {
		items.insert(std::make_pair(item, amount));
		std::cout << "�ش� �������� ���� �κ��丮�� �߰��մϴ�\n";
	}
	else {
		(*loc).second += amount;
		std::cout << item << " +" << amount <<"\n";
	}
}

void Inventory::popItem(std::string item, int amount)
{
	auto loc = items.find(item);
	if (loc != items.end()) {
		if (amount > (*loc).second){
			std::cout << "�ش� �������� ������ �Է� ������ �����ϴ�\n";
			exit;
		}
		(*loc).second -= amount;
		std::cout << item << "�� ������" << amount<<"�� �پ������ϴ�\n";
		if ((*loc).second == 0) {
			items.erase(item);
			std::cout << item << "�� ������ 0�� �Ǿ� �κ��丮���� ���ŵ˴ϴ�\n";
		}
	}
	else {
		std::cout << "�ش� �������� ã�� �� �����ϴ�\n";
	}

}

std::pair<std::string, int> Inventory::getItemInfo(std::string name)
{
	auto loc = items.find(name);
	if (loc != items.end()) {
		return *loc;
	}
	else {
		std::cout << "�ش� �������� ã�� �� �����ϴ�.\n";
		return std::make_pair("NONE",0);
	}
}

void Inventory::showList()
{
	int loop = 1;
	for (std::pair<std::string, int> p : items) {
		std::cout << loop << ". " << p.first << ": " << p.second << "\n";
		++loop;
	}
}