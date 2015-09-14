#include<stdio.h>
#define LENGTH 10


void swap(int *data, int root, int max){
	int temp = data[max];
	data[max] = data[root];
	data[root] = temp;

	return;
}

void heapify(int *data, int root, int length){

	int rightchild = root*2+2;
	int leftchild = root*2+1;
	int maxnode = 0;

	if(leftchild<length && data[leftchild] > data[root])
		maxnode = leftchild;
	else
		maxnode = root;
	if(rightchild<length && data[rightchild] > data[maxnode])
		maxnode = rightchild;
	
	if(maxnode != root){
		swap(data, root, maxnode);
		heapify(data, maxnode, length);
	}
		
}

void heapSort(int *data){
 
	int i;

	//將數列轉換成Max Heap
	for(i=(LENGTH/2 -1) ; i>=0 ; i--)
		heapify(data, i, LENGTH);
	
	for(i=0 ; i<LENGTH ; i++)
	 	printf("value is %d\n", data[i]);

	//排序
	for(i = LENGTH-1 ; i>0 ; i--){
		swap(data, 0, i);
		heapify(data, 0, i);
	}
	printf("\nAfter Sorted : \n");
	for(i=0 ; i<LENGTH ; i++)
	 	printf("value is %d\n", data[i]);

	return;
}



int main(void)
{
	int data[10] = {92,38,59,57,14,52,19,69,23,84};

	heapSort(data);

	return 0;
}
