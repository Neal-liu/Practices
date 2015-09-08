#include <stdio.h>
#include<math.h>

int isMultipleOf3(int n){

	int odd_count = 0;
	int even_count = 0;

	if(n == 0)
		return 1;
	else if(n == 1)
		return 0;

	while(n){
		if(n & 0x1)
			odd_count ++;
		n >>= 1;

		if(n & 0x1)
			even_count ++;
		n >>= 1;
	}
	
	return isMultipleOf3(abs(odd_count - even_count));
}


int main(void)
{
	if(isMultipleOf3(81))
		printf("the number is multiple of 3!\n");
	else
		printf("the number is not multiple of 3 ! \n");

	return 0;
}

