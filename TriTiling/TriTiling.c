/* Tri Tiling 
Content ：
	給你一個3 * n的地面，用1 * 2的地板磚鋪滿，問有幾種方法。
Input ： 
	每行有一個整數n，代表為3 * n的地面，0 ≤ n ≤ 30，n=-1時代表輸入結束
Output ： 
	請對每一個輸入，輸出可能的排法數
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int g(int);

int f(int n){
	if(n == 0)
		return 1;
	else if(n == 1)
		return 0;
	else
		return f(n-2)+2*g(n-1);
}
int g(int n){
	if(n == 0)
		return 0;
	else if(n == 1)	
		return 1;
	else
		return f(n-1)+g(n-2);
}

int main(int argc, char *argv[]){

	char *line = NULL;
//	char *tok = NULL;
	int result = 0;
	int input = 0;
	int tok = -1;;

	scanf("%d", &tok);
	while(tok != -1){
		result = f(tok);
		printf("%d\n", result);
		scanf("%d", &tok);
	}

	return 0;
}
