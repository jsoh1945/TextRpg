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
			cout << "마을에 도착했습니다. 무엇을 하시겠습니까?" << endl;
			cout << "[1. 필드로 나가기], [2. 스텟 확인], [3. 상점 가기], [4. 게임종료]" << endl;
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
						cout << "필드에 도착했습니다. 무엇을 하시겠습니까?" << endl;
						cout << "[1. 몬스터를 찾기], [2. 인벤토리 확인], [3. 스텟 확인], [4. 마을로 가기]" << endl;
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
							//인벤토리 전체를 확인하기 위한 while문
							while (flag == CHECK_INVENTORY) {
								for (int i = 0; i < MAX_INVEN_SLOT; ++i) {
									if (i == 0) {
										cout << "슬롯 " << i+1 << ": " << P.getInvenItemName(i) << " - " << P.getInvenNumberOfItem(i) << "원" << endl;
										continue;
									}
									cout << "슬롯 " << i+1 <<": " << P.getInvenItemName(i) << " - " << P.getInvenNumberOfItem(i) << "개" << endl;
								}
								cout << "[1. 뒤로가기]" << endl;
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
									cout << "다시 선택해 주세요" << endl;
									Sleep(2000);
									system("cls");
									continue;
								}
								break;
							}
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







