#include "globalFunction.h"

using namespace std;

int flag = MAIN;
int LastFlag = 0;
int PlayerChoice;
int main()
{
	Player P;
	while (flag != END) {
		//시작 메세지
		if (!startMSG()) {
			continue;
		}
		string settingMSG = "세팅중입니다.";
		for (int i = 0; i < 3; ++i) {
			TextRPG_Text();
			cout << settingMSG;
			settingMSG = settingMSG + " .";
			Sleep(1000);
			system("cls");
		}
		//전직설정
		flag = TOWN;
		switch (PlayerChoice) {
		case 전사:
			P.setClass("전사");
			break;
		case 도적:
			P.setClass("도적");
			break;
		case 마법사:
			P.setClass("마법사");
			break;
		case 궁수:
			P.setClass("궁수");
		}
		cout << "세팅 완료." << endl;
		Sleep(2000);
		system("cls");
		//마을 소환
		while (flag == TOWN) {
			TextRPG_Text();
			cout << "-------------------------------------" << endl;
			cout << "마을에 도착했습니다. 무엇을 하시겠습니까?" << endl;
			cout << "[1. 필드로 나가기]" << endl;
			cout << "[2. 스텟 확인]" << endl;
			cout << "[3. 인벤토리 확인]" << endl;
			cout << "[4. 상점 가기]" << endl;
			cout << "[5.게임종료]" << endl;
			cout << "-------------------------------------" << endl;
			if (!PlayerChoosing()) {
				continue;
			}
			else {
				switch (PlayerChoice) {
				case 1:
					flag = FIELD;
					//몬스터 사냥을 위해 필드로 나갔을 때
					while (flag == FIELD) {
						system("cls");
						TextRPG_Text();
						cout << "-------------------------------------" << endl;
						cout << "필드에 도착했습니다. 무엇을 하시겠습니까?" << endl;
						cout << "[1. 몬스터를 찾기]" << endl;
						cout << "[2. 인벤토리 확인]" << endl;
						cout << "[3. 스텟 확인]" << endl;
						cout << "[4. 마을로 가기]" << endl;
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
							//인벤토리 전체를 확인하기 위한 while문
							showInventory(flag, LastFlag, &P);
							//나올땐 PlayerChoice가 0이 되서 나옴
							break;
						case 3:
							flag = STAT_INFO;
							LastFlag = FIELD;
							system("cls");
							//스텟확인을 할 경우 while문
							showStatInfo(flag, LastFlag, &P);
							//나올 땐 PlayerChoice가 0이되어서 나옴
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
					//스텟확인을 할 경우 while문
					showStatInfo(flag, LastFlag, &P);
					//나올 땐 PlayerChoice가 0이되어서 나옴
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







