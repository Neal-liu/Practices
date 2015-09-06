#include<stdio.h>

int stair(int n){
	if(n == 0)
		return 1;
	else if(n == 1)
		return 1;
	else if(n == 2)
		return 2;
	else
		return (stair(n-1)+stair(n-2)+stair(n-3));

}


int main(void)
{
	int number = stair(3);
	int number1 = stair(4);
	int number2 = stair(5);
	int number3 = stair(6);
	int number4 = stair(7);

	printf("number 3 is %d\n", number);
	printf("number 4 is %d\n", number1);
	printf("number 5 is %d\n", number2);
	printf("number 6 is %d\n", number3);
	printf("number 7 is %d\n", number4);
	return 0;
}
