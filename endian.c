/* big endian to little endian and vice versa. */

#include<stdio.h>
#include<stdint.h>

int main(void)
{
	int32_t a = 0x00010011;
	int32_t b = 0;

	b = ((a&0xFF000000)>>24) | ((a&0xFF0000)>>8) | ((a&0xFF00)<<8) | ((a&0xFF)<<24);
	printf("a = %d\n", a);
	printf("b = %d\n", b);

	return 0;
}
