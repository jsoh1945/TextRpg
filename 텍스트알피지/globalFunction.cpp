#include "globalFunction.h"

std::uniform_int_distribution<int> randfrom0to99(0, 99);
std::random_device rd;
std::mt19937 gen(rd());


void TextRPG_Text() {
	std::cout << "---------------------------------" << std::endl;
	std::cout << "|         텍스트 알피지         |" << std::endl;
	std::cout << "---------------------------------" << std::endl;
}

void error_msg(std::string err) {
	std::cout << "[에러]: " << err << std::endl;
}

void showStatInfoG(Player* P) {
	TextRPG_Text();
	std::cout << "-----------------------" << std::endl;
	std::cout << "|     Player Info     |" << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "|  직업: " << P->getClass() << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "|  HP: " << P->getHP() << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "|  MP: " << P->getMP() << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "|  레벨: " << P->getLevel() << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "|  공격력: " << P->getATT() << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "|  방어력: " << P->getDEF() << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "|  크리티컬: " << P->getCri() << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "| 크리티컬 대미지: " << P->getCD() << std::endl;
	std::cout << "-----------------------" << std::endl;
}

void showStatInfo(int& gameFlag, int& LastFlag, Player* P) {
	while (gameFlag == STAT_INFO) {
		showStatInfoG(P);
		if (LastFlag == TOWN) {
			std::cout << "[1. 마을로 가기], [2. 게임 종료]" << std::endl;
			if (!PlayerChoosing()) {
				continue;
			}
			switch (PlayerChoice) {
			case 1:
				gameFlag = TOWN;
				LastFlag = 0;
				PlayerChoice = 0;
				system("cls");
				break;
			case 2:
				gameFlag = END;
				LastFlag = 0;
				PlayerChoice = 0;
				break;
			}
		}
		if (LastFlag == FIELD) {
			std::cout << "[1. 필드로 가기], [2. 게임 종료]" << std::endl;
			if (!PlayerChoosing()) {
				continue;
			}
			switch (PlayerChoice) {
			case 1:
				gameFlag = FIELD;
				LastFlag = 0;
				PlayerChoice = 0;
				system("cls");
				break;
			case 2:
				gameFlag = END;
				LastFlag = 0;
				PlayerChoice = 0;
				break;
			}
		}
	}
}

int PlayerChoosing() {
	if (!(std::cin >> PlayerChoice)) {
		std::cin.clear();
		std::cin.ignore(256, '\n');
		error_msg("숫자만 입력가능합니다.");
		Sleep(1000);
		system("cls");
		return 0;
	}
	else {
		return PlayerChoice;
	}
}

int startMSG() {
	std::cout << "---------------------------------" << std::endl;
	std::cout << "|   텍스트 알피지를 시작합니다   |" << std::endl;
	std::cout << "---------------------------------" << std::endl;
	Sleep(1000);
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "| [TextRPG] 캐릭터를 선택해주시기 바랍니다 |" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	Sleep(1000);
	std::cout << "[1. 전사], [2. 도적], [3. 마법사], [4. 궁수]" << std::endl;
	if (!(std::cin >> PlayerChoice)) {
		std::cin.clear();
		std::cin.ignore(256, '\n');
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
			std::cout << "-----------------------------" << std::endl;
			std::cout << "|   전사를 선택하셨습니다   |" << std::endl;
			std::cout << "-----------------------------" << std::endl;
			break;
		case 도적:
			std::cout << "-----------------------------" << std::endl;
			std::cout << "|   도적을 선택하셨습니다   |" << std::endl;
			std::cout << "-----------------------------" << std::endl;
			break;
		case 마법사:
			std::cout << "-------------------------------" << std::endl;
			std::cout << "|   마법사를 선택하셨습니다   |" << std::endl;
			std::cout << "-------------------------------" << std::endl;
			break;
		case 궁수:
			std::cout << "-----------------------------" << std::endl;
			std::cout << "|   궁수를 선택하셨습니다   |" << std::endl;
			std::cout << "-----------------------------" << std::endl;
			break;
		}
		Sleep(2000);
		system("cls");
		return PlayerChoice;
	}
}

