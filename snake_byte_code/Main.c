#include<stdio.h>
#include"snake.h"

void main() {
	int ekey = 0;
	int i;

	printf("Enter the number of item: ");
	scanf("%d", &N);
	
	init();						// ������ �ʱ�ȭ �Լ�
	
	while (1) {

		if (_kbhit()) {			// Ű���� �Է��� ������ 1, ������ 0�� ����
			ekey = _getch();	// �Է¹��� Ű ���� ����
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
		update();				// ���� ������Ʈ
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
		Sleep(50);// ȭ�鿡 ���

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

