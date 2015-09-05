/* implements add with logical operator and iteration. */

#include<stdio.h>

void add(int a, int b){

	int sum, carry;
	sum = (a ^ b);
	carry = (a & b) << 1;
	if(carry != 0)
		add(sum, carry);
	else if( sum < 0 ){
		printf("overflow!!\n");
	}
	else
		printf("sum is %d\n", sum);
}


int main(void)
{
	add(2147483647,1);

	return 0;
}
