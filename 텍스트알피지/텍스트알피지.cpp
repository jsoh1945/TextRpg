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
			cout << "������ �����߽��ϴ�. ������ �Ͻðڽ��ϱ�?" << endl;
			cout << "[1. �ʵ�� ������], [2. ���� Ȯ��], [3. ���� ����], [4. ��������]" << endl;
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
						cout << "�ʵ忡 �����߽��ϴ�. ������ �Ͻðڽ��ϱ�?" << endl;
						cout << "[1. ���͸� ã��], [2. �κ��丮 Ȯ��], [3. ���� Ȯ��], [4. ������ ����]" << endl;
						if (!PlayerChoosing()) {
							continue;
						}
						switch (PlayerChoice) {
						case 1:
							flag = FIND_MONSTER;
							while (flag == FIND_MONSTER) {
								
							}
							PlayerChoice = 0;
							system("cls");
							break;
						case 2:
							flag = CHECK_INVENTORY;
							system("cls");
							//�κ��丮 ��ü�� Ȯ���ϱ� ���� while��
							while (flag == CHECK_INVENTORY) {
								for (int i = 0; i < MAX_INVEN_SLOT; ++i) {
									if (i == 0) {
										cout << "���� " << i+1 << ": " << P.getInvenItemName(i) << " - " << P.getInvenNumberOfItem(i) << "��" << endl;
										continue;
									}
									cout << "���� " << i+1 <<": " << P.getInvenItemName(i) << " - " << P.getInvenNumberOfItem(i) << "��" << endl;
								}
								cout << "[1. �ڷΰ���]" << endl;
								if (!PlayerChoosing()) {
									continue;
								}
								switch (PlayerChoice) {
								case 1:
									flag = FIELD;
									PlayerChoice = 0;
									system("cls");
									break;
								default:
									cout << "�ٽ� ������ �ּ���" << endl;
									Sleep(2000);
									system("cls");
									continue;
								}
								break;
							}
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
					break;
				case 4:
					flag = END;
					continue;
				case 0:
					continue;
				}
			}
		}
		

		
	}
}







