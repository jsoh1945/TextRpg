#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <Windows.h>

using namespace std;

#define ���� 1
#define ���� 2
#define ������ 3
#define �ü� 4

bool gameFlag = true;
int PlayerChoice = 0;

int startMSG();
void error_msg(const string err);
int PlayerChoosing();

class Player {
	int HP;
	int MP;
	int Level;
	float CR;
	int CD;
	bool isDead;
	int Class;
public:
	Player(){
		HP = 100;
		MP = 100;
		Level = 1;
		CR = 0;
		CD = 100;
		isDead = false;
		Class = 0;
	}
	void damaged(int DMG) {
		HP = HP - DMG;
	}
	void heal(int DMG) {
		HP = HP + DMG;
	}
	void setClass(int C) {
		Class = C;
	}
	void LevelUp() {

	}
	int getHP() {
		return HP;
	}
	int getMP() {
		return MP;
	}
	int getLevel() {
		return Level;
	}
	float getCri() {
		return CR;
	}
	int getCD() {
		return CD;
	}
	int getClass() {
		return Class;
	}
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

class Slime : Monster {
	Monster S;
public:
	Slime() {
		S.setHP(50);
	}
	int getHP() {
		return S.getHP();
	}
};

void showStatInfo(Player* P);

int main()
{
	Player P;
	while (gameFlag) {
		//���� �޼���
		if (!startMSG()) {
			continue;
		}
		string settingMSG = "�������Դϴ�.";
		for (int i = 0; i < 3; ++i) {
			cout << settingMSG;
			settingMSG = settingMSG + " .";
			Sleep(1000);
			system("cls");
		}
		//��������
		switch (PlayerChoice) {
		case ����:
			P.setClass(����);
			break;
		case ����:
			P.setClass(����);
			break;
		case ������:
			P.setClass(������);
			break;
		case �ü�:
			P.setClass(�ü�);
		}
		cout << "���� �Ϸ�." << endl;
		Sleep(2000);
		system("cls");
		//���� ��ȯ
		cout << "������ �����߽��ϴ�. ������ �Ͻðڽ��ϱ�?" << endl;
		cout << "1. �ʵ�� ������, 2. ������ Ȯ��, 3. �׸��α�" << endl;
		if (!PlayerChoosing()) {
			continue;
		}
		else {
			switch (PlayerChoice) {
			case 1:
				break;
			case 2:
				showStatInfo(&P);
				break;
			case 3:
				gameFlag = 0;
				continue;
			}
		}
		Sleep(2000);

		
	}
}

void error_msg(string err) {
	cout << "[����]: " << err << endl;
}

int startMSG() {
	cout << "---------------------------------" << endl;
	cout << "|   �ؽ�Ʈ �������� �����մϴ�   |" << endl;
	cout << "---------------------------------" << endl;
	Sleep(1000);
	cout << "--------------------------------------------" << endl;
	cout <<"| [TextRPG] ĳ���͸� �������ֽñ� �ٶ��ϴ� |" << endl;
	cout << "--------------------------------------------" << endl;
	Sleep(1000);
	cout << "[1. ����], [2. ����], [3. ������], [4. �ü�]" << endl;
	if (!(cin >> PlayerChoice)) {
		cin.clear();
		cin.ignore(256,'\n');
		error_msg("���ڸ� �Է°����մϴ�.");
		Sleep(1000);
		system("cls");
		return 0;
	}
	else if (PlayerChoice < 0 || PlayerChoice > 4) {
		error_msg("1~4������ ���ڸ� �Է°����մϴ�.");
		Sleep(1000);
		system("cls");
		return 0;
	}
	else {
		system("cls");
		switch (PlayerChoice) {
		case ����:
			cout << "-----------------------------" << endl;
			cout << "|   ���縦 �����ϼ̽��ϴ�   |" << endl;
			cout << "-----------------------------" << endl;
			break;
		case ����:
			cout << "-----------------------------" << endl;
			cout << "|   ������ �����ϼ̽��ϴ�   |" << endl;
			cout << "-----------------------------" << endl;
			break;
		case ������:
			cout << "-------------------------------" << endl;
			cout << "|   �����縦 �����ϼ̽��ϴ�   |" << endl;
			cout << "-------------------------------" << endl;
			break;
		case �ü�:
			cout << "-----------------------------" << endl;
			cout << "|   �ü��� �����ϼ̽��ϴ�   |" << endl;
			cout << "-----------------------------" << endl;
			break;
		}
		Sleep(2000);
		system("cls");
		return PlayerChoice;
	}
}

int PlayerChoosing() {
	if (!(cin >> PlayerChoice)) {
		cin.clear();
		cin.ignore(256, '\n');
		error_msg("���ڸ� �Է°����մϴ�.");
		Sleep(1000);
		system("cls");
		return 0;
	}
	else {
		return PlayerChoice;
	}
}

void showStatInfo(Player* P) {
	cout << "-----------------------" << endl;
	cout << "|     Player Info     |" << endl;
	cout << "-----------------------" << endl;
	cout << "|  ����: " << P->getClass() << endl;
	cout << "-----------------------" << endl;
	cout << "|  HP: " << P->getHP() << endl;
	cout << "-----------------------" << endl;
	cout << "|  MP: " << P->getMP() << endl;
	cout << "-----------------------" << endl;
	cout << "|  ����: " << P->getLevel() << endl;
	cout << "-----------------------" << endl;
	cout << "|  ũ��Ƽ��: " << P->getCri() << endl;
	cout << "-----------------------" << endl;
	cout << "| ũ��Ƽ�� �����: " << P->getCD() << endl;
	cout << "-----------------------" << endl;

} 
