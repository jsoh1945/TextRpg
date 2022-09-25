#include "globalFunction.h"

std::uniform_int_distribution<int> randfrom0to99(0, 99);
std::random_device rd;
std::mt19937 gen(rd());

void TextRPG_Text() {
	std::cout << "---------------------------------" << std::endl;
	std::cout << "|         �ؽ�Ʈ ������         |" << std::endl;
	std::cout << "---------------------------------" << std::endl;
}

void error_msg(std::string err) {
	std::cout << "[����]: " << err << std::endl;
}

void showStatInfoG(Player* P) {
	TextRPG_Text();
	std::cout << "-----------------------" << std::endl;
	std::cout << "|     Player Info     |" << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "|  ����: " << P->getClass() << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "|  HP: " << P->getHP() << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "|  MP: " << P->getMP() << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "|  ����: " << P->getLevel() << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "|  ũ��Ƽ��: " << P->getCri() << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "| ũ��Ƽ�� �����: " << P->getCD() << std::endl;
	std::cout << "-----------------------" << std::endl;
}

void showStatInfo(int& gameFlag, int& LastFlag, Player* P) {
	while (gameFlag == STAT_INFO) {
		showStatInfoG(P);
		if (LastFlag == TOWN) {
			std::cout << "[1. ������ ����], [2. ���� ����]" << std::endl;
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
			std::cout << "[1. �ʵ�� ����], [2. ���� ����]" << std::endl;
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
		error_msg("���ڸ� �Է°����մϴ�.");
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
	std::cout << "|   �ؽ�Ʈ �������� �����մϴ�   |" << std::endl;
	std::cout << "---------------------------------" << std::endl;
	Sleep(1000);
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "| [TextRPG] ĳ���͸� �������ֽñ� �ٶ��ϴ� |" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	Sleep(1000);
	std::cout << "[1. ����], [2. ����], [3. ������], [4. �ü�]" << std::endl;
	if (!(std::cin >> PlayerChoice)) {
		std::cin.clear();
		std::cin.ignore(256, '\n');
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
			std::cout << "-----------------------------" << std::endl;
			std::cout << "|   ���縦 �����ϼ̽��ϴ�   |" << std::endl;
			std::cout << "-----------------------------" << std::endl;
			break;
		case ����:
			std::cout << "-----------------------------" << std::endl;
			std::cout << "|   ������ �����ϼ̽��ϴ�   |" << std::endl;
			std::cout << "-----------------------------" << std::endl;
			break;
		case ������:
			std::cout << "-------------------------------" << std::endl;
			std::cout << "|   �����縦 �����ϼ̽��ϴ�   |" << std::endl;
			std::cout << "-------------------------------" << std::endl;
			break;
		case �ü�:
			std::cout << "-----------------------------" << std::endl;
			std::cout << "|   �ü��� �����ϼ̽��ϴ�   |" << std::endl;
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
		for (int i = 0; i < MAX_INVEN_SLOT; ++i) {
			if (i == 0) {
				std::cout << "���� " << i + 1 << ": " << P->getInvenItemName(i) << " - " << P->getInvenNumberOfItem(i) << "��" << std::endl;
				continue;
			}
			std::cout << "���� " << i + 1 << ": " << P->getInvenItemName(i) << " - " << P->getInvenNumberOfItem(i) << "��" << std::endl;
		}
		if (LastFlag == FIELD) {
			std::cout << "[1. �ʵ�� ����]" << std::endl;
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
				std::cout << "�ٽ� ������ �ּ���" << std::endl;
				Sleep(2000);
				system("cls");
				continue;
			}
		}
		if (LastFlag == TOWN) {
			std::cout << "[1. ������ ����]" << std::endl;
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
				std::cout << "�ٽ� ������ �ּ���" << std::endl;
				Sleep(2000);
				system("cls");
				continue;
			}
		}

	}
}

void BattleWithMonster(int& gameFlag, int& LastFlag, Player* P) {
	TextRPG_Text();
	
	Monster M(P);
	while (gameFlag == BATTLE) {
		M.showStat();
		std::cout << std::endl;
		showStatInfoG(P);
		PlayerChoosing();
	}
}

void FindMonster(int& gameFlag, int& LastFlag, Player* P) {
	system("cls");
	int finding = randfrom0to99(gen);
	while (gameFlag == FIND_MONSTER) {
		TextRPG_Text();
		std::cout << "���͸� ã�����Դϴ�. . ." << std::endl;
		Sleep(2000);
		if (finding >= 49) {
			std::cout << "���͸� ã�ҽ��ϴ�." << std::endl;
			std::cout << "�����Ͻðڽ��ϱ�?" << std::endl;
			std::cout << "[1. �����Ѵ�], [2. ����ģ��]" << std::endl;
			PlayerChoosing();
			switch (PlayerChoice) {
			case 1:
				std::cout << "���Ϳ� �����մϴ�" << std::endl;
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
				std::cout << "���ͷκ��� ������ �ٽ� �ʵ�� ���ϴ�" << std::endl;
				Sleep(2000);
				LastFlag = 0;
				gameFlag = FIELD;
				PlayerChoice = 0;
				system("cls");
				break;
			}
		}
		else {
			std::cout << "���͸� ã�� ���Ͽ����ϴ�." << std::endl;
			Sleep(2000);
			LastFlag = 0;
			gameFlag = FIELD;
			PlayerChoice = 0;
			system("cls");
			break;
		}
	}
}