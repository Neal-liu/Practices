#include<stdio.h>
#include<stdbool.h>


int main(void)
{
	int n = 0;
	bool powerof2;
	
	powerof2 = (n&(n-1)) ? false : true;
	if(powerof2)
		printf("this number is power of 2\n");
	else
		printf("this number is not power of 2\n");

	
	return 0;
}
