#include<stdio.h>

static double d = 0.375;

int main(void)
{
	int a = 0, i;

	printf(".");
	for(i=0 ; i<32 ; i++){
		d = d*2;
		if(d >= 1.0){
			printf("1");
			a = (a<<1)|0x1;
			d -= 1;
		}
		else{
			printf("0");
			a = (a<<1)|0x0;
		}

		if(i == 31 && d != 0){
			printf("ERROR!\n");
			break;
		}	
	}

	return 0 ;
}
