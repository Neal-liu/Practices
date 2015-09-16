#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *reverse_string(char *);
char *reverse2(char *);

int main(void)
{
	char str[] = "Test";

	printf("%s\n",str);
	reverse_string(str);
	printf("%s\n",str);
	reverse2(str);
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

void swap(char *a, char *b){
	*a = *a^*b;
	*b = *a^*b;
	*a = *a^*b;
}

char *reverse2(char *str){
	int length = strlen(str);
//	printf("length is %d\n", length);
	if(str == NULL)
		return;
	
	char *new = str;
	char *end = str + length -1;
	while(str<end){
	//	swap(*str, *end);
		*str = *str ^ *end;
		*end = *str ^ *end;
		*str = *str ^ *end;
		str++;
		end--;
	}
//	printf("reverse string is %s\n", new);
	return new;
}

