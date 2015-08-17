#include<stdio.h>
#include<stdint.h>
#include<math.h>

#define u 0 /* don't care */
//#define H 2^26

uint32_t clz(uint32_t x) {
	uint32_t H = 7*pow(255,3);
	static uint8_t table[64] = {
		32, 31,  u, 16,  u, 30,  3,  u, 15,  u,  u,  u, 29, 10,  2,  u,
		u,  u, 12, 14, 21,  u, 19,  u,  u, 28,  u, 25,  u,  9,  1,  u,
		17,  u,  4,  u,  u,  u, 11,  u, 13, 22, 20,  u, 26,  u,  u, 18,
		5,  u,  u, 23,  u, 27,  u,  6,  u, 24,  7,  u,  8,  u,  0,  u,
	};
	x = x | (x >> 1);
	x = x | (x >> 2);
	x = x | (x >> 4);
	x = x | (x >> 8);
	x = x | (x >> 16);
	x *= H; // Multiplier is H
	return table[x >> 26];
}  

int main(void)
{
	printf("number is %d\n", clz(0x7));

	return 0;
}
