#include <stdio.h>
#include<stdlib.h>

int main(void)
{
	char *ptr;

	if( (ptr = (char *) malloc(0)) == NULL )
		puts("Got a null pointer"); 
	else{ 
		printf("%p\n", ptr);
		puts("Got a valid pointer"); 
	}

	return 0;
}
