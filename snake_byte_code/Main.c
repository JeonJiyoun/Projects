#include<stdio.h>
#include"snake.h"

void main() {
	int ekey = 0;
	int i;

	printf("Enter the number of item: ");
	scanf("%d", &N);
	
	init();						// 변수값 초기화 함수
	
	while (1) {

		if (_kbhit()) {			// 키보드 입력이 있으면 1, 없으면 0을 리턴
			ekey = _getch();	// 입력받은 키 값을 받음
			_flushall();
			switch (ekey) {
			case L:
				sn.dir = 0;
				break;
			case R:
				sn.dir = 1;
				break;
			case U:
				sn.dir = 2;
				break;
			case D:
				sn.dir = 3;
				break;
			default:
				break;

			}
		}
		update();				// 변수 업데이트
		if (sn.die == 0) {

			break;
		}
		
		
		for (i = 0 ; i < N; i++) {
			if (obj[i].eat != 0) {
				break;
			}
		
		}
		if (i == N) {
			break;
		}
		draw();	
		Sleep(50);// 화면에 출력

	}
		
		release();
		system("cls");
		if (sn.die == 0) {
			printf("\n\n\n\n\n\n\n\n\n\n\n\n                                             Lose!\n");
			Sleep(1000);
		}
		if (i==N) {
			printf("\n\n\n\n\n\n\n\n\n\n\n\n                                             Win!\n");
			Sleep(1000);
		}
	}

