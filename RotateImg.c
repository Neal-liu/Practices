#include<stdio.h>
#define X 3
#define Y 4

void rotateImg(int buf[X][Y], int buf2[Y][X]){
	int x, y;	

	for(x = 0 ; x < X ; x++){
		for(y = 0; y < Y ; y++){
			buf2[y][X-x-1] = buf[x][y];
		}
	}

		printf("\n");
	for(y = 0 ; y < Y ; y++){
		for(x = 0; x < X ; x++){
			printf("%d ", buf2[y][x]);
		}
		printf("\n");
	}
}

int main(void)
{
	int buffer[X][Y] = {0};
	int buffer2[Y][X] = {0};
	int x, y, count = 0;

	for(x = 0 ; x < X ; x++)
		for(y = 0; y < Y ; y++)
			buffer[x][y] = count++;

	for(x = 0 ; x < X ; x++){
		for(y = 0; y < Y ; y++){
			printf("%d ", buffer[x][y]);
		}
		printf("\n");
	}
	printf("\n");
	rotateImg(buffer, buffer2);

	return 0 ;
}