void showInventory(int& gameFlag, int& LastFlag, Player* P) {
	TextRPG_Text();
	while (gameFlag == CHECK_INVENTORY) {
		P->getInventory().showList();
		if (LastFlag == FIELD) {
			std::cout << "[1. 필드로 가기]" << std::endl;
			if (!PlayerChoosing()) {
				continue;
			}
			switch (PlayerChoice) {
			case 1:
				gameFlag = FIELD;
				LastFlag = 0;
				PlayerChoice = 0;
				system("cls");
				break;
			default:
				std::cout << "다시 선택해 주세요" << std::endl;
				Sleep(2000);
				system("cls");
				continue;
			}
		}
		if (LastFlag == TOWN) {
			std::cout << "[1. 마을로 가기]" << std::endl;
			if (!PlayerChoosing()) {
				continue;
			}
			switch (PlayerChoice) {
			case 1:
				gameFlag = TOWN;
				LastFlag = 0;
				PlayerChoice = 0;
				system("cls");
				break;
			default:
				std::cout << "다시 선택해 주세요" << std::endl;
				Sleep(2000);
				system("cls");
				continue;
			}
		}

	}
}

void BattleWithMonster(int& gameFlag, int& LastFlag, Player* P) {
	std::uniform_int_distribution<> dmg(1, P->getATT());
	std::uniform_int_distribution<> crit(0, P->getCri());
	TextRPG_Text();
	int PlayerDMG = 0;
	int MonsterDMG = 0;
	bool isCrit = false;
	Monster M(P);
	while (gameFlag == BATTLE) {
		if (M.getHP() < 0) {
			std::uniform_int_distribution<> gold(M.getLevel(), M.getLevel() + 50);
			int getGold = gold(gen);
			TextRPG_Text();
			std::cout << "몬스터와의 전투에서 승리했습니다!\n";
			std::cout << "전리품을 획득했습니다 (" << getGold << "원)\n";
			P->getInventory().pushItem("골드", getGold);
			std::cout << "계속 하려면 아무키나 입력하세요\n";
			_getch();
			gameFlag = FIELD;
			break;
		}
		M.showStat();
		std::cout << std::endl;
		showStatInfoG(P);
		std::cout << "[1. 공격한다], [2. 방어한다], [3. 도망친다]" << std::endl;
		PlayerChoosing();
		
		switch (PlayerChoice) {
		case 1:

			PlayerDMG = dmg(gen);
			if (crit(gen) >= 50) {
				isCrit = true;
			} else {
				isCrit = false;
			}
			if (isCrit) {
				std::cout << "몬스터를 " << PlayerDMG * 2 << "대미지로 타격했습니다\n";
				M.getDamaged(PlayerDMG * 2);
				
			} else {
				std::cout << "몬스터를 " << PlayerDMG << "대미지로 타격했습니다\n";
				M.getDamaged(PlayerDMG);
			}
			Sleep(1000);
			system("cls");
			break;
		case 2:
			break;
		case 3:
			gameFlag = FIELD;
			system("cls");
			break;
		}
		


	}
}

void FindMonster(int& gameFlag, int& LastFlag, Player* P) {
	system("cls");
	int finding = randfrom0to99(gen);
	while (gameFlag == FIND_MONSTER) {
		TextRPG_Text();
		std::cout << "몬스터를 찾는중입니다. . ." << std::endl;
		Sleep(2000);
		if (finding >= 49) {
			std::cout << "몬스터를 찾았습니다." << std::endl;
			std::cout << "전투하시겠습니까?" << std::endl;
			std::cout << "[1. 전투한다], [2. 도망친다]" << std::endl;
			PlayerChoosing();
			switch (PlayerChoice) {
			case 1:
				std::cout << "몬스터와 전투합니다" << std::endl;
				LastFlag = FIND_MONSTER;
				gameFlag = BATTLE;
				Sleep(1000);
				system("cls");
				BattleWithMonster(gameFlag, LastFlag, P);
				LastFlag = 0;
				gameFlag = FIELD;
				PlayerChoice = 0;
				system("cls");
				break;
			case 2:
				std::cout << "몬스터로부터 도망쳐 다시 필드로 갑니다" << std::endl;
				Sleep(2000);
				LastFlag = 0;
				gameFlag = FIELD;
				PlayerChoice = 0;
				system("cls");
				break;
			}
		}
		else {
			std::cout << "몬스터를 찾지 못하였습니다." << std::endl;
			Sleep(2000);
			LastFlag = 0;
			gameFlag = FIELD;
			PlayerChoice = 0;
			system("cls");
			break;
		}
	}
}