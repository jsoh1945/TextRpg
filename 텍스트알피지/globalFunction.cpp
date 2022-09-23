#include "globalFunction.h"

void error_msg(std::string err) {
	std::cout << "[에러]: " << err << std::endl;
}

void showStatInfoG(Player* P) {
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
				PlayerChoice = 0;
				system("cls");
				break;
			case 2:
				gameFlag = END;
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
				PlayerChoice = 0;
				system("cls");
				break;
			case 2:
				gameFlag = END;
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

void showInventroy(int& gameFlag, int& LastFlag, Player* P) {
	while (gameFlag == CHECK_INVENTORY) {
		for (int i = 0; i < MAX_INVEN_SLOT; ++i) {
			if (i == 0) {
				std::cout << "슬롯 " << i + 1 << ": " << P->getInvenItemName(i) << " - " << P->getInvenNumberOfItem(i) << "원" << std::endl;
				continue;
			}
			std::cout << "슬롯 " << i + 1 << ": " << P->getInvenItemName(i) << " - " << P->getInvenNumberOfItem(i) << "개" << std::endl;
		}
		if (LastFlag == FIELD) {
			std::cout << "[1. 필드로 가기]" << std::endl;
			if (!PlayerChoosing()) {
				continue;
			}
			switch (PlayerChoice) {
			case 1:
				gameFlag = FIELD;
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

		}

		break;
	}
}