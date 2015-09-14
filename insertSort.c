#include<stdio.h>

int main(void)
{
	int i, j, temp;
	int data[5] = {3,5,6,9,1};

	for(i = 1 ; i<5 ;i++){
		temp = data[i];
		for(j=i ; j>0 && temp < data[j-1] ; j--){
			data[j] = data[j-1];
		}
		data[j] = temp;
	}

	for(i = 0 ; i<5 ;i++)
		printf("value is %d\n", data[i]);
	return 0;
}
