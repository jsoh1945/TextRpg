#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <Windows.h>

using namespace std;

#define 전사 1
#define 도적 2
#define 마법사 3
#define 궁수 4

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
		//시작 메세지
		if (!startMSG()) {
			continue;
		}
		string settingMSG = "세팅중입니다.";
		for (int i = 0; i < 3; ++i) {
			cout << settingMSG;
			settingMSG = settingMSG + " .";
			Sleep(1000);
			system("cls");
		}
		//전직설정
		switch (PlayerChoice) {
		case 전사:
			P.setClass(전사);
			break;
		case 도적:
			P.setClass(도적);
			break;
		case 마법사:
			P.setClass(마법사);
			break;
		case 궁수:
			P.setClass(궁수);
		}
		cout << "세팅 완료." << endl;
		Sleep(2000);
		system("cls");
		//마을 소환
		cout << "마을에 도착했습니다. 무엇을 하시겠습니까?" << endl;
		cout << "1. 필드로 나가기, 2. 프로필 확인, 3. 그만두기" << endl;
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
	cout << "[에러]: " << err << endl;
}

int startMSG() {
	cout << "---------------------------------" << endl;
	cout << "|   텍스트 알피지를 시작합니다   |" << endl;
	cout << "---------------------------------" << endl;
	Sleep(1000);
	cout << "--------------------------------------------" << endl;
	cout <<"| [TextRPG] 캐릭터를 선택해주시기 바랍니다 |" << endl;
	cout << "--------------------------------------------" << endl;
	Sleep(1000);
	cout << "[1. 전사], [2. 도적], [3. 마법사], [4. 궁수]" << endl;
	if (!(cin >> PlayerChoice)) {
		cin.clear();
		cin.ignore(256,'\n');
		error_msg("숫자만 입력가능합니다.");
		Sleep(1000);
		system("cls");
		return 0;
	}
	else if (PlayerChoice < 0 || PlayerChoice > 4) {
		error_msg("1~4사이의 숫자만 입력가능합니다.");
		Sleep(1000);
		system("cls");
		return 0;
	}
	else {
		system("cls");
		switch (PlayerChoice) {
		case 전사:
			cout << "-----------------------------" << endl;
			cout << "|   전사를 선택하셨습니다   |" << endl;
			cout << "-----------------------------" << endl;
			break;
		case 도적:
			cout << "-----------------------------" << endl;
			cout << "|   도적을 선택하셨습니다   |" << endl;
			cout << "-----------------------------" << endl;
			break;
		case 마법사:
			cout << "-------------------------------" << endl;
			cout << "|   마법사를 선택하셨습니다   |" << endl;
			cout << "-------------------------------" << endl;
			break;
		case 궁수:
			cout << "-----------------------------" << endl;
			cout << "|   궁수를 선택하셨습니다   |" << endl;
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
		error_msg("숫자만 입력가능합니다.");
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
	cout << "|  직업: " << P->getClass() << endl;
	cout << "-----------------------" << endl;
	cout << "|  HP: " << P->getHP() << endl;
	cout << "-----------------------" << endl;
	cout << "|  MP: " << P->getMP() << endl;
	cout << "-----------------------" << endl;
	cout << "|  레벨: " << P->getLevel() << endl;
	cout << "-----------------------" << endl;
	cout << "|  크리티컬: " << P->getCri() << endl;
	cout << "-----------------------" << endl;
	cout << "| 크리티컬 대미지: " << P->getCD() << endl;
	cout << "-----------------------" << endl;

} 
