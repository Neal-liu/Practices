#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool palindrome(char *str){
	int length = strlen(str);
	char *str2 = str + length -1;
	while(str < str2){
		if(*str != *str2)
			return false;
		str++;
		str2--;
	}
	return true;
}

int main(void){

	bool isPalindrome = palindrome("testtset");
	if(isPalindrome)
		printf("This string is palindrome!!\n");
	else
		printf("This string is nothing !\n");

	return 0;
}
