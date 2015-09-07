#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int count = 0 ;
	int num = atoi(argv[1]);

	while(num/5 > 0){
		count += num/5;
		num /= 5;
	}

	printf("N! ctz is %d\n", count);

	return 0;
}
