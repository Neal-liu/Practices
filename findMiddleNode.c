#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
	int value;
	struct Node *next;
};

struct Node *head = NULL;

void findMiddleNode(struct Node *head){
	struct Node *quick = head;
	struct Node *slow = head;

	if(head != NULL){
		while(slow->next != NULL && quick->next->next != NULL){
			slow = slow->next;
			quick = quick->next->next;
		}
		if(quick->next != NULL)
			printf("middle number is %d, %d\n", slow->value, slow->next->value);
		else
			printf("middle number is %d\n", slow->value);
	}
	else
		printf("there is no list!!\n");
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
	push_value(3);
	push_value(6);
	push_value(2);
	push_value(1);
	push_value(1);
	push_value(8);

	printf("Before Sorting : 3, 2, 7, 8, 3, 6, 2, 1, 1, 8\n");
	findMiddleNode(head);

	return 0;
}
