#include <stdio.h>
#define A 26
#define B 18

int findGCD(int, int);
int findGCD2(int, int);
int findGCD3(int, int);

int main(void)
{
	int result1 = findGCD(A,B);
	int result2 = findGCD2(A,B);
	int result3 = findGCD3(A,B);
	printf("GCD is %d\n", result1);
	printf("GCD is %d\n", result2);
	printf("GCD is %d\n", result3);

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

int findGCD2(int a, int b)
{
	while(1){
		a %= b;
		if(a == 0)
			return b;
		if(a == 1)
			return 1;
		b %= a;
		if(b == 0)
			return a;
		if(b == 1)
			return 1;
	}
}

int findGCD3(int a, int b)
{
	while (1) {
		if (a > (b * 4)) {
			a %= b;
			if (a == 0) return b;
			if (a == 1) return 1;

		} 
		else if (a >= b) {
			a -= b;
			if (a == 0) return b;
			if (a == 1) return 1;
		}
		if (b > (a * 4)) {
			b %= a;
			if (b == 0) return a;
			if (b == 1) return 1;

		}
		else if (b >= a) {
			b -= a;
			if (b == 0) return a;
			if (b == 1) return 1;
		}
	}

}

