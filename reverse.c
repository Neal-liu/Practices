#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *reverse_string(char *);

int main(void)
{
	char str[] = "Test";

	printf("%s\n",str);
	reverse_string(str);
	printf("%s\n",str);

	return 0;
}

char *reverse_string(char *str)
{
	char temp, temp2;
	char *s = str;
	int len = strlen(str)-1;
	int i;
	int k = len;

	for(i = 0 ; i<len ; i++){
		temp = str[k];
		str[k] = str[i];
		str[i] = temp;
		k--;

		if( k == (len/2))
			return str;
		
	}

}

