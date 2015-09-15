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

int atoi(char *str){
	bool negative = false;
	int value = 0;

	if(str == NULL)
		return value;

	if(*str == '-'){
		negative = true;
		str++;
	}

	while(*str != '\0'){
		if(*str >= '0' && *str <= '9'){
			value = value*10 + (int)*str - 48;	// 48 = '0'
		}
		str++;
	}
	if(negative)
		value = -value;

	return value;
}

int main(void)
{
	char *string = itoa(14357);
	printf("string is %s\n", string);
	
	int num = atoi("-124");
	printf("test is %d\n", num);

	return 0;
}





