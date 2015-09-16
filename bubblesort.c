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

/* delete duplicates from linked-list */
void Unique(struct Node *head){

	struct Node *pass = NULL;
	struct Node *current = NULL;
	struct Node *iteration = NULL;

	pass = head;
	while(pass != NULL){
		
		current = pass;
		iteration = pass;
		while(current->next != NULL){
			if(pass->value == iteration->next->value){
				if(current->next->next != NULL){
					struct Node *dup = current->next;
					current->next = current->next->next;
					free(dup);
				}
				else
					current->next = NULL;
			}
				current = current->next;
				iteration = iteration->next;
				if(current == NULL)
					break;
		}
		pass = pass->next;
	}

	printf("After unique : \n");
	while(head != NULL){
		printf("value is %d\n", head->value);
		head = head->next;
	}

}

void findCircular(struct Node *head){

	struct Node *prev = NULL;
	struct Node *current = head;
	while(current != NULL){
		struct Node *next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	bool hascycle = (prev == head) && (head != NULL) && (head->next != NULL);

	/* reconstruct the list */
	current = prev;
	prev = NULL;
	while(current != NULL){
		struct Node *next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return hascycle;
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

struct Node *create_node(int data){
	struct Node *n = malloc(sizeof(struct Node));
	n->value = data;
	n->next = NULL;

	return n;
}

void insert(struct Node *n1, struct Node *n2){

	n2->next = n1->next;
	n1->next = n2;
}

/* Delete nodes from singly linked-list when pointer to the previous node is not available. */
void deleteNode(struct Node *ptr){
	struct Node *temp = ptr->next;
	ptr->value = ptr->next->value;
	ptr->next = temp->next;
	free(temp);
}


int main(void)
{
	head = malloc(sizeof(struct Node));
	head->value = 3;

//	push_value(1);
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
//	printf("Before Sorting : 3, 2, 7, 8, 8, 6, 1, 1 \n");
	BubbleSort(head);
//	Unique(head);
	printf("\n");
	struct Node *a = create_node(10);	
	while(head != NULL){
		if(head->value == 7)
			insert(head, a);

		printf("value is %d\n", head->value);
		head = head->next;
	}

	return 0;
}
