#include <stdio.h>

int main(int argc, void *argv[]){

	int i = 0;
	int *j;
	short *s = (short *) &i;
	i = 0;
	*s = 1;

	printf("%d\n", i);
	printf("%p\n", s);
	printf("%p\n", &i);
	printf("%p\n", j);
	printf("The END!\n");
	return 0;
}
