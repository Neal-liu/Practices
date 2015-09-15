/* pseudocode:  */
/* 
Function selectionSort(Type data[1..n])
	Index i, j, max
   	For i from 1 to n do
   		max = i
  		For j from i + 1 to n do
  			If data[j] > data[max] then
  				max = j

  		Exchange data[i] and data[max]
End
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
	int value;
	struct Node *next;
};

struct Node *head = NULL;
struct Node *swap(struct Node*, struct Node *);


// this code still have errors.
void selectionSort(struct Node *head){
	struct Node *prev = NULL;
	struct Node *current = NULL;
	struct Node *check = NULL;
	struct Node *max = NULL;
	struct Node *newhead = NULL;
	int maxmum = -1;
	bool change = false;
	current = head;

	while(current->next != NULL){
		maxmum = current->value;
		check = current->next;
		change = false;
		while(check != NULL){
			if(check->value > maxmum){
				maxmum = check->value;
				max = check;
				change = true;
			}
			check = check->next;
		}
		if(change){
			current = swap(current, max);
			if(prev != NULL)
				prev->next = current;
			else
				newhead = current;
//			if(newhead == NULL){
//			}
		}
		prev = current;
		current = current->next;
		printf("value is %d\n",maxmum);
	}

	printf("After sorting : \n");
	while(newhead != NULL){
		printf("value is %d\n", newhead->value);
		newhead = newhead->next;
	}
}

struct Node *swap(struct Node *p, struct Node *q){
	struct Node *temp = q->next;
	q->next = p;
	p->next = temp;

	return q;
}




void push_value(int value){

	struct Node *current = head;
	while(current->next != NULL){
		current = current->next;
	}
	struct Node *newnode = malloc(sizeof(struct Node));
	newnode->value = value;
	newnode->next = NULL;
	current->next = newnode;

}


int main(void)
{
	head = malloc(sizeof(struct Node));
	head->value = 1;
	push_value(3);
	push_value(2);
	push_value(7);
	push_value(8);
	push_value(4);
	push_value(9);
/*
	push_value(2);
	push_value(7);
	push_value(8);
	push_value(3);
	push_value(6);
	push_value(2);
	push_value(1);
	push_value(1);
	push_value(8);
*/
	printf("Before Sorting : 1, 3, 2\n");
//	printf("Before Sorting : 3, 2, 7, 8, 3, 6, 2, 1, 1, 8\n");
	selectionSort(head);

	return 0;
}
