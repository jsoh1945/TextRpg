#include "globalFunction.h"

void error_msg(std::string err) {
	std::cout << "[����]: " << err << std::endl;
}

void showStatInfoG(Player* P) {
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
			std::cout << "[1. �ʵ�� ����], [2. ���� ����]" << std::endl;
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

void showInventroy(int& gameFlag, int& LastFlag, Player* P) {
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

		}

		break;
	}
}