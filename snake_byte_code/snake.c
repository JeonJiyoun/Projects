#include"snake.h"

void init() {
	sInit();
	sn.die = 1;
	taillength = 5;

	obj = (object *)malloc(N*sizeof(object));
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		obj[i].heart.x = rand() % (ROW - 2) + 1;
		obj[i].heart.y = rand() % (COL - 2) + 1;
		if (obj[i].heart.x == sn.head.x&&obj[i].heart.y == sn.head.y) {
			init();
		}
		for (int j = 0; j < taillength; j++) {
			if (obj[i].heart.x == sn.tail[i].x&&obj[i].heart.y == sn.tail[i].y) {
				init();
			}
		}
		obj[i].eat = 1;

	}
	sn.head.x = rand() % (ROW - 2) + 1;
	sn.head.y = rand() % (COL - 2) + 1;
	sn.dir = rand() % 4;
	switch (sn.dir) {
	case LEFT:
		for (int i = 0; i < taillength; i++) {
			sn.tail[i].x = sn.head.x + (i + 1);
			sn.tail[i].y = sn.head.y;
		}
		break;
	case RIGHT:
		for (int i = 0; i < taillength; i++) {
			sn.tail[i].x = sn.head.x - (i + 1);
			sn.tail[i].y = sn.head.y;
		}
		break;
	case UP:
		for (int i = 0; i <taillength; i++) {
			sn.tail[i].x = sn.head.x;
			sn.tail[i].y = sn.head.y + (i + 1);
		}
		break;
	case DOWN:
		for (int i = 0; i < taillength; i++) {
			sn.tail[i].x = sn.head.x;
			sn.tail[i].y = sn.head.y - (i + 1);
		}
		break;


	}
	if (sn.tail[taillength - 1].x>ROW - 2 || sn.tail[taillength - 1].x <= 0 || sn.tail[taillength - 1].y>COL - 2 || sn.tail[taillength - 1].y <= 0) {
		init();
	}

}

void update() {
	//move
	int temp[2][500];
	int i = 0;
	switch (sn.dir)
	{
	case LEFT:
		if (sn.head.x <= 1) {
			break;
		}
		for (; i < taillength-1; i++) {
			temp[0][i] = sn.tail[i].x;
			temp[1][i] = sn.tail[i].y;
		}
		for (i = 1; i <taillength; i++) {
			sn.tail[i].x = temp[0][i - 1];
			sn.tail[i].y = temp[1][i - 1];
		}
		sn.tail[0].x = sn.head.x;
		sn.tail[0].y = sn.head.y;
		sn.head.x -= 1;
		break;
	case RIGHT:
		if (sn.head.x >= ROW - 2) {
			break;
		}
		for (; i < taillength-1; i++) {
			temp[0][i] = sn.tail[i].x;
			temp[1][i] = sn.tail[i].y;
		}
		for (i = 1; i < taillength; i++) {
			sn.tail[i].x = temp[0][i - 1];
			sn.tail[i].y = temp[1][i - 1];
		}
		sn.tail[0].x = sn.head.x;
		sn.tail[0].y = sn.head.y;
		sn.head.x += 1;
		break;
	case UP:
		if (sn.head.y <= 1) {
			break;
		}
		for (; i < taillength-1; i++) {
			temp[0][i] = sn.tail[i].x;
			temp[1][i] = sn.tail[i].y;
		}
		for (i = 1; i < taillength; i++) {
			sn.tail[i].x = temp[0][i - 1];
			sn.tail[i].y = temp[1][i - 1];
		}
		sn.tail[0].x = sn.head.x;
		sn.tail[0].y = sn.head.y;
		sn.head.y -= 1;
		break;
	case DOWN:
		if (sn.head.y >= COL - 2) {
			break;
		}
		for (; i < taillength-1; i++) {
			temp[0][i] = sn.tail[i].x;
			temp[1][i] = sn.tail[i].y;
		}
		for (i = 1; i < taillength; i++) {
			sn.tail[i].x = temp[0][i - 1];
			sn.tail[i].y = temp[1][i - 1];
		}
		sn.tail[0].x = sn.head.x;
		sn.tail[0].y = sn.head.y;
		sn.head.y += 1;
		break;
	}
	for (i = 0; i < taillength; i++) {
		if (sn.head.x == sn.tail[i].x&&sn.head.y == sn.tail[i].y) {
			sn.die = 0;
		}
	}
		for (i = 0; i < N; i++) {
			if (sn.head.x == obj[i].heart.x&&sn.head.y == obj[i].heart.y) {
				obj[i].eat = 0;
				taillength++;
			}
		}//collision

	}



void draw() {
	int x = 0, y = 0;

	sClear();

	for (; x < 40; x++) {
		sPrint(x * 2, y, "бс");
		sPrint(x * 2, 19- y, "бс");
	}
	for (x = 0,y=1; y < 19; y++) {
		sPrint(x * 2, y, "бс");
		sPrint((39 - x) * 2, y, "бс");
	}
	
	for (int i = 0; i < N; i++) {
		sPrint((obj[i].heart.x) * 2, obj[i].heart.y, "в╛");
	}
	for (int i = 0; i < N; i++) {
		if (obj[i].eat == 0) {
			sPrint((obj[i].heart.x) * 2, obj[i].heart.y, " ");
		}
	}
	sPrint((sn.head.x) * 2, (sn.head.y), "б▌");
	
	for (int i = 0; i < taillength; i++) {
		sPrint((sn.tail[i].x) * 2, sn.tail[i].y, "в┬");
		
	}
	
	sFlipping();
}

void release() {
	sRelease();
}

