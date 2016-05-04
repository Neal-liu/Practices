#include<stdio.h>
#include<stdlib.h>

int lower_bit(int n){

	return n&-n;
}


int getSum(int *BITree, int index){

	int sum = 0;
	index += 1;

	while(index > 0){
		sum += BITree[index];
		index -= lower_bit(index);
	}
	return sum;
}

void updateBIT(int *BITree, int length, int index, int value){

	index += 1;
	while(index<=length){
		BITree[index] += value;
		index += lower_bit(index);
	}
}
/*
int query(int a, int b){
	
	if(a > b)
		swap(a, b);

	return sum(b) - sum(a-1);
}
*/
int *constructBITree(int arr[], int n){
	int *BITree = (int *)malloc(n * sizeof(int));
	int i;

	for(i=1 ; i<=n ; i++)
		BITree[i] = 0;

	for(i=0 ; i<n ; i++)
		updateBIT(BITree, n, i, arr[i]);
	
	return BITree;
}

int main(void)
{
	int array[] = {10, 25, 22, 7, 34, 2, 9, 12, 16, 16};
	int length = sizeof(array)/sizeof(array[0]);
	int i;

	for(i=0 ; i<length ; i++)
		printf("%d, ", array[i]);
	printf("\n");
	int *arr2 = constructBITree(array, length);

	for(i=0 ; i<=length ; i++)
		printf("%d, ", arr2[i]);
	printf("\n");

	printf("Sum of elements in arr[0..5] is %d\n", getSum(arr2, 5));

	return 0;
}
