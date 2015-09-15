#include<stdio.h>
#include<stdbool.h>

char *itoa(int n){
	int length = 0;
	bool negative = false;
	char *ret = NULL;

	if(n < 0){
		n = -n;
		length++;
		negative = true;
	}

	int temp = n;
	while(temp){
		temp /= 10;
		length++;
	}

	ret = malloc(sizeof(char)*(length+1));
	ret[length] = '\0';
	
	if(negative)
		ret[0] = '-';
	
	int i = length-1;
	while(n){
		ret[i--] = n%10 + '0';
		n /= 10;
	}
	return ret;
}

int main(void)
{
	char *string = itoa(83246);

	printf("string is %s\n", string);

	return 0;
}
