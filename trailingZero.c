#include<stdio.h>

int main(void)
{
	int N = 25;
	int n = 0;

	while(N/5 > 0){
		n += N/5;
		N /= 5;
	}
	printf("N! trailing zero is %d\n", n);

	return 0;
}
