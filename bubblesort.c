#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
	int value;
	struct Node *next;
};

struct Node *head = NULL;
struct Node *swap(struct Node*, struct Node *);

void BubbleSort(struct Node *head)
{
	struct Node *prev = NULL;
	struct Node *current = NULL;

	if(!head) return ;
	bool change = true;

	while(change){
		prev = NULL;
		current = head;
		change = false;
		while(current->next != NULL){
			if(current->value > current->next->value){
				current = swap(current , current->next);
				change = true;
				if(prev != NULL)
					prev->next = current;
				else
					head = current;
			}
			prev = current;
			current = current->next;
		}
	}

	printf("After sorting : \n");
	while(head != NULL){
		printf("value is %d\n", head->value);
		head = head->next;
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
	head->value = 3;

	push_value(2);
	push_value(7);
	push_value(8);
	push_value(6);
	push_value(1);

	printf("Before Sorting : 3, 2, 7, 8, 6, 1 \n");
	BubbleSort(head);

	return 0;
}
