#include "globalFunction.h"

using namespace std;

int flag = MAIN;
int LastFlag = 0;
int PlayerChoice;
int main()
{
	Player P;
	while (flag != END) {
		//���� �޼���
		if (!startMSG()) {
			continue;
		}
		string settingMSG = "�������Դϴ�.";
		for (int i = 0; i < 3; ++i) {
			TextRPG_Text();
			cout << settingMSG;
			settingMSG = settingMSG + " .";
			Sleep(1000);
			system("cls");
		}
		//��������
		flag = TOWN;
		switch (PlayerChoice) {
		case ����:
			P.setClass("����");
			break;
		case ����:
			P.setClass("����");
			break;
		case ������:
			P.setClass("������");
			break;
		case �ü�:
			P.setClass("�ü�");
		}
		cout << "���� �Ϸ�." << endl;
		Sleep(2000);
		system("cls");
		//���� ��ȯ
		while (flag == TOWN) {
			TextRPG_Text();
			cout << "-------------------------------------" << endl;
			cout << "������ �����߽��ϴ�. ������ �Ͻðڽ��ϱ�?" << endl;
			cout << "[1. �ʵ�� ������]" << endl;
			cout << "[2. ���� Ȯ��]" << endl;
			cout << "[3. �κ��丮 Ȯ��]" << endl;
			cout << "[4. ���� ����]" << endl;
			cout << "[5.��������]" << endl;
			cout << "-------------------------------------" << endl;
			if (!PlayerChoosing()) {
				continue;
			}
			else {
				switch (PlayerChoice) {
				case 1:
					flag = FIELD;
					//���� ����� ���� �ʵ�� ������ ��
					while (flag == FIELD) {
						system("cls");
						TextRPG_Text();
						cout << "-------------------------------------" << endl;
						cout << "�ʵ忡 �����߽��ϴ�. ������ �Ͻðڽ��ϱ�?" << endl;
						cout << "[1. ���͸� ã��]" << endl;
						cout << "[2. �κ��丮 Ȯ��]" << endl;
						cout << "[3. ���� Ȯ��]" << endl;
						cout << "[4. ������ ����]" << endl;
						cout << "-------------------------------------" << endl;
						if (!PlayerChoosing()) {
							continue;
						}
						switch (PlayerChoice) {
						case 1:
							flag = FIND_MONSTER;
							FindMonster(flag, LastFlag, &P);
							PlayerChoice = 0;
							system("cls");
							break;
						case 2:
							flag = CHECK_INVENTORY;
							LastFlag = FIELD;
							system("cls");
							//�κ��丮 ��ü�� Ȯ���ϱ� ���� while��
							showInventory(flag, LastFlag, &P);
							//���ö� PlayerChoice�� 0�� �Ǽ� ����
							break;
						case 3:
							flag = STAT_INFO;
							LastFlag = FIELD;
							system("cls");
							//����Ȯ���� �� ��� while��
							showStatInfo(flag, LastFlag, &P);
							//���� �� PlayerChoice�� 0�̵Ǿ ����
							break;
						case 4:
							flag = TOWN;
							PlayerChoice = 0;
							system("cls");
							break;
						}
					}
					break;
				case 2:
					flag = STAT_INFO;
					LastFlag = TOWN;
					system("cls");
					//����Ȯ���� �� ��� while��
					showStatInfo(flag, LastFlag, &P);
					//���� �� PlayerChoice�� 0�̵Ǿ ����
					break;
				case 3:
					flag = CHECK_INVENTORY;
					LastFlag = TOWN;
					system("cls");
					showInventory(flag, LastFlag, &P);
					break;
				case 4:
					system("cls");
					continue;
				case 5:
					flag = END;
					continue;
				case 0:
					continue;
				}
			}
		}
		

		
	}
}







