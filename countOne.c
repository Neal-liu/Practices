#include<stdio.h>
#include<stdint.h>

int countOne (int32_t n){
	int count = 0;
	if(n == 0)
		return 0;
	while(n){
		if(n & 0x1 == 1)
			count++;
		n >>= 1;
	}
	printf("number of 1 is %d\n", count);
	return count;
}

int countOne2(int32_t x){

	x = (x & (0x55555555)) + ((x >> 1) & (0x55555555));
	x = (x & (0x33333333)) + ((x >> 2) & (0x33333333));
	x = (x & (0x0f0f0f0f)) + ((x >> 4) & (0x0f0f0f0f));
	x = (x & (0x00ff00ff)) + ((x >> 8) & (0x00ff00ff));
	x = (x & (0x0000ffff)) + ((x >> 16) & (0x0000ffff));

	printf("number of 1 is %d\n", x);
}

int main(void)
{
	countOne(0X1F);
	countOne2(0X1F);
	return 0;
}
