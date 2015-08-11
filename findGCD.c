#include <stdio.h>
#define A 26
#define B 18

int findGCD(int, int);

int main(void)
{
	int result = findGCD(A,B);
	printf("GCD is %d\n", result);
	return 0;
}

int findGCD(int a, int b)
{
	while(1){
		if(a > b)
			a -= b;
		else if(a < b)
			b -= a;
		else
			return a;
	}
}
