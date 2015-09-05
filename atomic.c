#include<stdio.h>

int main(void)
{

	while(TestAndSet(&lock) == 1);
	// critical section
	lock = 0;

	return 0;
}
